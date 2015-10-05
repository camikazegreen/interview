<?php
/**
 * @file
 * Display an UA File Download.
 *
 * Available variables:
 * - $content: An associative array of fields ready for rendering
 *   - field_ua_download_description: General discription of the file.
 *   - field_ua_download_file: Image Actual download link.
 *   - field_ua_download_name: A short title for the download.
 *   - filed_ua_download_preview_image: Preview image or file type icon.
 * - $classes: A string containing CSS classes for the download.
 * - $attributes: A string containing HTML attributes for the downloadZ.
 * Inject minimally rendered fields into the template HTML.
 *
 * @see paragraphs-item.tpl.php
 */

?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <h3>
    <?php print render($content['field_ua_download_name']); ?>
  </h3>
  <?php
    print render($content['field_ua_download_preview_image']);
    print render($content['field_ua_download_file']);
  ?>
  <?php if (!empty($content['field_ua_download_description'])): ?>
    <p>
      <?php print render($content['field_ua_download_description']); ?>
    </p>
  <?php endif; ?>
</div>
