<?php
/**
 * @file
 * ua_program.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ua_program_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ua_program-field_ua_program_focus_areas'.
  $field_instances['node-ua_program-field_ua_program_focus_areas'] = array(
    'bundle' => 'ua_program',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ua_program_focus_areas',
    'label' => 'Focus Areas',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Focus Areas');

  return $field_instances;
}
