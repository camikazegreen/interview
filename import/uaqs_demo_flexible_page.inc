<?php

/**
 * @file
 * Add content to demonstrate the UAQS Flexible Page feature.
 *
 * The main contributed Migrate module does not support the Paragraphs-based
 * entities that are the main point of a UAQS Flexible Page, but the Paragraphs
 * module itself includes Migrate support.
 *
 * @see https://www.drupal.org/node/2271181
 */

/**
 * Defines migration into the UAQS Plain Text type of Paragraphs entity.
 */
class UaqsDemoPlainTextMigration extends UaqsParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_plain_text', 'field_uaqs_main_content',
      t('Populate demonstration UAQS Plain Text entities (based on Paragraphs).'));

    // Fields to import to the bundle.
    $data_fields = array(
      'uaqs_text_area' => t('Generic multi-line text area'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_uaqs_text_area', 'uaqs_text_area');
    // Allow limited HTML markup in the text area field.
    $this->addFieldMapping('field_uaqs_text_area:format')
         ->defaultValue('uaqs_textual_content');
  }

}

/**
 * Defines migration into the UAQS Headed Text type of Paragraphs entity.
 */
class UaqsDemoHeadedTextMigration extends UaqsParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_headed_text', 'field_uaqs_main_content',
      t('Populate demonstration UAQS Headed Text entities (based on Paragraphs).'));

    // Fields to import to the bundle.
    $data_fields = array(
      'uaqs_text_heading' => t('Heading for the following text'),
      'uaqs_text_area' => t('Generic multi-line text area'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_uaqs_text_heading', 'uaqs_text_heading');
    $this->addFieldMapping('field_uaqs_text_area', 'uaqs_text_area');
    // Allow limited HTML markup in the text area field.
    $this->addFieldMapping('field_uaqs_text_area:format')
         ->defaultValue('uaqs_textual_content');
  }

}

/**
 * Defines migration into the UAQS Column Image type of Paragraphs entity.
 */
