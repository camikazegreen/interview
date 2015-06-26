<?php

/**
 * @file
 * Add content to demonstrate the UA Program feature.
 */

/**
 * Makes demonstration UA Program taxonomy terms from pre-defined data.
 *
 * Terms come from a local JSON-formatted text file.
 *
 * @see UaDemoProgramMigration for more details.
 */
class UaDemoProgramTermMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Add demonstration UA Program taxonomy terms to a vocabulary.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    // Taxonomy term fields.
    $data_fields = array(
      'description' => t('Taxonomy term description'),
      'parent_name' => t('Nest under the term with this name'),
    );

    // Source key field.
    $id_field = 'name';
    $source_key = array($id_field => t('Unique key'));

    // All the fields to migrate.
    $fields = $source_key + $data_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    // Destination, giving the machine name of the vocabulary.
    $this->destination = new MigrateDestinationTerm('tags');

    // The usual migration map, keyed off the source term names.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        $id_field => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => $source_key[$id_field],
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // One-to-one correspondence: JSON names and taxonomy fields.
    $this->addSimpleMappings(array_keys($fields));
  }
}

/**
 * Makes demonstration UA Program node content from pre-defined data.
 *
 * A local JSON-formatted text file holds the sample data this uses to build
 * the node contents. The overall approach is similar to the one illustrated
 * for handling JSON imports in the documentation for the Migrate module in the
 * “Using MigrateSourceJSON” subsection.
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoProgramMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Make demonstration UA Program node content from pre-defined data.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    // Documented lists of source data fields.
    // @see ua_program ua_program.features.field_instance.inc
    // First, the single-value text fielda...
    $data_fields = array(
      'title' => t('Program Name'),
      'ua_program_focus_areas' => t('Focus Areas (term references)'),
    );

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key'));

    // All the fields to migrate.
    $fields = $source_key + $data_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    // Destination.
    $this->destination = new MigrateDestinationNode('ua_program');

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

    // JSON names to simple content type fields and subfields.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_ua_program_focus_areas', 'ua_program_focus_areas')
         ->separator('|');
  }
}
