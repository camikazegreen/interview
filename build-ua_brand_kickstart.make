; Use this file to build a full distribution including Drupal core and the
; UA Quickstart dependencies using the following command:
;
; drush make build-ua_quickstart.make <target directory>

api = 2
core = 7.x

includes[] = drupal-org-core.make

; Download install profile and recursively build all its dependencies.
projects[ua_quickstart][type] = profile
projects[ua_quickstart][download][type] = git
projects[ua_quickstart][download][branch] = rename
projects[ua_quickstart][download][url] = git@bitbucket.org:joegraduate/ua_brand_kickstart.git
