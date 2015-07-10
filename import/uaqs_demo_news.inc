<?php

/**
 * @file
 * Add content to demonstrate the UA News feature.
 */

/**
 * Makes demonstration UA News content from pre-defined data.
 *
 * This migration imports most of the UA News content from a JSON file, but
 * the contacts list for the news item is a distinct entity and needs its own
 * migration (see below).
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoNewsMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_news',
      t('Make demonstration UA News content from pre-defined data.'));

    // Documented lists of source data fields.
    // Seesee ua_news ua_news.features.field_instance.inc
    // First, the node title field...
    $title_field = array(
      'title' => t('Title'),
    );
    // The single-value text fielda...
    $single_value_fields = array(
      'ua_news_short_title' => t('Short title'),
      'ua_news_front' => t('Show on front page'),
      'ua_news_byline' => t('Byline'),
      'ua_news_published' => t('Published'),
      'expiration_date' => t('Expiration date'),
      'ua_news_summary' => t('Summary'),
      'ua_news_body' => t('Article body'),
      'ua_news_more_info' => t('Link to more information'),
    );
    // Titles for links...
    $link_title_fields = array(
      'ua_news_more_info_title' => t('Information link title'),
    );
    // File fields...
    $file_src_field = 'ua_news_attachments';
    $file_fields = array(
      $file_src_field => t('Attachment filename'),
      $file_src_field . '_description' => t('Attachment description'),
    );
    // Image fields...
    $image_src_field = 'ua_news_photo';
    $image_fields = array(
      $image_src_field => t('Photo filename'),
      $image_src_field . '_title' => t('Photo title'),
      $image_src_field . '_alt' => t('Photo alt text'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $title_field + $single_value_fields + $link_title_fields + $file_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // The title has no prefix.
    $this->addSimpleMappings(array('title'));

    // One-to-one correspondence: JSON names and simple content type fields.
    foreach (array_keys($single_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Link title is a special case.
    $this->addFieldMapping('field_ua_news_more_info:title', 'ua_news_more_info_title');

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

    // Allow limited HTML markup in the body field.
    $this->addFieldMapping('field_ua_news_body:format')
         ->defaultValue('filtered_html');
  }

}

/**
 * Populate the Contacts field collection within UA News content.
 */
class UaDemoNewsContactMigration extends UaDemoFieldCollectionMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'field_ua_news_contacts', 'ua_news_id', 'UaDemoNews',
      t('Populate demonstration UA News contact field collections.'));

    // Data fields.
    $data_fields = array(
      'ua_news_contact_name' => t('Contact Name'),
      'ua_news_contact_email' => t('Contact Email'),
      'ua_news_contact_phone' => t('Contact Phone'),
    );

    $fields = $this->getSourceKeyField() + $this->getForeignKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    foreach (array_keys($data_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Unmigrated fields.
    $this->addUnmigratedDestinations(array(
      'field_ua_news_contact_phone:language',
      'field_ua_news_contact_name:language',
    ));
  }

}
