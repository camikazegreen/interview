<?php
/**
 * @file
 * ua_content_chunks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_content_chunks_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ua_content_chunks_node_info() {
  $items = array(
    'ua_main_page' => array(
      'name' => t('UA Main Page'),
      'base' => 'node_content',
      'description' => t('The preferred way to add basic content to a UA web site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function ua_content_chunks_paragraphs_info() {
  $items = array(
    'ua_column_image' => array(
      'name' => 'UA Column Image',
      'bundle' => 'ua_column_image',
      'locked' => '1',
    ),
    'ua_file_download' => array(
      'name' => 'UA File Download',
      'bundle' => 'ua_file_download',
      'locked' => '1',
    ),
    'ua_headed_text' => array(
      'name' => 'UA Headed Text',
      'bundle' => 'ua_headed_text',
      'locked' => '1',
    ),
    'ua_plain_text' => array(
      'name' => 'UA Plain Text',
      'bundle' => 'ua_plain_text',
      'locked' => '1',
    ),
  );
  return $items;
}
