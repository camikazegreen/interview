#!/bin/bash

# update-component.sh
# Component Update script for UA Quickstart
#
# This script updates the revision defined in UA QuickStart's drupal-org.make
# file for the $PROJECT_NAME component with the new $REVISION value and then
# stages, commits, and pushes the change.
#
# To work properly, this script must be run from within a cloned working tree of
# the ua_quickstart repository.
#
# Required environment variables
# - $PROJECT_NAME The name of the component repository
# - $REVISION The revision hash of the latest commit in the component repository
#
# Optional environment variables
# - $COMMIT_MSG The message to use when committing the changes

if [ -z "$PROJECT_NAME" ]; then
    echo "Please set PROJECT_NAME environment variable."
    exit 1
fi

if [ -z "$REVISION" ]; then
    echo "Please set REVISION environment variable."
    exit 1
fi

SEARCH_PATTERN="projects\[${PROJECT_NAME}\]\[download\]\[revision\]"
DEFAULT_COMMIT_MSG="Updating ${PROJECT_NAME} with latest revision."
COMMIT_MSG=${COMMIT_MSG:-${DEFAULT_COMMIT_MSG}}

sed -i "s/${SEARCH_PATTERN}.*/${SEARCH_PATTERN}\ \=\ ${REVISION:0:7}/g" drupal-org.make
git add drupal-org.make
git commit -m "${COMMIT_MSG}"