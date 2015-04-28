<?php
/**
 * @file
 * ua_event.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ua_event_node_info() {
  $items = array(
    'ua_event' => array(
      'name' => t('UA Event'),
      'base' => 'node_content',
      'description' => t('Use an <em>event</em> to add events to the site\'s event displays.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
