; Makefile for UA Quickstart distribution
core = 7.x
api = 2

; =====================================
; UA Modules
; =====================================

projects[ua_core][type] = module
projects[ua_core][subdir] = custom
projects[ua_core][download][type] = git
projects[ua_core][download][branch] = 7.x-1.x
projects[ua_core][download][url] = https://bitbucket.org/ua_drupal/ua_core.git

projects[ua_cas][type] = module
projects[ua_cas][subdir] = custom
projects[ua_cas][download][type] = git
projects[ua_cas][download][branch] = 7.x-1.x
projects[ua_cas][download][url] = https://bitbucket.org/ua_drupal/ua_cas.git

projects[ua_demo][type] = module
projects[ua_demo][subdir] = custom
projects[ua_demo][download][type] = git
projects[ua_demo][download][branch] = 7.x-1.x
projects[ua_demo][download][url] = https://bitbucket.org/ua_drupal/ua_demo.git

projects[ua_featured_content][type] = module
projects[ua_featured_content][subdir] = custom
projects[ua_featured_content][download][type] = git
projects[ua_featured_content][download][branch] = 7.x-1.x
projects[ua_featured_content][download][url] = https://bitbucket.org/ua_drupal/ua_featured_content.git

projects[ua_navigation][type] = module
projects[ua_navigation][subdir] = custom
projects[ua_navigation][download][type] = git
projects[ua_navigation][download][branch] = 7.x-1.x
projects[ua_navigation][download][url] = https://bitbucket.org/ua_drupal/ua_navigation.git

projects[ua_page][type] = module
projects[ua_page][subdir] = custom
projects[ua_page][download][type] = git
projects[ua_page][download][branch] = 7.x-1.x
projects[ua_page][download][url] = https://bitbucket.org/ua_drupal/ua_page.git


; =====================================
; UA Themes
; =====================================

projects[ua_zen][type] = theme
projects[ua_zen][directory_name] = ua_zen
projects[ua_zen][download][type] = git
projects[ua_zen][download][branch] = 7.x-1.x
projects[ua_zen][download][url] = https://bitbucket.org/ua_drupal/ua_zen.git
