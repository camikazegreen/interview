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
projects[ua_core][download][url] = git@bitbucket.org:ua_drupal/ua_core.git

projects[ua_demo][type] = module
projects[ua_demo][subdir] = custom
projects[ua_demo][download][type] = git
projects[ua_demo][download][branch] = 7.x-1.x
projects[ua_demo][download][url] = git@bitbucket.org:ua_drupal/ua_demo.git

projects[ua_navigation][type] = module
projects[ua_navigation][subdir] = custom
projects[ua_navigation][download][type] = git
projects[ua_navigation][download][branch] = 7.x-1.x
projects[ua_navigation][download][url] = git@bitbucket.org:ua_drupal/ua_navigation.git

projects[ua_featured_content][type] = module
projects[ua_featured_content][subdir] = custom
projects[ua_featured_content][download][type] = git
projects[ua_featured_content][download][branch] = 7.x-1.x
projects[ua_featured_content][download][url] = git@bitbucket.org:uabrandingdigitalassets/ua_featured_content.git

projects[ua_content_types][type] = module
projects[ua_content_types][subdir] = custom
projects[ua_content_types][directory_name] = ua_content_types
projects[ua_content_types][download][type] = git
projects[ua_content_types][download][branch] = 7.x-1.x
projects[ua_content_types][download][url] = git@bitbucket.org:uabrandingdigitalassets/cals-ua-features.git


; =====================================
; UA Themes
; =====================================

projects[ua_zen][type] = theme
projects[ua_zen][directory_name] = ua_zen
projects[ua_zen][download][type] = git
projects[ua_zen][download][branch] = 7.x-1.x
projects[ua_zen][download][url] = git@bitbucket.org:uabrandingdigitalassets/ua-zen.git
