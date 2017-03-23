<?php
/**
 * @file
 * uaqs_person.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uaqs_person_defaultconfig_features() {
  return array(
    'uaqs_person' => array(
      'field_default_fields' => 'field_default_fields',
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function uaqs_person_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'node-uaqs_person-title_field'.
  $fields['node-uaqs_person-title_field'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'title_field',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 1,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'uaqs_person',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'title',
          'settings' => array(
            'field_multiple_limit' => -1,
            'field_multiple_limit_offset' => 0,
            'field_multiple_limit_order' => 0,
            'title_class' => 'margin-align-top margin-zero-bottom',
            'title_link' => '',
            'title_style' => 'h2',
          ),
          'type' => 'title_linked',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'title',
          'settings' => array(
            'field_multiple_limit' => -1,
            'field_multiple_limit_offset' => 0,
            'field_multiple_limit_order' => 0,
            'title_class' => 'margin-zero-top margin-zero-bottom',
            'title_link' => '',
            'title_style' => 'h2',
          ),
          'type' => 'title_linked',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'title',
          'settings' => array(
            'field_multiple_limit' => -1,
            'field_multiple_limit_offset' => 0,
            'field_multiple_limit_order' => 0,
            'title_class' => '',
            'title_link' => 'content',
            'title_style' => 'h4',
          ),
          'type' => 'title_linked',
          'weight' => 0,
        ),
        'uaqs_card' => array(
          'label' => 'hidden',
          'module' => 'title',
          'settings' => array(
            'field_multiple_limit' => -1,
            'field_multiple_limit_offset' => 0,
            'field_multiple_limit_order' => 0,
            'title_class' => 'card-title',
            'title_link' => 'content',
            'title_style' => 'h4',
          ),
          'type' => 'title_linked',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'node',
      'fences_wrapper' => 'no_wrapper',
      'field_name' => 'title_field',
      'label' => 'Title',
      'required' => 1,
      'settings' => array(
        'hide_label' => array(
          'entity' => 'entity',
          'page' => 'page',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => -5,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Title');

  return $fields;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function uaqs_person_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_uaqs_person';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_uaqs_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_uaqs_person';
  $strongarm->value = '[node:field-uaqs-fname] [node:field-uaqs-lname]';
  $export['auto_entitylabel_pattern_node_uaqs_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_uaqs_person';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_uaqs_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__uaqs_person';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
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
      'uaqs_card' => array(
        'custom_settings' => TRUE,
      ),
      'uaqs_featured_content' => array(
        'custom_settings' => FALSE,
      ),
      'uaqs_teaser_list' => array(
        'custom_settings' => FALSE,
      ),
      'uaqs_sidebar_teaser_list' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__uaqs_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_uaqs_person';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_uaqs_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_uaqs_person';
  $strongarm->value = '1';
  $export['node_preview_uaqs_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_uaqs_person';
  $strongarm->value = 0;
  $export['node_submitted_uaqs_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_uaqs_person_pattern';
  $strongarm->value = 'person/[node:title]';
  $export['pathauto_node_uaqs_person_pattern'] = $strongarm;

  return $export;
}
