<?php
/**
 * @file
 * ua_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ua_event_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ua_event_image_default_styles() {
  $styles = array();

  // Exported image style: ua_fixed_banner_460.
  $styles['ua_fixed_banner_460'] = array(
    'label' => 'Fixed banner 460',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 460,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

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
