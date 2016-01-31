; ------------------------------------------------------------------------------
; UAQS Person Makefile
;
; Downloads the Views Bootstrap module dependencies for UAQS Person components.
; ------------------------------------------------------------------------------

core = 7.x
api = 2

; Set default contrib destination
defaults[projects][subdir] = contrib

; ------------------------------------------------------------------------------
; Contrib modules
; ------------------------------------------------------------------------------

projects[views_bootstrap][version] = 3.x-dev
projects[views_bootstrap][download][type] = "git"
projects[views_bootstrap][download][url] = "http://git.drupal.org/project/views_bootstrap.git"
projects[views_bootstrap][download][revision] = "9c9a049a43686c483be5513514e62e6013cf43e1"
projects[views_bootstrap][patch] = https://www.drupal.org/files/issues/views_bootstrap-breakpoint-control-2203111-92-7.x.patch