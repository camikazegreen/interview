<?php
/**
 * @file
 * ua_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ua_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'ua_page_body'.
  $field_bases['ua_page_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'ua_page_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  return $field_bases;
}
