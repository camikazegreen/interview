<?php
/**
 * @file
 * uaqs_block_types_mini_blurb.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function uaqs_block_types_mini_blurb_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-uaqs_mini_blurb-field_uaqs_text_area'.
  $field_instances['bean-uaqs_mini_blurb-field_uaqs_text_area'] = array(
    'bundle' => 'uaqs_mini_blurb',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Short piece of text (only one or two paragraphs).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_uaqs_text_area',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Short piece of text (only one or two paragraphs).');
  t('Text');

  return $field_instances;
}
