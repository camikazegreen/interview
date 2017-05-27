<?php
/**
 * @file
 * uaqs_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uaqs_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "entity_embed" && $api == "default_entity_embed_configurations") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function uaqs_fields_image_default_styles() {
  $styles = array();

  // Exported image style: uaqs_card_image.
  $styles['uaqs_card_image'] = array(
    'label' => 'Card Image',
    'effects' => array(
      20 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 568,
          'height' => 426,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 1,
          'style_name' => 'uaqs_card_image',
        ),
        'weight' => 2,
      ),
      19 => array(
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

  // Exported image style: uaqs_large.
  $styles['uaqs_large'] = array(
    'label' => 'Large (scale to 1140px wide)',
    'effects' => array(
      14 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'uaqs_large',
        ),
        'weight' => -1,
      ),
      12 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: uaqs_marquee.
  $styles['uaqs_marquee'] = array(
    'label' => 'uaqs_marquee',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
      4 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1140,
          'height' => 502,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: uaqs_media_object.
  $styles['uaqs_media_object'] = array(
    'label' => 'Media object',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 64,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'uaqs_media_object',
        ),
        'weight' => -10,
      ),
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 64,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: uaqs_medium.
  $styles['uaqs_medium'] = array(
    'label' => 'Medium (scale to 760px wide)',
    'effects' => array(
      17 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 760,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'uaqs_medium',
        ),
        'weight' => 0,
      ),
      18 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 760,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: uaqs_medium_square.
  $styles['uaqs_medium_square'] = array(
    'label' => 'Medium Square (220x220)',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'uaqs_medium_square',
        ),
        'weight' => -11,
      ),
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: uaqs_small.
  $styles['uaqs_small'] = array(
    'label' => 'Small (scale to 380px wide)',
    'effects' => array(
      15 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 380,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'uaqs_small',
        ),
        'weight' => 0,
      ),
      16 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 380,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
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
