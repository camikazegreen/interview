<?php

/**
 * @file
 * Add content to demonstrate the UA Featured Content feature.
 */

/**
 * Makes demonstration UA Carousel Item node content from pre-defined data.
 *
 * The field contents come from a JSON file.
 */
class UaDemoCarouselItemMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_carousel_item',
      t('Make demonstration UA Carousel Item node content from pre-defined data.'));

    // Documented lists of source data fields.
    // see ua_featured_content ua_featured_content.features.field_instance.inc
    // First, the node title field...
    $title_field = array(
      'title' => t('Headline'),
    );
    // The single-value text fields...
    $single_value_fields = array(
      'short_summary' => t('Short summary'),
      'call_to_action' => t('Call to action link'),
    );
    // Titles for links...
    $link_title_fields = array(
      'call_to_action_title' => t('Call to action link title'),
    );
    // Image fields...
    $image_src_field = 'slide_image';
    $image_fields = array(
      $image_src_field => t('Slide image'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $title_field + $single_value_fields + $link_title_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // The title has no prefix.
    $this->addSimpleMappings(array('title'));

    // One-to-one correspondence: JSON names and simple content type fields.
    foreach (array_keys($single_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Link titles.
    $this->addFieldMapping('field_call_to_action:title', 'call_to_action_title');

    // Images.
    $image_dst_field = 'field_' . $image_src_field;
    $this->addFieldMapping($image_dst_field, $image_src_field);
    $this->addFieldMapping($image_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping($image_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($image_dst_field . ':source_dir')
         ->defaultValue($this->imagePath());
  }

}
