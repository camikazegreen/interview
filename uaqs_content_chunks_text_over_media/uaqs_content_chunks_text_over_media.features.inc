<?php
/**
 * @file
 * uaqs_content_chunks_text_over_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uaqs_content_chunks_text_over_media_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function uaqs_content_chunks_text_over_media_paragraphs_info() {
  $items = array(
    'uaqs_content_chunks_text_over_media' => array(
      'name' => 'Text over media',
      'bundle' => 'uaqs_content_chunks_text_over_media',
      'locked' => '1',
    ),
  );
  return $items;
}
