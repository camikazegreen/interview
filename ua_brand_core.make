; ------------------------------------------------------------------------------
; UA Brand Core Makefile
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
; Dependencies common to most UA Brand features/sites
; ------------------------------------------------------------------------------

projects[ctools][version] = 1.7

projects[entity][version] = 1.6

projects[libraries][version] = 2.2

projects[pathauto][version] = 1.2

projects[token][version] = 1.5

projects[views][version] = 3.10


; ------------------------------------------------------------------------------
; Commonly used field modules
; ------------------------------------------------------------------------------

projects[date][version] = 2.8

projects[entityreference][version] = 1.1

projects[field_group][version] = 1.4

projects[link][version] = 1.3


; ------------------------------------------------------------------------------
; Features module and related
; ------------------------------------------------------------------------------

projects[features][version] = 2.3

projects[strongarm][version] = 2.0


; ------------------------------------------------------------------------------
; UA Zen theme dependencies
; ------------------------------------------------------------------------------

; TODO: is this really needed for the theme?
projects[block_class][version] = 2.1

; TODO: is this really needed for the theme?
projects[jquery_update][version] = 2.5

projects[responsive_menus][version] = 1.5

projects[superfish][version] = 1.9
; Fix superfish module's makefile which packages the superfish library
projects[superfish][patch][] = http://cgit.drupalcode.org/superfish/patch/?id=3524a21ee42ce75a56fe1814256db5ae15b5d98a

projects[zen][version] = 5.5


; ------------------------------------------------------------------------------
; Libraries
; ------------------------------------------------------------------------------
