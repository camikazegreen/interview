<?php
/**
 * @file
 * uaqs_content_chunks_html.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function uaqs_content_chunks_html_paragraphs_info() {
  $items = array(
    'uaqs_content_chunks_html' => array(
      'name' => 'HTML Field',
      'bundle' => 'uaqs_content_chunks_html',
      'locked' => '1',
    ),
  );
  return $items;
}
