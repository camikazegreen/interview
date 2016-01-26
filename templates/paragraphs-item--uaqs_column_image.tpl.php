<?php
/**
 * @file
 * Display an UAQS Column Image as an HTML5 figure.
 *
 * Available variables:
 * - $content: An associative array of fields ready for rendering
 *   - field_uaqs_caption_text: Image caption.
 *   - field_uaqs_image_credit: Image credit information.
 *   - field_uaqs_image_wide: The image itself.
 * - $classes: A string containing CSS classes for the figure.
 * - $attributes: A string containing HTML attributes for the figure.
 * Inject minimally rendered fields into the template HTML.
 *
 * @see paragraphs-item.tpl.php
 */

?>
<figure class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_uaqs_image_wide']); ?>
  <?php if ($content['have_figcaption']): ?>
    <figcaption>
      <?php if ($content['have_credit']): ?>
        <small>
          <?php print render($content['field_uaqs_image_credit']); ?>
        </small>
        <?php if ($content['have_caption']): ?>
          |
        <?php endif; ?>
      <?php endif; ?>
      <?php print render($content['field_uaqs_caption_text']); ?>
    </figcaption>
  <?php endif; ?>
</figure>
