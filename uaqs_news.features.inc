<?php
/**
 * @file
 * ua_news.features.inc
 */

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
