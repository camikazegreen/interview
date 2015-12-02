UA Quickstart* Drupal Distribution and Install Profile
=============================================================
(*) Name subject to change

Demonstration/starter Drupal distribution and installation profile that packages various features consistent with community best practices and UA brand strategy.

## A Complete Customized Drupal

UA Quickstart is a complete customized version of the popular Drupal content management system, not an add-on to an existing Drupal-based web site. Previously to start a new Drupal site you would prepare a web server and database, then download the Drupal core software from drupal.org and install it (following the instructions at https://www.drupal.org/documentation/install). This would produce a minimally functional web site with no content, which you could then customize by adding themes and modules to fit it to your needs. Increasing, however, you can download Drupal distributions, which not only contain the core, but also complete sets of additions to make it almost immediately useful for a particular purpose, such as an online storefront. UA Quickstart is the distribution that provides many of the features specific to the University of Arizona, and rather than an empty site, initially shows some demonstration content (which can nevertheless be turned off instantly).

## Packaged versions

Complete pre-built versions of the UA Quickstart distribution are in the [download area](https://bitbucket.org/ua_drupal/ua_quickstart/downloads). The file names give the release version (you will generally want the most recent release), and the file suffixes give the compression method, `.zip` and `.tar.gz`. Treat these exactly as you would a manual download of Drupal itself from drupal.org: prepare a local development or test web server, a MySQL database, expand the `.zip` or `.tar.gz` file where you would like the site to appear, and go through the usual steps to bring up a new Drupal site, following the instructions from the drupal.org [installation guide](https://www.drupal.org/documentation/install). Pre-packaged [development .tar.gz](http://jenkins.ltrr.arizona.edu/job/ua_quickstart/lastSuccessfulBuild/artifact/ua_quickstart-7.x-1.x-dev.tar.gz) and [development .zip](http://jenkins.ltrr.arizona.edu/job/ua_quickstart/lastSuccessfulBuild/artifact/ua_quickstart-7.x-1.x-dev.zip) files are also available; these will generally contain the latest changes, which might be unstable experimental features, but might also be fixes for known problems.

## Install Profile Features

- Creates default text formats (copied from Drupal Standard install profile, for now).
- Creates default administrator role (copied from Drupal Standard install profile, for now).
- Enables some default blocks.

## Distribution Packaged Features (Dependencies)

- [UA Zen Theme](https://bitbucket.org/ua_drupal/ua_zen)
- [UA CAS Feature](https://bitbucket.org/ua_drupal/ua_cas)
- [UA Google Tag Feature](https://bitbucket.org/ua_drupal/ua_google_tag)
- [UA Core Feature](https://bitbucket.org/ua_drupal/ua_core)
- [UA Demo Content Feature](https://bitbucket.org/ua_drupal/ua_demo)
- [UA Event Feature](https://bitbucket.org/ua_drupal/ua_event)
- [UA Google Tag](https://bitbucket.org/ua_drupal/ua_google_tag)
- [UA Featured Content (Carousel) Feature](https://bitbucket.org/ua_drupal/ua_featured_content)
- [UA Navigation Feature](https://bitbucket.org/ua_drupal/ua_navigation)
- [UA News Feature Feature](https://bitbucket.org/ua_drupal/ua_news)
- [UA Page Feature](https://bitbucket.org/ua_drupal/ua_page)
- [UA Person Feature](https://bitbucket.org/ua_drupal/ua_person)
- [UA Program Feature](https://bitbucket.org/ua_drupal/ua_program)
- [UA Publication Feature](https://bitbucket.org/ua_drupal/ua_publication)
- [UA Unit Feature](https://bitbucket.org/ua_drupal/ua_unit)
- More to come...

## Contributing to the Project

To contribute to the project you will need your own account on the [Bitbucket](bitbucket.org) repository hosting service, as well as a local development environment (like a laptop or test web server) where you can use the [Git](http://git-scm.com/) version control system client and the widely used [Drush](http://docs.drush.org/en/master/) Drupal command-line utility. Ideally your development environment will include a web server that can support Drupal, for local testing of your work.

### 1. Fork a Repository on Bitbucket

Pick the repository on Bitbucket that contains the code you would like to modify, and fork your own copy of it. So if you are looking at the repository for UA Google Tag at https://bitbucket.org/ua_drupal/ua_google_tag and your Bitbucket username is `tobiashume`, you would select the “Fork” option that Bitbucket provides, and end up with a new `tobiashume/ua_google_tag` repository (when it prompts you for options, don't bother changing anything, and in particular keep it public).

### 2. Clone your Forked Repository

Clone a copy of your forked repository in some location where it is easy to work on. So after changing to the correct directory, it would be just the usual command line Git clone:

    cd ~/gitwork
    git clone git@bitbucket.org:tobiashume/ua_google_tag.git

(with your username substituted for `tobiashume`, the repository of interest for `ua_google_tag` and your own working directory for Git clones in place of `gitwork`).

### 3. Check Out an Issue Branch

Checkout a new branch in your local clone of the forked repository. If possible, name it after the issue in Jira that your changes will address, but if you don't know this simply pick something descriptive. So in this example:

    cd ua_google_tag
    git checkout -b 'UADIGITAL-184'

### 4. Work on Your Branch

Edit and add files according to the changes you need to make, committing changes as you go, for example:

    git commit -a -m 'Fix the URLs.'

### 5. Clone UA Quickstart

Clone the official UA Quickstart repository in some location that can't get confused with your work on the repository you are trying to change.

    cd ~/gitwork
    git clone https://bitbucket.org/ua_drupal/ua_quickstart.git

### 6. Modify the Clone to Use Itself

The clone of UA Quickstart will contain a tiny collection of files, just enough to throw together clones of all the other repositories for the UA Zen theme, the various features and so on. It refers back to the repository you just cloned it from, so it's vital to first break this circularity by telling it to use your local copy instead. Change to the directory holding your copy (`cd ua_quickstart`), noting the full path of this directory (so in this example something like `/home/tobiashume/gitwork/ua_quickstart`). Checkout a new branch: you can simply repeat the command for the feature branch you have been working on:

    git checkout -b 'UADIGITAL-184'

and edit the file called `build-ua_quickstart.make` replacing the lines telling it to use the repository on Bitbucket

    projects[ua_quickstart][download][branch] = 7.x-1.x
    projects[ua_quickstart][download][url] = https://bitbucket.org/ua_drupal/ua_quickstart.git

with some telling it to use the current location; so for the example of a current directory `/home/tobiashume/gitwork/ua_quickstart`, and a current checked out branch `UADIGITAL-184` that would be

    projects[ua_quickstart][download][branch] = UADIGITAL-184
    projects[ua_quickstart][download][url] = file:///home/tobiashume/gitwork/ua_quickstart/.git

### 7. Modify UA Quickstart to Include Your Changes

Your copy of UA Quickstart still refers back to the Bitbucket repository rather than your local copy of the theme or feature with all your recent work in it. If you have been working on `ua_google_tag` and your issue branch for the changes there is `UADIGITAL-184` edit the file `drupal-org.make` and replace the lines like

    projects[ua_google_tag][download][branch] = 7.x-1.x
    projects[ua_google_tag][download][revision] = bfba545
    projects[ua_google_tag][download][url] = https://bitbucket.org/ua_drupal/ua_google_tag.git

with the location of your recent work:

    projects[ua_google_tag][download][branch] = UADIGITAL-184
    projects[ua_google_tag][download][url] = file:///home/tobiashume/gitwork/ua_google_tag/.git

The paths to your changes will always refer to the hidden Git directory within your working directories, so will always end in `/.git`. After the edits are complete, commit your UA Quickstart changes, but unlike your other commits working on the issue you don't have to be too careful about the commit message, since this will not be preserved anywhere in the long term.

    git commit -a -m 'Refer to local files, not Bitbucket.'

### 8. Build UA Quickstart

Change to a directory where your local web server expects to find the document root directories of websites (for example `/var/www`) and where you have write access. Use the `drush make` command to build UA Quickstart, referring back to your local working copy (in the previous examples this has been in the directory `/home/tobiashume/gitwork/ua_quickstart` but you would substitute your own directory name):

    drush make /home/tobiashume/gitwork/ua_quickstart/build-ua_quickstart.make ua_quickstart

This should build the complete UA Quickstart distribution, with your changes included, in a directory called `ua_quickstart`; but if something goes wrong you might have to delete this directory and everything within it, make further changes to your work, and try again.

### 9. Bring up the New Drupal Site

Treat the new `ua_quickstart` directory as if it was a freshly downloaded copy of the main Drupal distribution. Make sure the directory will be treated as a document root in your webserver, make a database ready for it and tidy up the permissions under the `sites/default/files` subdirectory. If you normally use a web browser to bring up a new Drupal site it should work as expected, if you normally use the `drush site-install` command, invoke it from within the newly created `ua_quickstart` directory, and be sure to explicitly mention the `ua_quickstart` profile as well:

    cd ua_quickstart
    drush si ua_quickstart --account-mail=tobiashume@ltrr.arizona.edu --account-name=tuber --db-url=mysqli://uaqsdbadmin:MyOwnPassword@localhost/uaquickstartdb --site-name='UA Quickstart' -y

(substituting your own `--db-url` database details, and `--account-mail`, which shouldn't matter in a local test in any case).

### 10. Check the Changes on the New Site

Use some web browsers to look at the new site in your test environment, checking that your changes work and have not broken anything else. The UA Demo Content module should be providing some pre-loaded test content that exercises most of the features within UA Quickstart.

### 11. Push Your Issue Branch to Bitbucket

Once everything seems to work (which might take a few iterations of further edits and re-installing your local UA Quickstart distribution), make sure you are back in the directory holding your significant changes (which in the examples here has been `/home/tobiashume/gitwork/ua_google_tag`), make sure all the changes are committed to the issue branch in Git (use `git status` to check), then push the issue branch to your own forked Bitbucket repository. So for the example issue branch `UADIGITAL-184` the command would be:

    git push -u origin 'UADIGITAL-184'

where `origin` is the usual Git shorthand for the upstream repository, here your own fork of one of the various repositories for UA Quickstart themes and features, and the `-u` option updates the branch configuration for the remote repository (unnecessary after the first push to the origin).

### 12. Issue a Pull Request

Your contributions to the project should now be up in Bitbucket, but they are isolated in your own fork of whatever repository you have been working on. Go to the Bitbucket web page for your repository (it should have your Bitbucket user name in the URL, something like `https://bitbucket.org/tobiashume/ua_google_tag` *not* the main version of the repository with `ua_drupal` in the URL, like https://bitbucket.org/ua_drupal/ua_google_tag). Make sure it is showing your issue branch, then select Bitbucket's “Create pull request” option, which should show it to be merged into the 7.x-1.x branch of the main UA Quickstart repository you initially forked from.

- In the title of the pull request, repeat any of the issue numbers (in the form UADIGITAL-184) that your changes address: this helps automated updates of the issues within Jira.
- Add a brief description of how your changes address the issues.
- In the Reviewers section, enter at least one and preferably two team members to review your request, choosing the people most directly responsible for the parts of UA Quickstart you have changed.
- Check the “Close branch” option on your issue branch, since this isn't something that should have a long-term independent existence.

It should be showing you a summary of your changes in the same diff format the reviewers will see: after a final check, select the “Create pull request” button.

### 13. Wait for a Merge or Decline of Your Request

Wait for someone to merge or decline your request (the reviewers might want to check your contribution in their own environments, which takes time). But follow up with the reviewers if several days pass with no obvious activity, since other changes may make it difficult to merge your request if too much time passes. If there is a reason for the delay there should be discussion on Slack, or on the comments associated with the request within Bitbucket.

Merging the request puts your changes into the main UA Quickstart repository for a particular theme or feature, where anyone interested in the project should find them easily, but they will not be part of a build of the UA Quickstart distribution until someone updates the specific Git commit references in the  `drupal-org.make` file in the main repository for UA Quickstart  itself: the reference should be to the commit that merged your changes (or something more recent). As soon as this last change goes through, the Jenkins continuous integration system will build a fresh UA Quickstart distribution, run some tests on this, and (if they pass) install it on a generally visible [demonstration server](http://kitten.ltrr.arizona.edu/).

## Release management

Releases for UA Quickstart and its individual features/components happen at the same time.  When a new version of UA Quickstart is ready to be tagged for release, all of the individual UA Quickstart component projects repositories should also be tagged with the same release version, whether changes to the individual project have occurred or not.

### Tagging new releases

To simplify the process of tagging synchronized releases for UA Quickstart and its various components by UA Quickstart maintainers, a `release.sh` shell script has been added to the UA Quickstart repository which automates the process of preparing each of the individual projects for release and creates the actual release tags.

The `release.sh` script automates the following steps:

- Creates a temporary clone of each individual UA Quickstart component repository.
- Updates CHANGELOG.txt and adds version information to the .info file for each component.
- Creates a new release tag for each component.
- Restores each component back to its default dev state (removes version information from .info file).
- Pushes the new tag and other changes made to each component to the component's origin repository (optional).
- Updates the references to each component in UA Quickstart's drush make files.
- Updates CHANGELOG.txt and adds version information to UA Quickstart's .info and build-ua_quickstart.make files.
- Creates a new release tag for UA Quickstart.
- Pushes the new tag and other changes made to UA Quickstart to its origin repository (optional).
- Restores UA Quickstart back to its default dev state (removes version information from .info and build-ua_quickstart.make files).

To create a new release tag for UA Quickstart and all of its components using this script, a UA Quickstart maintainer should follow these steps:

1. Clone a fresh copy of the UA Quickstart repository in a temporary location.

    git clone git@bitbucket.org:ua_drupal/ua_quickstart.git

2. Change into the cloned repository directory.

    cd ua_quickstart

3. Execute the `release.sh` script using the previous release tag version as the first argument and the new release tag version as the second argument.  The optional `-p` option enables "push mode", which will automatically push the changes made by the script (including the new release tags) to the origin reopositries.  Special care should be taken when using the `-p` option.  It is recommended to execute this script without the `-p` option once to verify that everything works as expected without pushing anything to the origin repositories and then repeating steps 1-2 before running the script again with the `-p` option.

    ./release.sh -p 7.x-1.0-alpha1 7.x-1.0-alpha2
