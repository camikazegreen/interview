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
 * Implements hook_flag_default_flags().
 */
function ua_featured_content_flag_default_flags() {
  $flags = array();
  // Exported flag: "ua_hero_carousel".
  $flags['ua_hero_carousel'] = array(
    'entity_type' => 'node',
    'title' => 'ua_hero_carousel',
    'global' => 1,
    'types' => array(
      0 => 'ua_carousel_item',
    ),
    'flag_short' => 'Add to UA Hero Carousel',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove from UA Hero Carousel',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'ua_featured_content' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'ua_featured_content',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function ua_featured_content_node_info() {
  $items = array(
    'ua_carousel_item' => array(
      'name' => t('Carousel Item'),
      'base' => 'node_content',
      'description' => t('Use <em>carousel items</em> to prominently feature links to content on the front page.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
