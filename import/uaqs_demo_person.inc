<?php

/**
 * @file
 * Add content to demonstrate the UA Person feature.
 */

/**
 * Makes demonstration UA Person content from pre-defined data.
 *
 * Currently local files hold the sample data this uses to build the content,
 * in a single JSON-formatted text file and collection of images. The overall
 * approach is similar to the one illustrated for handling JSON imports in the
 * documentation for the Migrate module in the “Using MigrateSourceJSON”
 * subsection.
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoPersonMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Make demonstration UA Person content from pre-defined data.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    // Documented lists of source data fields: all names here MUST match
    // those in the corresponding content type.
    // @see ua_person ua_person.features.field_instance.inc
    // First, the single-value text fielda...
    $single_value_fields = array(
      'ua_person_lname'  => t('Last Name (string)'),
      'ua_person_fname'  => t('First Name (string)'),
      'ua_person_email'  => t('E-mail (string)'),
      'ua_person_addresses' => t('Office location(s) (string)'),
      'ua_person_bio'    => t('Biography (string)'),
    );
    // Then the multi-value text fields...
    $multi_value_fields = array(
      'ua_person_phones' => t('Phone Number(s) (string[])'),
      'ua_person_titles' => t('Job Title(s) (string[])'),
    );
    // Image fields need special treatment, isolate them...
    $image_src_field = 'ua_person_photo';
    $image_fields = array($image_src_field => t('Photo filename (string)'));

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key (int)'));

    // All the fields to migrate.
    $fields = $source_key + $single_value_fields + $multi_value_fields + $image_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    // Destination.
    $this->destination = new MigrateDestinationNode('ua_person');

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

    // One-to-one correspondence: JSON names and simple content type fields.
    foreach (array_keys($single_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Multi-value fields need an explicit sparator (nesting { } doesn't work).
    foreach (array_keys($multi_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field)
           ->separator('|');
    }

    //Image fields are more complicated.
    $image_dst_field = 'field_' . $image_src_field;
    $this->addFieldMapping($image_dst_field, $image_src_field);
    $this->addFieldMapping($image_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    //  MigrateFileUri works for a local filespec as well as remote URIs.
    $this->addFieldMapping($image_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($image_dst_field . ':source_dir')
         ->defaultValue($our_path . '/import/images');
  }

}