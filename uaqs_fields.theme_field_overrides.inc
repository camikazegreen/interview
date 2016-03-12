<?php
/**
 * @file
 * Overrides for theme_field() (the default Field API rendering function).
 *
 * The default rendering of field labels and values places them within nested
 * sets of div elements, which add to the overall complexity of the markup,
 * and make theming more difficult. The overrides for the Field API's default
 * theme_field() function help the UA Zen theme render fields appropriately.
 */

/**
 * Returns HTML for a field, concatenating values (helper function).
 *
 * Provides a extremely simplified rendering of a field, concatenating values
 * with neither the label nor the enclosing wrapper elements.
 *
 * @param array $variables
 *   An associative array containing:
 *   - items: The array of field values to render.
 *
 * @return string
 *   The rendered field.
 */
function render_unadorned_values(array $variables) {
  // Field value: possibly multiple items to concatenate inline.
  $items = array();
  foreach ($variables['items'] as $delta => $item) {
    $items[] = drupal_render($item);
  }
  return implode($items);
}

/**
 * Returns HTML for a uaqs_text_area field.
 *
 * @param array $variables
 *   The usual field associative array for rendering.
 *
 * @return string
 *   The rendered field.
 */
function ua_zen_field__field_uaqs_text_area(array $variables) {
  return render_unadorned_values($variables);
}

