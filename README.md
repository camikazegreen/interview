# UA Person #

## Overview ##
This repository contains a module made with [Features](https://www.drupal.org/project/features) that provides a UA Person content type and a simple view display for a profile directory.

## Requirements ##
*In order to use this feature, you must first download and enable the [Features](https://www.drupal.org/project/features) module. 
*Place the feature from this repository into your site's module folder and enable it as you would any other module.
*Dependencies:
**Drupal Core modules
***Image
***Text
**Contributed modules
***[Automatic Nodetitles](https://www.drupal.org/project/auto_nodetitle) - used to hide the node title field and automatically populate it with the person's first and last name
***[Email](https://www.drupal.org/project/email) - used for the email field
***[Entity API](https://www.drupal.org/project/entity) - assists in the translation of special characters in names
***[Token](https://www.drupal.org/project/token) - provides tokens to generate the node title
***[Views](https://www.drupal.org/project/views)

Handy Drush dl/en command:

```
#!

drush en auto_nodetitle email entity token views
```