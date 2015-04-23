<?php
/**
 * @file
 * ua_person.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ua_person_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ua_person_image_default_styles() {
  $styles = array();

  // Exported image style: ua_medium_square.
  $styles['ua_medium_square'] = array(
    'label' => 'Medium Square (220x220)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
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
function ua_person_node_info() {
  $items = array(
    'ua_person' => array(
      'name' => t('UA Person'),
      'base' => 'node_content',
      'description' => t('Use a <em>person</em> to add to a personnel directory.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
