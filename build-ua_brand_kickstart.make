; Use this file to build a full distribution including Drupal core and the
; UA Brand Kickstart dependencies using the following command:
;
; drush make build-ua_brand_kickstart.make <target directory>

api = 2
core = 7.x

includes[] = drupal-org-core.make

; Download install profile and recursively build all its dependencies.
projects[ua_brand_kickstart][type] = profile
projects[ua_brand_kickstart][download][type] = git
projects[ua_brand_kickstart][download][branch] = joegraduate
projects[ua_brand_kickstart][download][url] = git@bitbucket.org:joegraduate/ua_brand_kickstart.git