class UaqsDemoColumnImageMigration extends UaqsParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_column_image', 'field_uaqs_main_content',
      t('Populate demonstration UAQS Column Image entities (based on Paragraphs).'));
    // Paragraphs view_mode
    $paragraphs_core = array (
      'view_mode' => t('View Mode'),
    );
    // Fields to import to the bundle.
    $data_fields = array(
      'uaqs_caption_text' => t('Image caption'),
      'uaqs_image_credit' => t('Image source or copyright holder'),
    );
    // Image fields...
    $image_src_field = 'uaqs_photo';
    $image_fields = array(
      $image_src_field => t('Image to place in content'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $paragraphs_core + $data_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    $this->addSimpleMappings(array('view_mode'));

    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_uaqs_caption_text', 'uaqs_caption_text');
    $this->addFieldMapping('field_uaqs_image_credit', 'uaqs_image_credit');
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
 * Defines migration into the UAQS Extra Info type of Paragraphs entity.
 */
class UaqsDemoExtraInfoMigration extends UaqsParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_extra_info', 'field_uaqs_main_content',
      t('Populate demonstration UAQS Extra Info entities (based on Paragraphs).'));

    // Fields to import to the bundle.
    $data_fields = array(
      'uaqs_link' => t('More information links'),
    );
    // Titles for link...
    $link_title_fields = array(
      'uaqs_link_title' => t('More information link title'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields + $link_title_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_uaqs_link', 'uaqs_link');
    // Link title is a special case.
    $this->addFieldMapping('field_uaqs_link:title', 'uaqs_link_title');

  }

}

/**
 * Defines migration into the UAQS File Attachment type of Paragraphs entity.
 */
class UaqsDemoFileAttachmentMigration extends UaqsParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_file_download', 'field_uaqs_main_content',
      t('Populate demonstration UAQS File Attachment entities (based on Paragraphs).'));

    // The single-value text fielda...
    $single_value_fields = array(
      'uaqs_download_name' => t('Name'),
      'uaqs_download_description' => t('Description'),
    );
    // File fields...
    $file_src_field = 'uaqs_download_file';
    $file_fields = array(
      $file_src_field => t('Attachment filename'),
      $file_src_field . '_description' => t('Attachment description'),
    );
    // Image fields...
    $image_src_field = 'uaqs_download_preview';
    $image_fields = array(
      $image_src_field => t('Download Preview'),
      $image_src_field . '_title' => t('Photo title'),
      $image_src_field . '_alt' => t('Photo alt text'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $single_value_fields + $file_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // One-to-one correspondence: JSON names and simple content type fields.
    foreach (array_keys($single_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Images and attachments.
    foreach (array($image_src_field, $file_src_field) as $src_field) {
      $dst_field = 'field_' . $src_field;
      $this->addFieldMapping($dst_field, $src_field)
           ->separator('|');
      $this->addFieldMapping($dst_field . ':file_replace')
           ->defaultValue(FILE_EXISTS_REPLACE);
      $this->addFieldMapping($dst_field . ':file_class')
           ->defaultValue('MigrateFileUri');
      $this->addFieldMapping($dst_field . ':source_dir')
           ->defaultValue($this->imagePath());
    }

    // Image alt and title fields.
    foreach (array('alt', 'title') as $label) {
      $this->addFieldMapping('field_' . $image_src_field . ':' . $label, $image_src_field . '_' . $label)
           ->separator('|');
    }

    // Attachment description field.
    $label = 'description';
    $this->addFieldMapping('field_' . $file_src_field . ':' . $label, $file_src_field . '_' . $label)
         ->separator('|');
  }
}

/**
 * Defines migration into the UAQS Marquee type of Paragraphs entity.
 */
class UaqsDemoMarqueeMigration extends UaqsParagraphsItemMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_content_chunks_marquee', 'field_uaqs_main_content',
      t('Populate demonstration UAQS Marquee entities (based on Paragraphs).'));
    // Paragraphs view_mode
    $paragraphs_core = array (
      'view_mode' => t('View Mode'),
    );
    // Fields to import to the bundle.
    $data_fields = array(
      'uaqs_summary_short' => t('Title'),
      'uaqs_html' => t('Body'),
      'uaqs_link' => t('Read more'),
    );
    // Image fields...
    $image_src_field = 'uaqs_photo';
    $image_fields = array(
      $image_src_field => t('Image to place in content'),
    );

    // Titles for link...
    $link_title_fields = array(
      'uaqs_link_title' => t('Read more link title'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $paragraphs_core + $data_fields + $image_fields + $link_title_fields ;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    $this->addSimpleMappings(array('view_mode'));
    $this->addFieldMapping('field_uaqs_summary_short', 'uaqs_summary_short');

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
    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_uaqs_html', 'uaqs_html');
    // Allow limited HTML markup in the text area field.
    $this->addFieldMapping('field_uaqs_html:format')
         ->defaultValue('uaqs_full_html');
    // Map JSON names to simple content type fields and subfields.
    $this->addFieldMapping('field_uaqs_link', 'uaqs_link');
    // Link title is a special case.
    $this->addFieldMapping('field_uaqs_link:title', 'uaqs_link_title');
  }

}

/**
 * Makes demonstration UAQS Flexible Page content from pre-defined data.
 *
 * This migration imports a small part of the UAQS FlexiblePage content directly
 * from a JSON file, but most of it is encapsulated in a series of entities
 * from the Paragraphs module, which get their own migrations (see above).
 */
class UaqsDemoFlexiblePageMigration extends UaqsNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_flexible_page',
      t('Make demonstration UAQS Flexible Page content from pre-defined data.'));

    // Source data fields:
    $data_fields = array(
      'title' => t('Title'),
      'uaqs_flexible_page_subtitle' => t('Sub-title'),
      'path' => t('URL path settings'),
      'uaqs_main_content' => t('Main Content'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // The title and path have no prefixes.
    $this->addSimpleMappings(array('title'));
    $this->addSimpleMappings(array('path'));
    $this->addFieldMapping('field_uaqs_flexible_page_subtitle', 'uaqs_flexible_page_subtitle');

    // Paragraphs (UAQS Content Chunks).
    $this->addFieldMapping('field_uaqs_main_content', 'uaqs_main_content')
         ->separator('|')
         ->sourceMigration(array(
           'UaqsDemoPlainText',
           'UaqsDemoHeadedText',
           'UaqsDemoColumnImage',
           'UaqsDemoMarquee',
         ));
  }

}
