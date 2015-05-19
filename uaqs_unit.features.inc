<?php
/**
 * @file
 * ua_unit.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_unit_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ua_unit_node_info() {
  $items = array(
    'ua_unit' => array(
      'name' => t('UA Unit'),
      'base' => 'node_content',
      'description' => t('Use a <em>unit</em> to create information about an academic unit.'),
      'has_title' => '1',
      'title_label' => t('Unit Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
