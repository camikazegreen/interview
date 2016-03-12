<?php
/**
 * @file
 * uaqs_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uaqs_fields_user_default_permissions() {
  $permissions = array();

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
