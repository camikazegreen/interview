<?php
/**
 * @file
 * ua_featured_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_featured_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ua_featured_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ua_featured_content_node_info() {
  $items = array(
    'featured_content' => array(
      'name' => t('Featured Content'),
      'base' => 'node_content',
      'description' => t('Place items into the Featured Content slideshow on the front page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
