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

  return $styles;
}
