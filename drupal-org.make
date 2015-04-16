; Makefile for UA Brand Kickstart distribution
core = 7.x
api = 2

; =====================================
; UA Brand Modules
; =====================================

projects[ua_brand_core][type] = module
projects[ua_brand_core][subdir] = custom
projects[ua_brand_core][download][type] = git
projects[ua_brand_core][download][branch] = 7.x-1.x
projects[ua_brand_core][download][url] = git@bitbucket.org:joegraduate/ua_brand_core.git

projects[ua_brand_demo][type] = module
projects[ua_brand_demo][subdir] = custom
projects[ua_brand_demo][download][type] = git
projects[ua_brand_demo][download][branch] = 7.x-1.x
projects[ua_brand_demo][download][url] = git@bitbucket.org:joegraduate/ua_brand_demo.git

projects[ua_brand_navigation][type] = module
projects[ua_brand_navigation][subdir] = custom
projects[ua_brand_navigation][download][type] = git
projects[ua_brand_navigation][download][branch] = 7.x-1.x
projects[ua_brand_navigation][download][url] = git@bitbucket.org:joegraduate/ua_brand_navigation.git

projects[ua_featured_content][type] = module
projects[ua_featured_content][subdir] = custom
projects[ua_featured_content][download][type] = git
projects[ua_featured_content][download][branch] = makefile
projects[ua_featured_content][download][url] = git@bitbucket.org:uabrandingdigitalassets/ua_featured_content.git

projects[ua_content_types][type] = module
projects[ua_content_types][subdir] = custom
projects[ua_content_types][directory_name] = ua_content_types
projects[ua_content_types][download][type] = git
projects[ua_content_types][download][branch] = 7.x-1.x
projects[ua_content_types][download][url] = git@bitbucket.org:uabrandingdigitalassets/ua-features.git


; =====================================
; UA Brand Themes
; =====================================

projects[ua_zen][type] = theme
projects[ua_zen][subdir] = custom
projects[ua_zen][directory_name] = ua_zen
projects[ua_zen][download][type] = git
projects[ua_zen][download][branch] = 7.x-1.x
projects[ua_zen][download][url] = git@bitbucket.org:uabrandingdigitalassets/ua-zen.git
