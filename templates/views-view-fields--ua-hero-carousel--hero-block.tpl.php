<?php

/**
 * @file
 * Overrides views-views-fields.tpl.php for UA Hero Carousel block display.
 *
 * @todo Move this into a template for a custom view mode instead?
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>

<?php if (isset($fields["field_call_to_action_1"]->content)): ?>
<a href="<?php print $fields["field_call_to_action_1"]->content; ?>">
<?php else : ?>
<a href="<?php print $fields["path"]->content; ?>">
<?php endif; ?>
  <div class="slide-image-container container" style="background-image: url('<?php print $fields["field_slide_image"]->content; ?>')">
    <div class="container">
      <div class="mask white">
        <?php print $fields["title"]->content; ?>
        <?php print $fields["body"]->content; ?>
        <?php if (isset($fields["field_call_to_action"]->content)): ?>
        <?php print $fields["field_call_to_action"]->content; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</a>
