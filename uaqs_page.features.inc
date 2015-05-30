<?php
/**
 * @file
 * ua_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ua_page_node_info() {
  $items = array(
    'ua_page' => array(
      'name' => t('UA Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
