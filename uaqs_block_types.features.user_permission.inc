<?php
/**
 * @file
 * uaqs_block_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uaqs_block_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any uaqs_captioned_image bean'.
  $permissions['view any uaqs_captioned_image bean'] = array(
    'name' => 'view any uaqs_captioned_image bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any uaqs_contact_summary bean'.
  $permissions['view any uaqs_contact_summary bean'] = array(
    'name' => 'view any uaqs_contact_summary bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any uaqs_illustrated_blurb bean'.
  $permissions['view any uaqs_illustrated_blurb bean'] = array(
    'name' => 'view any uaqs_illustrated_blurb bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any uaqs_illustrated_link bean'.
  $permissions['view any uaqs_illustrated_link bean'] = array(
    'name' => 'view any uaqs_illustrated_link bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any uaqs_mini_blurb bean'.
  $permissions['view any uaqs_mini_blurb bean'] = array(
    'name' => 'view any uaqs_mini_blurb bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any uaqs_statement bean'.
  $permissions['view any uaqs_statement bean'] = array(
    'name' => 'view any uaqs_statement bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
