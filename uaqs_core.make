; ------------------------------------------------------------------------------
; UA Core Makefile
;
; This makefile should stay as bare-bones as possilbe.  In general, individual
; modules/features should include their own makefiles to package their own
; dependencies.  Ideally, only dependencies that are common to most sites using
; the UA Drupal distribution (regardless of how many individual features have
; been enabled) should be included here.
; ------------------------------------------------------------------------------

core = 7.x
api = 2

; Set default contrib destination
defaults[projects][subdir] = contrib

; ------------------------------------------------------------------------------
; Contrib dependencies common to many UA features/sites
; ------------------------------------------------------------------------------

projects[ctools][version] = 1.7

projects[entity][version] = 1.6

projects[libraries][version] = 2.2

projects[pathauto][version] = 1.2

projects[token][version] = 1.6

projects[views][version] = 3.10


; ------------------------------------------------------------------------------
; Commonly used field modules
; ------------------------------------------------------------------------------

projects[auto_nodetitle][version] = 1.0

projects[date][version] = 2.8

projects[email][version] = 1.3

projects[entityreference][version] = 1.1

projects[auto_nodetitle][version] = 1.0

projects[field_collection][version] = 1.0-beta8

projects[field_group][version] = 1.4

projects[link][version] = 1.3


; ------------------------------------------------------------------------------
; Features module and related
; ------------------------------------------------------------------------------

projects[defaultconfig][version] = 1.0-alpha9
projects[defaultconfig][patch][2042799] = http://drupal.org/files/default_config_delete_only_if_overriden.patch
projects[defaultconfig][patch][2043307] = http://drupal.org/files/defaultconfig_include_features_file.patch
projects[defaultconfig][patch][2008178] = http://drupal.org/files/defaultconfig-rebuild-filters-2008178-4_0.patch
projects[defaultconfig][patch][1861054] = http://drupal.org/files/fix-defaultconfig_rebuild_all.patch
projects[defaultconfig][patch][2221005] = http://drupal.org/files/issues/defaultconfig-duplicate_modules_in_overview-2221005-1.patch

projects[features][version] = 2.5

projects[migrate][version] = 2.7

projects[strongarm][version] = 2.0


; ------------------------------------------------------------------------------
; UA Zen theme dependencies
; ------------------------------------------------------------------------------

projects[zen][version] = 5.5
projects[zen][subdir] = ''


; ------------------------------------------------------------------------------
; Libraries
; ------------------------------------------------------------------------------
