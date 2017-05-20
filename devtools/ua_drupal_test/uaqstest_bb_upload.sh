#!/bin/sh
#------------------------------------------------------------------------------
#
# uaqstest_bb_upload.sh: upload build artefacts to Bitbucket download areas.
#
# Originally based on an early version of
# https://bitbucket.org/Swyter/bitbucket-curl-upload-to-repo-downloads
# (an upload script provided before Bitbucked documented uploads in their API),
# this now uses the mechanism described at
# https://developer.atlassian.com/bitbucket/api/2/reference/resource/repositories/%7Busername%7D/%7Brepo_slug%7D/downloads#post
#
# See also:
# https://confluence.atlassian.com/bitbucket/deploy-build-artifacts-to-bitbucket-downloads-872124574.html
# and
# https://bitbucket.org/site/master/issues/3251/add-custom-file-uploads-to-rest-api-bb
#
# Todo: Use OAuth2-based authentication, re-using the credentials for build
# status updates.
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Environment variables and semi-constants.

# Repository owner: internal Bitbucket settings override anything else.
[ -n "$BITBUCKET_REPO_OWNER" ] && \
  UAQSTEST_REPO_OWNER="$BITBUCKET_REPO_OWNER"
[ -z "$UAQSTEST_REPO_OWNER" ] && \
  UAQSTEST_REPO_OWNER='ua_drupal'}

# Repository machine name: internal Bitbucket settings override anything else.
[ -n "$BITBUCKET_REPO_SLUG" ] && \
  UAQSTEST_REPO_SLUG="$BITBUCKET_REPO_SLUG"
[ -z "$UAQSTEST_REPO_SLUG" ] && \
  UAQSTEST_REPO_SLUG='ua_quickstart'}

#------------------------------------------------------------------------------
# Utility functions definitions.

errorexit () {
  echo "** $1." >&2
  exit 1
}

# Show progress on STDERR, unless explicitly quiet.
if [ -z "$UAQSTEST_QUIET" ]; then
  logmessage () {
    echo "$1..." >&2
  }
  normalexit () {
    echo "$1." >&2
    exit 0
  }
else
  logmessage () {
    return
  }
  normalexit () {
    exit 0
  }
fi

#------------------------------------------------------------------------------
# Initial run-time error checking.

# The Bitbucket user name:
[ -z "$UAQSTEST_BBUSER" ] && \
  errorexit "no BitBucket username (must set UAQSTEST_BBUSER)"

# The Bitbucket password:
[ -z "$UAQSTEST_BBPASS" ] && \
  errorexit "no BitBucket password (must set UAQSTEST_BBPASS)."

[ $# -eq 0 ] && \
  errorexit "no file specified for upload"

af=$1
logmessage "The artefact file to upload is ${af}"
[ -e "$af" ] || \
  errorexit "could not find the upload file"

#------------------------------------------------------------------------------
# Actual upload operation (trivial, and silent unless there are errors).

curl -X POST "https://api.bitbucket.org/2.0/repositories/${UAQSTEST_REPO_OWNER}/${UAQSTEST_REPO_SLUG}/downloads" \
  --user "${UAQSTEST_BBUSER}:${UAQSTEST_BBPASS}" \
  --form files=@"$af"

err="$?"
if [ "$err" -ne 0 ]; then
  errorexit "Could not upload, curl returned '${err}'"
else
  normalexit "Upload OK"
fi
