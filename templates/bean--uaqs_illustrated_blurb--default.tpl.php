<?php
/**
 * @file
 * Display simplified UA Illustrated Blurb content.
 *
 * Available variables:
 * - $content: An associative array of fields ready for rendering
 *   - field_ua_blurb_text: One or two paragraphs of text.
 *   - field_ua_read_more: A link to further relevant content.
 *   - field_ua_supporting_image: A decorative or supplementary image.
 * - $classes: A string containing CSS classes for the outer wrapper.
 * - $attributes: A string containing HTML attributes for the outer wrapper.
 * - $content_attributes: A string containing HTML attributes for the inner
 *   wrapper.
 *
 * This generates less markup than the default Bean template, adding few
 * wrappers and relying on some minimalist field renderings.
 *
 * @see bean.tpl.php
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_ua_supporting_image']); ?>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      print render($content['field_ua_blurb_text']);
      print render($content['field_ua_read_more']);
    ?>
  </div>
</div>
