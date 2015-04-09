; ------------------------------------------------------------------------------
; UA Featured Content Makefile
;
; Downloads contrib module dependencies for UA Featured Content component.
; ------------------------------------------------------------------------------

core = 7.x
api = 2

; Set default contrib destination
defaults[projects][subdir] = contrib

; ------------------------------------------------------------------------------
; Contrib modules
; ------------------------------------------------------------------------------

projects[flexslider][version] = 2.0-alpha3

projects[image_url_formatter][version] = 1.4


; ------------------------------------------------------------------------------
; Libraries
; ------------------------------------------------------------------------------

; TODO: investigate whether we can download a specific release/tagged version.
libraries[flexslider][download][type] = "get"
libraries[flexslider][download][url] = "https://github.com/woothemes/FlexSlider/zipball/master"
libraries[flexslider][directory_name] = "flexslider"
