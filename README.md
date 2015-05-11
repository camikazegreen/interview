# UA Person #

## Overview ##
This repository contains a module made with [Features](https://www.drupal.org/project/features) that provides a UA Person content type and a simple view display for a profile directory.

## Requirements ##
- In order to use this feature, you must first download and enable the [Features](https://www.drupal.org/project/features) module. 
- Place the feature from this repository into your site's module folder and enable it as you would any other module.
- Dependencies:
  - Drupal Core modules
    - Image
    - Text
  - Contributed modules
    - [Email](https://www.drupal.org/project/email) used for the email field
    - [Field Group](https://www.drupal.org/project/field_group) used to group profile information for layout reasons
    - [Views](https://www.drupal.org/project/views)

Handy Drush dl/en command:

```
#!

drush en email field_group views views_ui
```
## Notes on automatically generating the Full Name field with the first and last name fields ##

### Modules needed: ###
- [Automatic Node Titles](https://www.drupal.org/project/auto_nodetitle)
- [Token](https://www.drupal.org/project/token)
- [Entity API](https://www.drupal.org/project/entity)
  - Entity Token (part of Entity API)

### Process: ###
Once the modules are enabled, in the content type's settings there will be a new set of options for Automatic Title Generation. It's advisable to check "Automatically generate 

the title and hide the title field" and then fill in the pattern for the title with the tokens for the first name and last name fields.

#### Tokens: ####
```
#!
[node:field-ua-person-fname] [node:field-ua-person-lname]
```
*Note:* Once you enable Entity Tokens, you are given two different types of tokens for each field. To make sure apostrophes or any other type of special character get 

translated, use the token with the dashes, not the underscores (e.g. Taters O'Brian will become <Taters O&#039;Brian> if the underscore tokens are used).

## Views ##

### Structure ###
The view included is modeled after a wireframe mockup provided by Student Affairs Marketing (image below).
Included fields:
- Photo (124px x 124px)
- Full name
- Job title(s)
- Email
- Phone number(s)
![persons-view.png](https://bitbucket.org/repo/qyrqzr/images/288845954-persons-view.png)

### Styling ###
The view display for the persons content type has classes added to it through the Views UI to facilitate styling.

Styling classes are as follows:

- **Main View class:** *ua-people-grid* (I used the word "grid" because this display will show persons 3-across on large screens, 2-across on medium screens and 1-across on smallest screens)
- **Row class:** *ua-people-row*
- **Field Classes:**
    - Photo  *ua-person-photo*
    - Full name  *ua-person-name*
    - Job title(s)  *ua-person-job-titles*
    - Email  *ua-person-email*
    - Phone number(s)  *ua-person-phone*