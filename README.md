# UA News #

## Overview ##
This repository contains a module made with [Features](https://www.drupal.org/project/features) that provides a UA News content type.

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
    - [Date](https://www.drupal.org/project/date) used for the article's publishing date and expiration date
    - [Email](https://www.drupal.org/project/email) used for the contact email
    - [Field Collection](https://www.drupal.org/project/field_collection) used for the contact persons (includes fields Name, Email, and Phone)
    - [Link](https://www.drupal.org/project/link) used for the more information link
    - [Strongarm](https://www.drupal.org/project/strongarm) used maintain content type settings

Handy Drush dl/en command:

```
#!

drush en date date_api email field_collection link strongarm
```
## Views ##

There are two views: a spotlight block with a list of 3 news items and a full page view.

### Structure ###

Included fields:

- News Photo (block and page)
- News title (block and page)
- News published date (block and page - several different formats used)
- News summary (page only)

### Styling ###
To facilitate styling, the view displays have classes added to them via the Views UI.

#### Styling classes are as follows: ####

- **Full Page class:** *ua-news-page*
- **Block class:** *ua-news-spotlight*
- **Row class:** *ua-news-row*
- **Field Classes (block):**
    - Photo  *ua-news-photo*
    - Title  *ua-news-title*
    - Published date  *ua-news-published*
    - Summary  *ua-news-summary*