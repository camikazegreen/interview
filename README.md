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
    - [Automatic Node Titles](https://www.drupal.org/project/auto_nodetitle)
    - [Email](https://www.drupal.org/project/email) used for the email field
    - [Entity API](https://www.drupal.org/project/entity)
       - Entity Token (part of Entity API)
    - [Field Group](https://www.drupal.org/project/field_group) used to group profile information for layout reasons
    - [Token](https://www.drupal.org/project/token)
    - [Views](https://www.drupal.org/project/views)

Handy Drush dl/en command:

```
#!

drush en auto_nodetitle email entity entity_token field_group token views views_ui
```
## Automatically Generated Titles ##

### Why: ###
Drupal does not allow you to simply not fill in a node's title—it's necessary, but in a person content type it doesn't make much sense to have it. The Automatic Nodetitles module makes it possible to hide a node's title and populate it with the first and last name fields. Instead of having a content manager put in the person's full name (in the title field) and then redundantly fill in the first and last name, they only have to put in the person's first and last name. This also makes it easier for developers to make views of people which can be sorted by last or first name, or make URLs based on part of a name (e.g. mysite.com/people/macaulay).

### Tokens: ###
Entity Tokens is necessary because it provides tokens for generating the full name field. These tokens (with dashes, not underscores) translate apostrophes or any other type of special character (e.g. generates Taters O'Brian instead of Taters O&#039;Brian).

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