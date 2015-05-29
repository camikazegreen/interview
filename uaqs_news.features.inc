<?php
/**
 * @file
 * ua_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ua_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ua_news_node_info() {
  $items = array(
    'ua_news' => array(
      'name' => t('UA News'),
      'base' => 'node_content',
      'description' => t('Use <em>news</em> to add news articles to the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
