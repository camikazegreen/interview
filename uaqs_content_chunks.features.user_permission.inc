<?php
/**
 * @file
 * ua_content_chunks.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ua_content_chunks_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format ua_phrasing_content'.
  $permissions['use text format ua_phrasing_content'] = array(
    'name' => 'use text format ua_phrasing_content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
