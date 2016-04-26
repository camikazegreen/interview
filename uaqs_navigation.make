; ------------------------------------------------------------------------------
; UAQS Navigation Makefile
;
; Downloads module and library dependencies for UAQS Navigation components.
; ------------------------------------------------------------------------------

core = 7.x
api = 2

; Set default contrib destination
defaults[projects][subdir] = contrib

; ------------------------------------------------------------------------------
; Contrib modules
; ------------------------------------------------------------------------------

projects[bean][version] = 1.9
projects[menu_bean][version] = 1.0-beta2
projects[menu_block][version] = 2.7
projects[xautoload][version] = 5.6
projects[superfish][version] = 2.0
