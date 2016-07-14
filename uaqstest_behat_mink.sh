#!/bin/bash
#
# UA Quickstart distribution setup script for the Drupal Extension to Behat and Mink.
#

# Required environment variables...

# The URL for the test site on a local web server:
if [ -z "$UAQSTEST_BASEURL" ]; then
  echo "** no local web server URL for the Drupal test site (must set UAQSTEST_BASEURL)." >&2
  exit 1
fi

# Environment variables that we might write to...

# The Drupal root directory name:
if [ -z "$UAQSTEST_DRUPALROOT" ]; then
  export UAQSTEST_DRUPALROOT="${PWD}/ua_quickstart_test"
fi

# Environment variables to read but not write...

# Whether to hold off running the full set of tests immediately:
: ${UAQSTEST_RUNTESTS:=0}

# Verify that the lock file is in the current directory...

if [ -r composer.lock ]; then
  echo "Found the Composer lock file..." >&2
else
  echo "** could not find the composer.lock file defining the Drupal Extension to Behat and Mink." >&2
  exit 1
fi

# Check that Composer is available...

which composer
missing="$?"
if [ "$missing" -eq 0 ]; then
  echo "Found the Composer PHP dependency management tool as a command..." >&2
elif [ -r composer.phar ]; then
  echo "Found the Composer PHP dependency management tool as a .phar file..." >&2
else
  if [ -z "$UAQSTEST_FETCH" ]; then
    curl -V > /dev/null
    if [ "$?" -eq 0 ]; then
      UAQSTEST_FETCH='curl -sS'
    else
      wget -V > /dev/null
      if [ "$?" -eq 0 ]; then
        UAQSTEST_FETCH='wget -O -'
      else
        echo "** could not find a command to download files from URLs." >&2
        exit 1
      fi
    fi
  fi
  $UAQSTEST_FETCH https://getcomposer.org/installer | php
  err="$?"
  if [ "$err" -ne 0 ]; then
    echo "** could not install a local copy of composer: error code ${err}." >&2
    exit 1
  else
    echo "Installed a local copy of the Composer PHP dependency management tool..." >&2
  fi
fi
if [ -r composer.phar ]; then
  composer_cmd='php composer.phar'
else
  composer_cmd='composer'
fi

# Regenerate the Behat installation...

$composer_cmd install
err="$?"
if [ "$err" -ne 0 ]; then
  echo "** could not install the Drupal Extension to Behat and Mink: error code ${err}." >&2
  exit 1
else
  echo "Installed a local copy of the Drupal Extension to Behat and Mink..." >&2
fi

# Start phantomjs if it hasn't been started previously...

rundir="run/phantomjs"
pidfile="${rundir}/phantomjs.pid"
running_phantom=`ps ax | grep phantomjs | grep -v grep`
if [ -n "$running_phantom" ]; then
  echo "Found a running instance of PhantomJS..." >&2
else
  bin/phantomjs --webdriver=4444 > /dev/null &
  phantompid=`ps ax | grep phantomjs | grep -v grep | awk '{ print $1; }'`
  if [ -n "$phantompid" ]; then
    mkdir -p "$rundir"
    echo "$phantompid" > "$pidfile"
    echo "Started PhantomJS..." >&2
  else
    echo "-- could not start PhantomJS (some tests may not work as expected)..." >&2
  fi
fi

# Export Behat environment specific settings...

export BEHAT_PARAMS='{"extensions": {"Behat\\MinkExtension": {"base_url": "'"$UAQSTEST_BASEURL"'"},"Drupal\\DrupalExtension": {"drupal": {"drupal_root": "'"${UAQSTEST_DRUPALROOT}"'"}, "drush": {"root": "'"${UAQSTEST_DRUPALROOT}"'"}}}}'

# Run the tests...

if [ "$UAQSTEST_RUNTESTS" -eq 0 ]; then
  bin/behat
  err="$?"
  if [ "$err" -ne 0 ]; then
    echo "** some of the Behat + Mink tests failed: error code ${err}." >&2
  else
    echo "The Behat + Mink tests passed..." >&2
  fi
  if [ -r "$pidfile" ]; then
    read pid < "$pidfile"
    if [ -n "$pid" ]; then
      echo "Trying to stop our own PhantomJS instance..." >&2
      kill "$pid" || true
    fi
  fi
  exit "$err"
fi

exit 0
