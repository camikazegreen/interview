<?php

/**
 * @file
 * Add content to demonstrate the UA Event feature.
 */

/**
 * Makes demonstration UA Event content from pre-defined data.
 *
 * Currently local files hold the sample data this uses to build the content,
 * in a single JSON-formatted text file and collection of images. The overall
 * approach is similar to the one illustrated for handling JSON imports in the
 * documentation for the Migrate module in the “Using MigrateSourceJSON”
 * subsection.
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoEventMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Make demonstration UA Event content from pre-defined data.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    // Documented lists of source data fields: all names here MUST match
    // those in the corresponding content type.
    // @see ua_event ua_event.features.field_instance.inc
    // First, the node title field
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

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key (int)'));

    // All the fields to migrate.
    $fields = $source_key + $title_field + $single_value_fields + $date_extra_fields + $link_title_fields + $file_fields + $image_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    // Destination.
    $this->destination = new MigrateDestinationNode('ua_event');

    // The usual migration map, keyed off the arbitrary source IDs.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        $id_field => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => $source_key[$id_field],
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // The title has no prefix
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
         ->defaultValue($our_path . '/import/images');
    $file_dst_field = 'field_' . $file_src_field;
    $this->addFieldMapping($file_dst_field, $file_src_field)
         ->separator('|');
    $this->addFieldMapping($file_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping($file_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($file_dst_field . ':source_dir')
         ->defaultValue($our_path . '/import/images');

    // Image alt and title fields
    foreach (array('alt', 'title') as $subfield) {
      $this->addFieldMapping('field_' . $image_src_field . ':' . $subfield, $image_src_field . '_' . $subfield);
    }

    // Attachment description field
    $subfield = 'description';
    $this->addFieldMapping('field_' . $file_src_field . ':' . $subfield, $file_src_field . '_' . $subfield)
         ->separator('|');

    // Allow limited HTML markup in the description field
    $this->addFieldMapping('field_ua_event_description:format')
         ->defaultValue('filtered_html');
  }
}

/**
 * Populate the Contacts field collection within UA Event content.
 *
 * A field collection is an independent entity, so the main migration that
 * creates nodes cannot treat it as just another field, so a distinct
 * but associated migration is needed.
 *
 * @see https://www.drupal.org/node/1900640
 */
class UaDemoEventContactMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Populate demonstration UA Event contact field collections.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    $this->dependencies = array('UaDemoEvent');

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key (int)'));

    // Foreign key.
    $host_entity_id = 'ua_event_id';
    $foreign_key = array(
      $host_entity_id => t('ID of parent UA Event item'),
    );

    // Data fields.
    $data_fields = array(
      'ua_event_contact_name' => t('Contact Name'),
      'ua_event_contact_email' => t('Contact Email'),
      'ua_email_contact_phone' => t('Contact Phone'),
    );

    $fields = $source_key + $foreign_key + $data_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    $this->destination = new MigrateDestinationFieldCollection(
      'field_ua_event_contacts',
      array('host_entity_type' => 'node')
    );

    // The usual migration map, keyed off the arbitrary source IDs.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        $id_field => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => $source_key[$id_field],
        )
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Linking back to UA Event items on the foregn key
    $this->addFieldMapping('host_entity_id', $host_entity_id)
         ->sourceMigration('UaDemoEvent');

    foreach (array_keys($data_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

  }
}
