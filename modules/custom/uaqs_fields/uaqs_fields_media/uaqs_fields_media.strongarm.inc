<?php
/**
 * @file
 * uaqs_fields_media.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uaqs_fields_media_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__image';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'preview' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'uaqs_small' => array(
        'custom_settings' => TRUE,
      ),
      'uaqs_medium' => array(
        'custom_settings' => TRUE,
      ),
      'uaqs_square' => array(
        'custom_settings' => TRUE,
      ),
      'uaqs_media_list' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'preview' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'file' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'uaqs_small' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'uaqs_medium' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'uaqs_square' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'uaqs_media_list' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__image'] = $strongarm;

  return $export;
}
