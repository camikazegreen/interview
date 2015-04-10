; ------------------------------------------------------------------------------
; UA Brand Navigation Makefile
;
; Downloads module and library dependencies for UA Brand Navigation components.
; ------------------------------------------------------------------------------

core = 7.x
api = 2

; Set default contrib destination
defaults[projects][subdir] = contrib

; ------------------------------------------------------------------------------
; Contrib modules
; ------------------------------------------------------------------------------

projects[jquery_update][version] = 2.5

projects[menu_block][version] = 2.5

projects[responsive_menus][version] = 1.x-dev
projects[responsive_menus][download][type] = git
projects[responsive_menus][download][revision] = c3b0835
projects[responsive_menus][download][branch] = 7.x-1.x

projects[superfish][version] = 1.x-dev
projects[superfish][download][type] = git
projects[superfish][download][revision] = fa3d7c6
projects[superfish][download][branch] = 7.x-1.x


; ------------------------------------------------------------------------------
; Libraries
; ------------------------------------------------------------------------------

; 'ResponsiveMultiLevelMenu' required by responsive_menus contrib module.
; No release version(s) available.  Module documentation says to use URL below.
libraries[ResponsiveMultiLevelMenu][download][type] = get
libraries[ResponsiveMultiLevelMenu][download][url] = https://github.com/codrops/ResponsiveMultiLevelMenu/archive/master.zip

; 'sidr' required by responsive_menus contrib module.
libraries[sidr][download][type] = get
libraries[sidr][download][url] = "https://github.com/artberri/sidr-package/archive/1.2.1.zip"
