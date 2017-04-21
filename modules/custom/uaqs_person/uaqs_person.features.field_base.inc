<?php
/**
 * @file
 * uaqs_person.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function uaqs_person_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_uaqs_person_category'.
  $field_bases['field_uaqs_person_category'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_uaqs_person_category',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'uaqs_person_category',
          'parent' => 0,
        ),
      ),
      'options_list_callback' => 'title_taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
