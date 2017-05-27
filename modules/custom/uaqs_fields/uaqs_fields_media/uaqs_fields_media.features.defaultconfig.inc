<?php
/**
 * @file
 * uaqs_fields_media.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uaqs_fields_media_defaultconfig_features() {
  return array(
    'uaqs_fields_media' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function uaqs_fields_media_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'manualcrop_file_entity_settings_image';
  $strongarm->value = array(
    'manualcrop_enable' => 1,
    'manualcrop_keyboard' => 1,
    'manualcrop_thumblist' => 1,
    'manualcrop_inline_crop' => 0,
    'manualcrop_crop_info' => 1,
    'manualcrop_instant_preview' => 1,
    'manualcrop_instant_crop' => 0,
    'manualcrop_default_crop_area' => 1,
    'manualcrop_maximize_default_crop_area' => 0,
    'manualcrop_styles_mode' => 'include',
    'manualcrop_styles_list' => array(
      'uaqs_card_image' => 'uaqs_card_image',
      'uaqs_large' => 'uaqs_large',
      'uaqs_media_object' => 'uaqs_media_object',
      'uaqs_medium' => 'uaqs_medium',
      'uaqs_medium_square' => 'uaqs_medium_square',
      'uaqs_small' => 'uaqs_small',
    ),
    'manualcrop_require_cropping' => array(),
  );
  $export['manualcrop_file_entity_settings_image'] = $strongarm;

  return $export;
}
