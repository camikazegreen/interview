<?php
/**
 * @file
 * Display UA Headed Text.
 *
 * Available variables:
 * - $content: An associative array of fields ready for rendering
 *   - field_ua_text_area: One paragraph of text.
 *   - field_ua_text_heading: The associated heading.
 * - $classes: A string containing CSS classes for the download.
 * - $attributes: A string containing HTML attributes for the download.
 * Unlike most paragraph-items from Paragraphs, this actually marks up
 * the text with <p></p>.
 *
 * @see paragraphs-item.tpl.php
 */

?>
<h3>
  <?php print render($content['field_ua_text_heading']); ?>
</h3>
<p class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($content['field_ua_text_area']); ?>
</p>
