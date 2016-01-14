<?php
/**
 * @file
 * ua_block_types.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function ua_block_types_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'ua_captioned_image';
  $bean_type->label = 'UA Captioned Image';
  $bean_type->options = '';
  $bean_type->description = 'An image with caption and photo credit.';
  $export['ua_captioned_image'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'ua_card';
  $bean_type->label = 'UA Card';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['ua_card'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'ua_contact_summary';
  $bean_type->label = 'UA Contact Summary';
  $bean_type->options = '';
  $bean_type->description = 'Summary contact information, for example a departmental postal address, generic email address, and main office phone number.';
  $export['ua_contact_summary'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'ua_illustrated_blurb';
  $bean_type->label = 'UA Illustrated Blurb';
  $bean_type->options = '';
  $bean_type->description = 'A short piece of text associated with an image, heading, and link to more information.';
  $export['ua_illustrated_blurb'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'ua_illustrated_link';
  $bean_type->label = 'UA Illustrated Link';
  $bean_type->options = '';
  $bean_type->description = 'Extends the normal Link field with a small image.';
  $export['ua_illustrated_link'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'ua_mini_blurb';
  $bean_type->label = 'UA Mini Blurb';
  $bean_type->options = '';
  $bean_type->description = 'Short text with a heading.';
  $export['ua_mini_blurb'] = $bean_type;

  return $export;
}
