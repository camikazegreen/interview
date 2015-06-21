<?php

/**
 * @file
 * Add content to demonstrate the UA News feature.
 */

/**
 * Makes demonstration UA News content from pre-defined data.
 *
 * Currently local files hold the sample data this uses to build the content,
 * in a single JSON-formatted text file and collection of images. The overall
 * approach is similar to the one illustrated for handling JSON imports in the
 * documentation for the Migrate module in the “Using MigrateSourceJSON”
 * subsection.
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoNewsMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Make demonstration UA News content from pre-defined data.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    // Documented lists of source data fields: all names here MUST match
    // those in the corresponding content type.
    // @see ua_news ua_news.features.field_instance.inc
    // First, the node title field
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
    );
    // Image fields...
    $image_src_field = 'ua_news_photo';
    $image_fields = array(
      $image_src_field => t('Photo filename'),
    );

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key (int)'));

    // All the fields to migrate.
    $fields = $source_key + $title_field + $single_value_fields + $link_title_fields + $file_fields + $image_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    // Destination.
    $this->destination = new MigrateDestinationNode('ua_news');

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
           ->defaultValue($our_path . '/import/images');
    }

    // Allow limited HTML markup in the body field
    $this->addFieldMapping('field_ua_news_body:format')
         ->defaultValue('filtered_html');
  }
}

/**
 * Populate the Contacts field collection within UA News content.
 *
 * A field collection is an independent entity, so the main migration that
 * creates nodes cannot treat it as just another field, so a distinct
 * but associated migration is needed.
 *
 * @see https://www.drupal.org/node/1900640
 */
class UaDemoNewsContactMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Populate demonstration UA News contact field collections.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    $this->dependencies = array('UaDemoNews');

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key (int)'));

    // Foreign key.
    $host_entity_id = 'ua_news_id';
    $foreign_key = array(
      $host_entity_id => t('ID of parent UA News item'),
    );

    // Data fields.
    $data_fields = array(
      'ua_news_contact_name' => t('Contact Name'),
      'ua_news_contact_email' => t('Contact Email'),
      'ua_news_contact_phone' => t('Contact Phone'),
    );

    $fields = $source_key + $foreign_key + $data_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    $this->destination = new MigrateDestinationFieldCollection(
      'field_ua_news_contacts',
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

    // Linking back to UA News items on the foregn key
    $this->addFieldMapping('host_entity_id', $host_entity_id)
         ->sourceMigration('UaDemoNews');

    foreach (array_keys($data_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

  }
}