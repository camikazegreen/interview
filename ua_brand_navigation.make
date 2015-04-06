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

projects[responsive_menus][version] = 1.5

projects[superfish][version] = 1.9
; Fix superfish module's makefile which packages the superfish library
projects[superfish][patch][] = http://cgit.drupalcode.org/superfish/patch/?id=3524a21ee42ce75a56fe1814256db5ae15b5d98a


; ------------------------------------------------------------------------------
; Libraries
; ------------------------------------------------------------------------------

; 'ResponsiveMultiLevelMenu' required by responsive_menus contrib module.
; No release version(s) available.  Module documentation says to use URL below.
libraries[ResponsiveMultiLevelMenu][download][type] = get
libraries[ResponsiveMultiLevelMenu][download][url] = http://tympanus.net/Development/ResponsiveMultiLevelMenu/ResponsiveMultiLevelMenu.zip

; 'sidr' required by responsive_menus contrib module.
libraries[sidr][download][type] = get
libraries[sidr][download][url] = "https://github.com/artberri/sidr-package/archive/1.2.1.zip"
