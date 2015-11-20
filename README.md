# UA Drupal Test

## Local Development ##

Local development testing uses the `behat` and `mink` libraries.
All of the tests are defined as featured in the `features/` directory and the files end in `.feature`.

### Setup ###

1. Clone the repository somewhere on your machine.
It doesn't have to be in the directory with UA Quickstart.

2. Run `composer install` from this project's directory.
If you don't have composer, [go check it out](http://getcomposer.org)

3. Copy the `config/behat.yml` file up one directory level:  
`cp config/behat.yml ./`

4. Replace the `base_url` and `drupal_root` values with the base url to your site and the location on disk of your drupal root directory.

5. Run the tests by running the `behat` executable in the `bin/` directory of this project: e.g. `bin/behat`.

### Making new tests ###

Behat, Mink, and the Drupal extension we are using have a pretty sizable library of steps that are already defined.
To see them on the command line, run:

    bin/behat --definitions l

Or run `bin/behat --definitions i` to get a short description of most of the steps.

Look at existing features to get a sense of how the [gherkin](http://docs.behat.org/en/v2.5/guides/1.gherkin.html) syntax looks and feels.

### Tags ###

We currently have 2 tags defined to help separate our tests:

#### @regression ####

After a bug has been found, `@regression` scenarios should be able to replicate the bug.
That way, when the bug is fixed, the test will pass and we can make sure the bug doesn't come back.

#### @story ####

To help define what users should be able to do, we'll want to codeify user stories from the UI/UX team.
Those tests will be tagged with `@story` and operate on a higher level than the `@regression` tagged tests.

## CI Server ##

### Background ###

This configures automated tests of a custom Drupal distribution built by [UA Quickstart](https://bitbucket.org/ua_drupal/ua_quickstart) as one of the [University of Arizona Drupal](https://bitbucket.org/ua_drupal) projects. It assumes that a previous step has already built the packaged version of the distribution that does not require Git or specialist development tools to use as the basis of a new site installation, and tries to follow the steps a user would use to do this, downloading the distribution tarball, fixing up the `sites/default/settings.php` file and `sites/default/files` directory, specifying a local MySQL database to use, and so on. Because UA Quickstart already includes some demonstration content, this immediately produces a site on which some test suites can run. The tests use [CasperJS](http://casperjs.org/) in combination with the Webkit-based headless browser [PhantomJS](http://phantomjs.org/). CasperJS already has Drupal-specific support as a [drush add-on](https://www.drupal.org/project/casperjs). Although some other testing tools (notably Behat) can also work well with Drupal, CasperJS makes it easy to write many terse tests for an audience of developers, rather than more verbose tests that end users might also understand. There has been some previous experience with the combination of CasperJS and PhantomJS at the University of Arizona: in particular Mark Fischer experimented with them at the end of 2014. Nothing would prevent someone running the automated tests in their own development environment, but the main intent is to have a continuous integration system such as Jenkins do this whenever it packages a new version of the distribution. But the test suites are completely decoupled from any earlier build and packaging steps, even if run on the same server responsible for these earlier stages.

### Requirements ###

The tests have the same requirements as a normal new Drupal installation: a web server correctly configured to have a Drupal site under its document root, and a MySQL server with the credentials of a user on it with rights to create and drop all content from a specified database. Drush is required both for the `site-install` operation, but also for invoking the tests through the custom extra `casperjs` operation, and the current version of the [README.txt](http://cgit.drupalcode.org/casperjs/tree/README.txt?h=7.x-1.x) for setting this up is a good guide to follow for the required PhantomJS and CasperJS installations. Note that the particular combinations of versions does matter, and the recommended PahntomJS version is not currently the latest release. The casperjs drush extension should come from a git clone or the 7.x-1.x-dev version download: the 7.x-1.1 version has known problems that prevent the tests running. There are some relevant notes and blog postings from various sources, including further advice on [setting everything up](http://blog.navigationarts.com/getting-started-with-casperjs-and-drupal/) and [integrating it with Jenkins](http://blog.navigationarts.com/reporting-casperjs-test-results-in-jenkins/).

### Running ###

There are two distinct phases to running the tests. A shell script `ua_drupal_test_runner.sh` sets up the initial environment, downloading, unpacking and configuring the UA Quickstart distribution, before invoking `drush site-install` to automate the final steps of the installation. But it then passes control to the test runner in CasperJS to handle all the test suites.
