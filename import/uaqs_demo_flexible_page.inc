<?php

/**
 * @file
 * Add content to demonstrate the UA Flexible Page feature.
 *
 * The main contributed Migrate module does not support the Paragraphs-based
 * entities that are the main point of a UA Flexible Page, but the Paragraphs
 * module itself includes Migrate support.
 *
 * @see https://www.drupal.org/node/2271181
 */

/**
 * Defines migration into the UA Plain Text type of Paragraphs entity.
 */
class UaDemoPlainTextMigration extends UaDemoParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_plain_text', 'field_ua_main_content',
      t('Populate demonstration UA Plain Text entities (based on Paragraphs).'));

    // Fields to import to the bundle.
    $data_fields = array(
      'ua_text_area' => t('Generic multi-line text area'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_ua_text_area', 'ua_text_area');
    // Allow limited HTML markup in the text area field.
    $this->addFieldMapping('field_ua_text_area:format')
         ->defaultValue('ua_phrasing_content');
  }

}

/**
 * Defines migration into the UA Headed Text type of Paragraphs entity.
 */
class UaDemoHeadedTextMigration extends UaDemoParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_headed_text', 'field_ua_main_content',
      t('Populate demonstration UA Headed Text entities (based on Paragraphs).'));

    // Fields to import to the bundle.
    $data_fields = array(
      'ua_text_heading' => t('Heading for the following text'),
      'ua_text_area' => t('Generic multi-line text area'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_ua_text_heading', 'ua_text_heading');
    $this->addFieldMapping('field_ua_text_area', 'ua_text_area');
    // Allow limited HTML markup in the text area field.
    $this->addFieldMapping('field_ua_text_area:format')
         ->defaultValue('ua_phrasing_content');
  }

}

/**
 * Defines migration into the UA Column Image type of Paragraphs entity.
 */
class UaDemoColumnImageMigration extends UaDemoParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_column_image', 'field_ua_main_content',
      t('Populate demonstration UA Column Image entities (based on Paragraphs).'));

    // Fields to import to the bundle.
    $data_fields = array(
      'ua_caption_text' => t('Image caption'),
      'ua_image_credit' => t('Image source or copyright holder'),
    );
    // Image fields...
    $image_src_field = 'ua_image_wide';
    $image_fields = array(
      $image_src_field => t('Image to place in content'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_ua_caption_text', 'ua_caption_text');
    $this->addFieldMapping('field_ua_image_credit', 'ua_image_credit');
    // Images.
    $image_dst_field = 'field_' . $image_src_field;
    $this->addFieldMapping($image_dst_field, $image_src_field)
         ->separator('|');
    $this->addFieldMapping($image_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping($image_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($image_dst_field . ':source_dir')
         ->defaultValue($this->imagePath());
  }

}

/**
 * Makes demonstration UA Flexible Page content from pre-defined data.
 *
 * This migration imports a small part of the UA FlexiblePage content directly
 * from a JSON file, but most of it is encapsulated in a series of entities
 * from the Paragraphs module, which get their own migrations (see above).
 */
class UaDemoFlexiblePageMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_flexible_page',
      t('Make demonstration UA Flexible Page content from pre-defined data.'));

    // Source data fields:
    $data_fields = array(
      'title' => t('Title'),
      'ua_flexible_page_subtitle' => t('Sub-title'),
      'path' => t('URL path settings'),
      'ua_main_content' => t('Main Content'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // The title and path have no prefixes.
    $this->addSimpleMappings(array('title'));
    $this->addSimpleMappings(array('path'));
    $this->addFieldMapping('field_ua_flexible_page_subtitle', 'ua_flexible_page_subtitle');

    // Paragraphs (UA Content Chunks).
    $this->addFieldMapping('field_ua_main_content', 'ua_main_content')
         ->separator('|')
         ->sourceMigration(array(
           'UaDemoPlainText',
           'UaDemoHeadedText',
           'UaDemoColumnImage',
         ));
  }

}
