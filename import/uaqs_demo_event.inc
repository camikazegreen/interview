<?php

/**
 * @file
 * Add content to demonstrate the UA Event feature.
 */

/**
 * Makes demonstration UA Event content from pre-defined data.
 *
 * This migration imports most of the UA Event content from a JSON file, but
 * the contacts list for the event is a distinct entity and needs its own
 * migration (see below).
 */
class UaDemoEventMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_event',
      t('Make demonstration UA Event content from pre-defined data.'));

    // Documented lists of source data fields.
    // See ua_event ua_event.features.field_instance.inc
    // First, the node title field...
    $title_field = array(
      'title' => t('Title'),
    );
    // The single-value text fielda...
    $single_value_fields = array(
      'ua_event_short_title' => t('Short title'),
      'ua_event_front' => t('Show on front page'),
      'ua_event_date' => t('Event date'),
      'ua_event_summary' => t('Summary'),
      'ua_event_description' => t('Description'),
      'ua_event_location' => t('Event location'),
      'ua_event_more_info' => t('More information'),
    );
    // Date ending and repeat fields...
    $date_extra_fields = array(
      'ua_event_date_to' => t('Event end date'),
      'ua_event_date_rrule' => t('Event date repeat rule'),
    );
    // Titles for links...
    $link_title_fields = array(
      'ua_event_location_title' => t('Location link title'),
      'ua_event_more_info_title' => t('Information link title'),
    );
    // File fields...
    $file_src_field = 'ua_event_attachments';
    $file_fields = array(
      $file_src_field => t('Attachment filename'),
      $file_src_field . '_description' => t('Attachment description'),
    );
    // Image fields...
    $image_src_field = 'ua_event_photo';
    $image_fields = array(
      $image_src_field => t('Event Photo'),
      $image_src_field . '_title' => t('Event photo title'),
      $image_src_field . '_alt' => t('Event photo alt text'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $title_field + $single_value_fields + $date_extra_fields + $link_title_fields + $file_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // The title has no prefix.
    $this->addSimpleMappings(array('title'));

    // One-to-one correspondence: JSON names and simple content type fields.
    foreach (array_keys($single_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Date extras.
    $this->addFieldMapping('field_ua_event_date:to', 'ua_event_date_to');
    $this->addFieldMapping('field_ua_event_date:rrule', 'ua_event_date_rrule');

    // Link titles.
    $this->addFieldMapping('field_ua_event_location:title', 'ua_event_location_title');
    $this->addFieldMapping('field_ua_event_more_info:title', 'ua_event_more_info_title');

    // Images and attachments.
    $image_dst_field = 'field_' . $image_src_field;
    $this->addFieldMapping($image_dst_field, $image_src_field);
    $this->addFieldMapping($image_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping($image_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($image_dst_field . ':source_dir')
         ->defaultValue($this->imagePath());
    $file_dst_field = 'field_' . $file_src_field;
    $this->addFieldMapping($file_dst_field, $file_src_field)
         ->separator('|');
    $this->addFieldMapping($file_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping($file_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($file_dst_field . ':source_dir')
         ->defaultValue($this->imagePath());

    // Image alt and title fields.
    foreach (array('alt', 'title') as $subfield) {
      $this->addFieldMapping('field_' . $image_src_field . ':' . $subfield, $image_src_field . '_' . $subfield);
    }

    // Attachment description field.
    $subfield = 'description';
    $this->addFieldMapping('field_' . $file_src_field . ':' . $subfield, $file_src_field . '_' . $subfield)
         ->separator('|');

    // Allow limited HTML markup in the description field.
    $this->addFieldMapping('field_ua_event_description:format')
         ->defaultValue('filtered_html');
  }

}

/**
 * Populate the Contacts field collection within UA Event content.
 */
class UaDemoEventContactMigration extends UaDemoFieldCollectionMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'field_ua_event_contacts', 'ua_event_id', 'UaDemoEvent',
      t('Populate demonstration UA Event contact field collections.'));

    // Data fields.
    $data_fields = array(
      'ua_event_contact_name' => t('Contact Name'),
      'ua_event_contact_email' => t('Contact Email'),
      'ua_email_contact_phone' => t('Contact Phone'),
    );

    $fields = $this->getSourceKeyField() + $this->getForeignKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    foreach (array_keys($data_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Unmigrated fields.
    $this->addUnmigratedDestinations(array(
      'field_ua_email_contact_phone:language',
      'field_ua_event_contact_name:language',
    ));
  }

}
