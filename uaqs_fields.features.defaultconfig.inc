<?php
/**
 * @file
 * uaqs_fields.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uaqs_fields_defaultconfig_features() {
  return array(
    'uaqs_fields' => array(
      'strongarm' => 'strongarm',
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function uaqs_fields_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fences_default_classes';
  $strongarm->value = 1;
  $export['fences_default_classes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fences_default_markup';
  $strongarm->value = 1;
  $export['fences_default_markup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'title_bean';
  $strongarm->value = array(
    'auto_attach' => array(
      'title' => 'title',
    ),
    'hide_label' => array(
      'page' => 'page',
      'entity' => 'entity',
    ),
  );
  $export['title_bean'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'title_node';
  $strongarm->value = array(
    'auto_attach' => array(
      'title' => 0,
    ),
    'hide_label' => array(
      'page' => 0,
      'entity' => 0,
    ),
  );
  $export['title_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'title_taxonomy_term';
  $strongarm->value = array(
    'auto_attach' => array(
      'name' => 0,
      'description' => 0,
    ),
    'hide_label' => array(
      'page' => 0,
      'entity' => 0,
    ),
  );
  $export['title_taxonomy_term'] = $strongarm;

  return $export;
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function uaqs_fields_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format uaqs_filtered_html'.
  $permissions['use text format uaqs_filtered_html'] = array(
    'name' => 'use text format uaqs_filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format uaqs_full_html'.
  $permissions['use text format uaqs_full_html'] = array(
    'name' => 'use text format uaqs_full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format uaqs_standard'.
  $permissions['use text format uaqs_standard'] = array(
    'name' => 'use text format uaqs_standard',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format uaqs_textual_content'.
  $permissions['use text format uaqs_textual_content'] = array(
    'name' => 'use text format uaqs_textual_content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format uaqs_unconstrained'.
  $permissions['use text format uaqs_unconstrained'] = array(
    'name' => 'use text format uaqs_unconstrained',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
