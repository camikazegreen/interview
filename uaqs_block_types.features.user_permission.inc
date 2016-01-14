<?php
/**
 * @file
 * ua_block_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ua_block_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any ua_captioned_image bean'.
  $permissions['view any ua_captioned_image bean'] = array(
    'name' => 'view any ua_captioned_image bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any ua_contact_summary bean'.
  $permissions['view any ua_contact_summary bean'] = array(
    'name' => 'view any ua_contact_summary bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any ua_illustrated_blurb bean'.
  $permissions['view any ua_illustrated_blurb bean'] = array(
    'name' => 'view any ua_illustrated_blurb bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any ua_illustrated_link bean'.
  $permissions['view any ua_illustrated_link bean'] = array(
    'name' => 'view any ua_illustrated_link bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any ua_mini_blurb bean'.
  $permissions['view any ua_mini_blurb bean'] = array(
    'name' => 'view any ua_mini_blurb bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any ua_card bean'.
  $permissions['view any ua_card bean'] = array(
    'name' => 'view any ua_card bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );
  
  return $permissions;
}
