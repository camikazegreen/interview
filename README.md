# UAQS Fields Module

Modules in different parts of the UA QuickStart Drupal distribution share some common fields; for example, `field_uaqs_lname` will turn up in most places where the last name of a person is required. Drupal allows copies of fields to appear in many different places (field instances), but all the copies must share a common definition (the field base). If the shared field bases turn up in arbitrary modules there will be subtle problems (disabling a module may break seemingly unrelated parts of a web site), so the UAQS Fields module provides a single well-defined place where the field base definitions can find a home. Modules may still provide their own field base definitions for fields that nothing else is using, but the set of common field bases should be here. Other definitions that should also be common to several different modules also reside here.

The Drupal 7 Core [Filter](https://www.drupal.org/documentation/modules/filter) module provides extensible text formats, which specify the restrictions and transformations that apply to content placed in some fields (for example disallowing some HTML elements, or transforming text between line breaks into P elements). The UAQS Fields Module defines some text formats in addition to the Core defaults, and associates these with its field definitions. Drupal Core does not provide everything necessary for field-specific formats, so it includes additional code lifted from the [Better Formats](https://www.drupal.org/project/better_formats) contributed module, but omits both its friendly GUI and database overheads.

Within the UAQS modules, the contributed [Editor](https://www.drupal.org/project/editor) module is the preferred choice for allowing content creators to edit content through a WYSIWYG interface. It has a close association with text formats: if a field is to appear within the editor GUI for manipulation, the Editor module stores the interface configurations directly within the text formats that apply to that field, so the UAQS Fields module pre-configures its formats with the extra Editor data.

Field base definitions appear in the expected place (for something using the Features module), at `uaqs_fields.features.field_base.inc`, and anyone wanting to extend UAQS Fields should be able to define new base definitions there. Format definitions are in their own file, `uaqs_fields.features.filter.inc`, but there are some points to watch when extending this with new formats. The definitions themselves are simple (each definition is an array, and these are in turn the values keyed by labels, which generally match the machine name, within a single array gathering all the definitions together) but they include the extra `'editor' => 'ckeditor'` and long `editor_settings` data specific to the Editor module. The built-in PHP serialize() function produces the long `editor_settings` strings from nested arrays defining the GUI configuration, and these are difficult to modify by hand. The uaqs_fields_using_format() function in the `uaqs_fields.module` file defines the association between default formats and fields, and extra associations can be set up by modifying it. A content creator needs explicit permissions to actually use the additional formats, and the uaqs_fields_defaultconfig_user_default_permissions() function in `uaqs_fields.features.defaultconfig.inc` makes a start by setting these for the administrator at least. Additional roles require further permissions, and each additional format requires its own set of permissions for all the roles that will need it. The field bases, filters and formats also need specified in the module's .info file, `uaqs_fields.info`.

## Packaged Dependencies

This module provides core dependencies and features for the [UA Quickstart](https://bitbucket.org/ua_drupal/ua_quickstart) Drupal Distribution (or any other distributions wishing to make use of it), and itself automatically packages the following dependencies.

### Drupal Contrib Modules

#### Common Contrib Module Dependencies
- [Dialog](https://www.drupal.org/project/dialog)
- [Editor](https://www.drupal.org/project/editor)
- [Fences](https://www.drupal.org/project/fences)
- [Telephone](https://www.drupal.org/project/telephone)

#### Addon libraries for CKEditor
- [Autogrow](http://ckeditor.com/addon/autogrow)
