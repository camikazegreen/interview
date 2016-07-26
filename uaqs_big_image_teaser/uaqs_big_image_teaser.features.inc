<?php
/**
 * @file
 * uaqs_big_image_teaser.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uaqs_big_image_teaser_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function uaqs_big_image_teaser_paragraphs_info() {
  $items = array(
    'uaqs_full_width_teaser' => array(
      'name' => 'Big Image Teaser',
      'bundle' => 'uaqs_full_width_teaser',
      'locked' => '1',
    ),
  );
  return $items;
}
