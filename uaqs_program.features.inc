<?php
/**
 * @file
 * uaqs_program.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uaqs_program_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uaqs_program_node_info() {
  $items = array(
    'uaqs_program' => array(
      'name' => t('UAQS Program'),
      'base' => 'node_content',
      'description' => t('Use a <em>UAQS Program</em> to add academic UAQS Programs to the website.'),
      'has_title' => '1',
      'title_label' => t('Program Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
