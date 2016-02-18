#!/bin/bash
#
# UA Quickstart distribution package upload script.
#
# Required environment variables...

# The BitBucket user name:
if [ x"$UAQSTEST_BBUSER" = x ]; then
  echo "** no BitBucket username (must set UAQSTEST_BBUSER)." >&2
  exit 1
fi

# The BitBucket user name:
if [ x"$UAQSTEST_BBPASS" = x ]; then
  echo "** no BitBucket password (must set UAQSTEST_BBPASS)." >&2
  exit 1
fi

bbdload='/ua_drupal/ua_quickstart/downloads'
if [ $# -eq 0 ] ; then
  echo "** no file specified for upload" >&2
  exit 1
else
  echo "Upload file name provided..." >&2
fi
fil=$1
if [ -e "$fil" ] ; then
  echo "Found the upload file..." >&2
else
  echo "** could not find the upload file $fil." >&2
  exit 1
fi
# works like this: GET /account/signin/ -> POST /account/signin/ -> auto-redir to downloads page -> POST downloads page

# GET initial csrf, dropped in the cookie, final 32 chars of the line containing that word
# [i] note: you can add the "-v" parameter to any cURL command to get a detailed/verbose output, useful to diagnose problems.
echo "Getting initial csrf token from the sign-in page..." >&2
curl -k -c cookies.txt -o /dev/null https://bitbucket.org/account/signin/

csrf=$(grep csrf cookies.txt); set $csrf; csrf=$7;

# and login using POST, to get the final session cookies, then redirect it to the right page
echo "Signing in with the credentials provided..." >&2
curl -k -c cookies.txt -b cookies.txt -o /dev/null -d "username=$UAQSTEST_BBUSER&password=$UAQSTEST_BBPASS&submit=&next=$bbdload&csrfmiddlewaretoken=$csrf" --referer "https://bitbucket.org/account/signin/" -L https://bitbucket.org/account/signin/

csrf=$(grep csrf cookies.txt); set $csrf; csrf=$7;

# check that we have the session cookie, if not, something bad happened, don't spend time uploading.

if [ -z "$(grep bb_session cookies.txt)" ] ; then
  echo "** could not get the session cookie." >&2
  exit 1
else
  echo "Got the session cookie..." >&2
fi

# now that we're logged-in and at the right page, upload whatever you want to your repository...
echo "Starting upload..." >&2
curl -k -c cookies.txt -b cookies.txt -o /dev/null --referer "https://bitbucket.org/$bbdload" -L --form csrfmiddlewaretoken=$csrf --form token= --form files=@"$fil" https://bitbucket.org/$bbdload

echo "Closing session..." >&2
curl -k -c cookies.txt -b cookies.txt -o /dev/null -L https://bitbucket.org/account/signout/
