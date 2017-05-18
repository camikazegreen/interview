<?php
/**
 * @file
 * uaqs_fields.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function uaqs_fields_image_default_styles() {
  $styles = array();

  // Exported image style: uaqs_card_image.
  $styles['uaqs_card_image'] = array(
    'label' => 'Card Image',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 568,
          'height' => 426,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: uaqs_fixed_banner_460.
  $styles['uaqs_fixed_banner_460'] = array(
    'label' => 'Fixed banner 460',
    'effects' => array(
      1 => array(
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

  // Exported image style: uaqs_fixed_width.
  $styles['uaqs_fixed_width'] = array(
    'label' => 'Fixed width',
    'effects' => array(
      0 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 768,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: uaqs_medium_square.
  $styles['uaqs_medium_square'] = array(
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

  // Exported image style: uaqs_spotlight.
  $styles['uaqs_spotlight'] = array(
    'label' => 'Spotlight',
    'effects' => array(
      0 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 365,
          'height' => 196,
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}
