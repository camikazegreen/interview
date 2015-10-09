; ------------------------------------------------------------------------------
; UA Navigation Makefile
;
; Downloads module and library dependencies for UA Navigation components.
; ------------------------------------------------------------------------------

core = 7.x
api = 2

; Set default contrib destination
defaults[projects][subdir] = contrib

; ------------------------------------------------------------------------------
; Contrib modules
; ------------------------------------------------------------------------------

projects[jquery_update][version] = 2.6

projects[menu_block][version] = 2.7

