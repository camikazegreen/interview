<?php
/**
 * @file
 * ua_program.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_program_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ua_program_node_info() {
  $items = array(
    'ua_program' => array(
      'name' => t('UA Program'),
      'base' => 'node_content',
      'description' => t('Use a <em>UA program</em> to add academic UA programs to the website.'),
      'has_title' => '1',
      'title_label' => t('Program Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
