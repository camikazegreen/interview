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

; TODO: remove this after third release.
projects[superfish][version] = 1.x-dev
projects[superfish][download][type] = git
projects[superfish][download][revision] = fa3d7c6
projects[superfish][download][branch] = 7.x-1.x
