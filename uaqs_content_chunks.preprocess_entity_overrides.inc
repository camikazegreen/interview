<?php
/**
 * @file
 * Overrides for template_preprocess_entity().
 *
 * Manipulate the variables for the content chunk type before rendering.
 */

/**
 * Insert variables into the UA Column Image template.
 *
 * @param array &$variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The hook name (generally the block type name).
 */
function ua_content_chunks_preprocess_entity_paragraphs_item_ua_column_image(array &$variables, $hook) {
  $have_caption = !empty($variables['content']['field_ua_caption_text']);
  $have_credit = !empty($variables['content']['field_ua_image_credit']);
  $have_figcaption = ($have_caption || $have_credit);

  $variables['content']['have_caption'] = $have_caption;
  $variables['content']['have_credit'] = $have_credit;
  $variables['content']['have_figcaption'] = $have_figcaption;
}
