UA Quickstart* Drupal Distribution and Install Profile
=============================================================
(*) Name subject to change

Demonstration/starter Drupal distribution and installation profile that packages various features consistent with community best practices and UA brand strategy.

## Install Profile Features

- Creates default text formats (copied from Drupal Standard install profile, for now).
- Creates default administrator role (copied from Drupal Standard install profile, for now).
- Enables some default blocks.

## Distribution Packaged Features (Dependencies)

- [UA Core Feature](https://bitbucket.org/ua_drupal/ua_core)
- [UA Demo Content Feature](https://bitbucket.org/ua_drupal/ua_demo)
- [UA Navigation Feature](https://bitbucket.org/ua_drupal/ua_navigation)
- [UA (CALS) Content Types Feature](https://bitbucket.org/uabrandingdigitalassets/cals-ua-features)
- [UA Featured Content (Carousel) Feature](https://bitbucket.org/ua_drupal/ua_featured_content)
- [UA Zen Theme](https://bitbucket.org/uabrandingdigitalassets/ua-zen)
- More to come...

## Build Information

This distribution can be built using [Drush make](http://docs.drush.org/en/stable/make/).

### Build Distribution with Drupal Core and all dependencies

1. Change into the directory that you want the built distribution folder to be created in, e.g.:

        cd /var/www

2. Create a temporary build folder, e.g.:

        mkdir build

3. Clone the repository into the build folder, e.g.:

        git clone git@bitbucket.org:ua_drupal/ua_quickstart.git build/ua_quickstart

4. Check out a release tag (optional), e.g.:

        cd build/ua_quickstart
        git checkout 7.x-1.0-beta1

5. Change back into the directory that you want the built distribution folder to be created in, e.g.:

        cd /var/www

6. Use drush make to build the distribution, e.g.:

        drush make build/ua_quickstart/build-ua_quickstart.make ua_quickstart

7. Remove the build folder (optional), e.g.:

        rm -Rf build
