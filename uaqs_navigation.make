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

; TODO: figure out if we really need to be using the dev version of this.
projects[superfish][version] = 1.x-dev
projects[superfish][download][type] = git
projects[superfish][download][revision] = fa3d7c6
projects[superfish][download][branch] = 7.x-1.x


; ------------------------------------------------------------------------------
; Libraries
; ------------------------------------------------------------------------------

; 'Superfish' required by Superfish contrib module.
; Even though the Superfish module has its own make file that packages this
; library, we need this 'master' version to work with the dev release of the
; module that we are using.
libraries[superfish][download][type] = get
libraries[superfish][download][url] = https://github.com/mehrpadin/Superfish-for-Drupal/archive/master.zip
