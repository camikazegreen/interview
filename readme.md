# UA Event #

## Overview ##
This repository contains a module made with [Features](https://www.drupal.org/project/features) that provides a UA Event content type.

## Requirements ##
- In order to use this feature, you must first download and enable the [Features](https://www.drupal.org/project/features) module. 
- Place the feature from this repository into your site's module folder and enable it as you would any other module.
- Dependencies:
  - Drupal Core modules
    - File
    - Image
    - List
    - Options
    - Text
  - Contributed modules
    - [Date](https://www.drupal.org/project/date) used for the event date
    - [Email](https://www.drupal.org/project/email) used for the contact email
    - [Field Collection](https://www.drupal.org/project/field_collection) used for the contact persons (includes fields Name, Email, and Phone)
    - [Link](https://www.drupal.org/project/link) used for the location and more information links

Handy Drush dl/en command:

```
#!

drush en date date_all_day date_api date_repeat date_repeat_field email field_collection link 
```
## Views ##
Coming soon. Hope to have a block and calendar display.