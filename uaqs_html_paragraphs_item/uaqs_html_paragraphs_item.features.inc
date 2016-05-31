<?php
/**
 * @file
 * uaqs_body_paragraphs_item.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function uaqs_html_paragraphs_item_paragraphs_info() {
  $items = array(
    'uaqs_html_paragraphs_item' => array(
      'name' => 'HTML Field',
      'bundle' => 'uaqs_html_paragraphs_item',
      'locked' => '1',
    ),
  );
  return $items;
}
