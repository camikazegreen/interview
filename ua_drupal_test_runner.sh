#!/bin/bash
#
# UA Quickstart distribution test runner script
#
# Assumes that a previous step has built a distributable packaged version of the UA Quickstart
# distribution and placed this at a public location.
#
# Assumes that the current environment includes a MySQL server on which a predefined user
# has rights to drop and re-create a database, and the drush utility.
#
# Assumes that drush has the addition required to let it use CasperJS, and that there is a
# working CasperJS installation for this. See:
# https://www.drupal.org/project/casperjs
#
# Assumes a working web server, with the Drupal root directory being served as a document
# root directory, even if only at some arbitrary port on localhost.
#
# Does NOT assume any special access to the distrubution build environment, or the results of
# previous tests (ideally it is running in a freshly cleaned directory tree).

urlstem=${1-'http://jenkins.ltrr.arizona.edu/job/ua_quickstart/lastSuccessfulBuild/artifact/'}
tarball=${2-'ua_quickstart-7.x-1.x-dev.tar.gz'}
drupalroot=${3-'ua_quickstart'}
profile=${4-'ua_quickstart'}
adminemail=${5-'webmaster@ltrr.arizona.edu'}
adminuser=${6-'c13'}
# Never use the following database settings in production: they are in public repositories
dbname=${7-'uaquickstartdb'}
dbuser=${8-'uaqsdbadmin'}
dbpass=${9-'MitherTap'}
if [ $# -gt 9 ]; then
  shift 1
fi
user1pass=${9-'OGinIWereWhereGadieRins'}

# Local URL for the testing web server (the domain name will generally be something in
# /etc/hosts pointing at 127.0.0.1 rather than in the DNS)...
localurl='http://uaquickstarttest.arizona.edu:9081/'
# Relative path from the Drupal root directory to the testing root directory...
testroot='../suites'
testincludes='../includes'

# Download and expand the built & packaged distribution fron a previous step

wget -q "$urlstem$tarball"
err="$?"
if [ "$err" -ne 0 ]; then
  echo "** could not download the unchecked build: error code $err." >&2
  exit 1
else
  echo "Downloaded a copy of the last unchecked build..." >&2
fi
if [ -s "$tarball" ] ; then
  echo "Found the distribution tarball..." >&2
else
  echo "** could not find a non-empty distribution tarball $tarball." >&2
  exit 1
fi
tar xzf "$tarball"
err="$?"
if [ "$err" -ne 0 ]; then
  echo "** could not expand the distribution tarball $tarball: error code $err." >&2
  exit 1
else
  echo "Expanded the distribution tarball..." >&2
fi
if [ -d "$drupalroot" ]; then
  echo "Found the expected Drupal root directory." >&2
else
  echo "** could not find the expected Drupal root directory $drupalroot." >&2
  exit 1
fi

# Set up for default (not named site) Drupal installation

sitesdefault="$drupalroot/sites/default"
if [ -r "$sitesdefault" ]; then
  echo "Found the $sitesdefault directory in the distribution..." >&2
else
  echo "** the distribution is incomplete: $sitesdefault directory missing." >&2
  exit 1
fi
cd "$sitesdefault"
defaultsettings='default.settings.php'
if [ -r "$defaultsettings" ]; then
  echo "Found the $defaultsettings file in the distribution..." >&2
else
  echo "** the distribution is incomplete: $defaultsettings file missing." >&2
  exit 1
fi
cp "$defaultsettings" settings.php
if chmod 666 settings.php; then
  echo "Made a world-writable copy of the settings file..." >&2
else
  echo "** could not make a world-writable settings.php file." >&2
  exit 1
fi
mkdir files
if chmod 777 files; then
  echo "Made a world-writable files directory..." >&2
else
  echo "** could not make a world-writable files directory." >&2
  exit 1
fi

# Test that the specified database user can connect (without checking the particular database)

if mysql -u "$dbuser" -p"$dbpass" -e 'exit'; then
  echo "Can communicate with the database..." >&2
else
  echo "** database not available..." >&2
  exit 1
fi

# Site install: this should generate the working Drupal site for testing

cd ../..
if drush site-install "$profile" --account-mail="$adminemail" --account-name="$adminuser" --db-url=mysqli://"$dbuser":"$dbpass"@localhost/"$dbname" --site-name='UA Quickstart' -y; then
  echo "Successfully installed the site with demonstration content..." >&2
else
  echo "** the Drupal site install failed (before any actual testing)." >&2
  exit 1
fi
if drush user-password "$adminuser" --password="$user1pass"; then
  echo "Re-set the Drupal User1 ($adminuser) password..." >&2
else
  echo "** failed to set the pre-defined Drupal User1 ($adminuser) administrator password." >&2
  exit 1
fi

# Generate some CasperJS configuration files on the fly from templates and variables

cjstemplate="$testincludes/users.js.template"
cjsuserconfig="$testincludes/users.js"
cjssignin="$testincludes/signin.js"

sed -e "s/USER1NAME/$adminuser/" -e "s/USER1PASS/$user1pass/" "$cjstemplate" > "$cjsuserconfig"
err="$?"
if [ "$err" -ne 0 ]; then
  echo "** could not substitute the Drupal User1 details in $cjstemplate: error code $err." >&2
  exit 1
else
  echo "Set the Drupal User1 username and password in the CasperJS configuration..." >&2
fi
if [ -r "$cjsuserconfig" ]; then
  echo "Found the expected CasperJS Drupal user configuration file..." >&2
else
  echo "** could not find the CasperJS Drupal user configuration file $cjsuserconfig." >&2
  exit 1
fi

# Run the test suites

if drush casperjs --test-root="$testroot" --url="$localurl" --includes="$cjsuserconfig","$cjssignin"; then
  echo "Test suites completed OK." >&2
else
  echo "** some of the CasperJS tests failed." >&2
  exit 1
fi

# Set up a staging directory for database dumps

dumpdir='../dumps'
mkdir "$dumpdir"
err="$?"
if [ "$err" -ne 0 ]; then
  echo "** could not make the database dump staging directory $dumpdir: error code $err." >&2
  exit 1
else
  echo "Made the database dump staging directory..." >&2
fi
if [ -d "$dumpdir" ]; then
  echo "Found the database dump staging directory..." >&2
else
  echo "** could not find the database dump staging directory $dumpdir." >&2
  exit 1
fi
if chmod 1777 "$dumpdir"; then
  echo "Gave the dump directory the same permissions as /tmp..." >&2
else
  echo "** failed to set permissions on the database dump staging directory $dumpdir." >&2
  exit 1
fi

# Try synchronizing with a remote copy that everyone can see

drush sql-sync @uaquickstarttest @kitten
drush rsync @uaquickstarttest @kitten

exit 0
