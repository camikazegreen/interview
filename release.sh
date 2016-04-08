#!/bin/bash
# Script to prepare and tag releases for UA QuickStart distribution and
# related proejcts.
#
# This script should be executed from within an up-to-date working-copy of the
# UA QuickStart git repository.
#
# To use this script, you must have Git Release Notes for Drush installed
# @see https://drupal.org/project/grn

function usage
{
  echo "Usage: $0 [-p] old_tag new_tag"
  echo "      -p    push changes to origin"
}

#### Main
push_mode=
while getopts ":p" opt; do
  case $opt in
    p)
      echo "Push mode enabled."
      push_mode=1
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      usage
      exit 1
      ;;
  esac
  shift $((OPTIND-1))
done

if [ $# -ne 2 ]; then
  usage
  exit 1
fi

# Identify the old tag number (do not repeat this: choose the current tag).
#export UAQSOLDTAG="7.x-1.0-alpha1"
export UAQSOLDTAG=$1

# Identify the new tag number  (do not repeat this: choose the actual tag).
#export UAQSNEWTAG="7.x-1.0-alpha2"
export UAQSNEWTAG=$2

# Create a string to use for a temporary tag.
export UAQSTMPTAG="$UAQSNEWTAG"-tmp

# Create temporary folder.
mkdir release_tmp
cd release_tmp

# Define list of UA QuickStart components to tag releases for.
# Option 1: List automatically derived from drupal-org.make.
export UAQSPROJECTS=`grep 'https://bitbucket.org/' ../drupal-org.make | awk '{ print $3; }' | sed 's/.*ua_drupal\/\(.*\)\.git.*/\1/'` ;
# Option 2: Manual list.
#export UAQSPROJECTS="uaqs_block_types ua_cas uaqs_core uaqs_demo uaqs_event uaqs_featured_content uaqs_fields ua_google_tag uaqs_navigation uaqs_news uaqs_page uaqs_person uaqs_program uaqs_publication uaqs_unit ua_zen" ;

#
# Update CHANGELOG and tag new release for each UA QuickStart component.
#
printf "Preparing to tag releases for individual UA QuickStart components...\n"
for r in $UAQSPROJECTS ; do
  printf "\nCloning $r...\n"
  git clone --quiet "git@bitbucket.org:ua_drupal/$r.git"
  cd $r

  printf "Updating CHANGELOG.txt for $r...\n"
  # Create a temporary tag.
  git tag "$UAQSTMPTAG"
  # Deal with projects that don't have existing tags.
  if git rev-parse "$1" >/dev/null 2>&1 ; then
    hash=`git log --grep="Preparing to tag $1." -n 1 --pretty=format:%H`
    if [ x"$hash" = x ]; then
      UAQSOLDREF="$1"
    else
      UAQSOLDREF="$hash"
    fi
  else
    UAQSOLDREF=`git rev-list --max-parents=0 HEAD`
  fi
  export UAQSOLDREF
  # Ensure CHANGELOG.txt exists and preserve current contents.
  touch CHANGELOG.txt
  mv CHANGELOG.txt CHANGELOG.old
  # Generate new CHANGELOG content.
  drush rn --changelog $UAQSOLDREF $UAQSTMPTAG 2>/dev/null | sed "s/$UAQSTMPTAG/$UAQSNEWTAG/" > CHANGELOG.txt
  # Ensure CHANGLELOG generation was successful.
  DRUSHRESULT=$?
  if [ $DRUSHRESULT -eq 0 ]; then
    # Append old CHANGELOG contents after new content and remove backup.
    cat CHANGELOG.old >> CHANGELOG.txt
    rm CHANGELOG.old
    git add CHANGELOG.txt
  else
    # Restore CHANGELOG.txt.
    mv CHANGELOG.old CHANGELOG.txt
    printf "Updating CHANGELOG.txt for $r failed.\n"
  fi

  printf "Preparing to tag release for $r...\n"
  # Add version info to .info files.
  export INFOFILES=`find . -name '*.info'`;
  for i in $INFOFILES ; do
    echo -e "version = $UAQSNEWTAG" >> $i
    git add $i
  done
  git commit -m "Preparing to tag $UAQSNEWTAG."
  git tag "$UAQSNEWTAG"

  printf "Restoring $r to default dev state...\n"
  # Remove version info from .info files.
  for i in $INFOFILES ; do
    sed -i '' "/version = /d" $i
    git add $i
  done
  git commit -m "Back to dev."

  printf "Cleaning up...\n"
  # Delete temporary tag.
  git tag -d "$UAQSTMPTAG"

  if [ "$push_mode" == "1" ]; then
    printf "Pushing to origin...\n"
    git push origin 7.x-1.x
    git push --tags
  fi

  printf "Updating $r references in UA QuickStart...\n"
  export UAQSNEWHASH=`git rev-parse --short HEAD`
  # Update project tag reference in distro's drupal.org-release.make file.
  if [ "$UAQSOLDREF" == "$1" ]; then
    # If old tag exists, replace with new tag.
    sed -i '' "/$r/s/$1/$UAQSNEWTAG/" ../../drupal-org-release.make
  else
    # Otherwise replace placeholder 'alhpa0' with new tag.
    sed -i '' "/$r/s/7.x-1.0-alpha0/$UAQSNEWTAG/" ../../drupal-org-release.make
  fi
  # Update project commit hash in distro's default drupal-org.make file.
  sed -i '' -E "/$r.*revision/s/.{7}$/$UAQSNEWHASH/" ../../drupal-org.make

  cd ..
done

#
# Prepare UA QuickStart distribution for release, tag new release, then restore
# files to their default dev state.
#

printf "\nPreparing to tag release for UA QuickStart Distribution...\n"
# Navigate to root of ua_quickstart directory.
cd ..
printf "Updating CHANGELOG.txt...\n"
# Create a temporary tag.
git tag "$UAQSTMPTAG"
# Update CHANGELOG.txt.
mv CHANGELOG.txt CHANGELOG.old
drush rn --changelog "$UAQSOLDREF" "$UAQSTMPTAG" 2>/dev/null | sed "s/$UAQSTMPTAG/$UAQSNEWTAG/" > CHANGELOG.txt
# Ensure CHANGLELOG generation was successful.
DRUSHRESULT=$?
if [ $DRUSHRESULT -eq 0 ]; then
  # Append old CHANGELOG contents after new content and remove backup.
  cat CHANGELOG.old >> CHANGELOG.txt
  rm CHANGELOG.old
  git add CHANGELOG.txt
else
  # Restore CHANGELOG.txt.
  mv CHANGELOG.old CHANGELOG.txt
  printf "Updating CHANGELOG.txt for $r failed.\n"
fi

printf "Preparing to tag release...\n"
# Backup uncommitted changes made to drupal-org.make file.
cp drupal-org.make drupal-org.make.bak
# Temporarily replace drupal-org.make with version referencing tagged releases.
cp drupal-org-release.make drupal-org.make
# Update build-ua_quickstart.make to point at new tag rather than to main branch.
sed -i '' "/branch/{s/branch/tag/;s/7.x-1.x/$UAQSNEWTAG/;}" build-ua_quickstart.make
# Add version info to .info file.
echo -e "version = $UAQSNEWTAG" >> ua_quickstart.info
git add drupal-org-release.make drupal-org.make build-ua_quickstart.make ua_quickstart.info
git commit -m "Preparing to tag $UAQSNEWTAG."
git tag "$UAQSNEWTAG"

printf "Restoring UA QuickStart to default dev state...\n"
# Restore dev version of drupal-org.make file with uncommitted modifications.
mv drupal-org.make.bak drupal-org.make
# Restore build-ua_quickstart.make to default dev state.
sed -i '' "/tag/{s/tag/branch/;s/$UAQSNEWTAG/7.x-1.x/;}" build-ua_quickstart.make
# Remove version info from .info file.
sed -i '' "/version = /d" ua_quickstart.info
git add drupal-org.make build-ua_quickstart.make ua_quickstart.info
git commit -m "Back to dev."

printf "Cleaning up...\n"
# Delete temporary tag.
git tag -d "$UAQSTMPTAG"
# Cleanup temporary folder.
#rm -Rf release_tmp

if [ "$push_mode" == "1" ]; then
  printf "Pushing to origin...\n"
  git push origin 7.x-1.x
  git push origin --tags
fi
