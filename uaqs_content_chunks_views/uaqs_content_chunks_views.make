; ------------------------------------------------------------------------------
; UAQS Content Chunks Views Makefile
;
; Downloads the dependencies to add views as a UAQS Content Chunk.
; ------------------------------------------------------------------------------

core = 7.x
api = 2

; Set default contrib destination
defaults[projects][subdir] = contrib

; ------------------------------------------------------------------------------
; Contrib modules
; ------------------------------------------------------------------------------

projects[viewfield][version] = 2.1
