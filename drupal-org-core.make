api = 2
core = 7.x

; Drupal Core
projects[drupal][type] = core
projects[drupal][version] = 7.50

; *********** PATCHES ************

; Fixes core bug preventing menu links removed from code from being removed from database.
; @see https://jira.arizona.edu/browse/UADIGITAL-546
; @see https://www.drupal.org/node/1079628
projects[drupal][patch][1079628] = http://drupal.org/files/issues/programatically_added-1079628-24-d7.patch
