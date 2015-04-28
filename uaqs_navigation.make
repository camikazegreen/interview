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

projects[jquery_update][version] = 2.5

projects[menu_block][version] = 2.5

; TODO: figure out if we really need to be using the dev version of this.
projects[responsive_menus][version] = 1.x-dev
projects[responsive_menus][download][type] = git
projects[responsive_menus][download][revision] = c3b0835
projects[responsive_menus][download][branch] = 7.x-1.x

; TODO: figure out if we really need to be using the dev version of this.
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

; 'Superfish' required by Superfish contrib module.
; Even though the Superfish module has its own make file that packages this
; library, we need this 'master' version to work with the dev release of the
; module that we are using.
libraries[superfish][download][type] = get
libraries[superfish][download][url] = https://github.com/mehrpadin/Superfish-for-Drupal/archive/master.zip
