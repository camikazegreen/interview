<?php
/**
 * @file
 * ua_publication.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_publication_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ua_publication_node_info() {
  $items = array(
    'ua_pub' => array(
      'name' => t('UA Publication'),
      'base' => 'node_content',
      'description' => t('Use a <em>UA publication</em> to add published works to the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
