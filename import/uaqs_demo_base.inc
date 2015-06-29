<?php

/**
 * @file
 * Provides common base classes that the migrations for features can extend.
 */

/**
 * Establishes conventions for file handling.
 *
 * The default conventions for finding demo content associate local JSON files
 * with each migration, naming each file from the lowercased version of the
 * machine name of the migration. All the JSON files are in the data
 * subdirectory of the directory holding the migration PHP code, and any
 * additional files (PDF documents, JPEG and PNG images) are in a parallel
 * images subdirectory.
 */
abstract class UaDemoLocalfileMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  /**
   * Hard-codes the name for the subdirectory within this module's directory.
   *
   * @return string
   *   The path of our directory relative to DRUPAL_ROOT.
   */
  public function importRoot() {
    return drupal_get_path('module', 'ua_demo') . '/import';
  }

  /**
   * Gives the path of the directory holding the JSON demo data files.
   *
   * @return string
   *   The path relative to DRUPAL_ROOT.
   */
  public function dataPath() {
    return $this->importRoot() . '/data';
  }

  /**
   * Gives the path of the directory holding the image and attachment files.
   *
   * @return string
   *   The path relative to DRUPAL_ROOT.
   */
  public function imagePath() {
    return $this->importRoot() . '/images';
  }

  /**
   * Turns a class machine name into the default JSON data file path.
   *
   * @return string
   *   The relative path to the JSON data file.
   */
  public function jsonFilePath() {
    return $this->dataPath() . '/' . drupal_strtolower($this->machineName) . '.json';
  }

}

/**
 * Imports demonstration taxonomy terms from pre-defined data.
 *
 * Terms come from a local JSON-formatted text file, and the overall approach
 * here is similar to the abstract taxonomy migration class in the wine.inc
 * sample code included with the Migrate module, and the documentation for
 * migration sources based on MigrateSourceJSON.
 *
 * @see https://www.drupal.org/node/1152160
 */
abstract class UaDemoTermMigration extends UaDemoLocalfileMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   * @param string $vocabulary
   *   The machine name of the taxonomy vocabulary into which to import terms.
   * @param string $description
   *   Detailed information describing the migration.
   */
  public function __construct($arguments, $vocabulary, $description) {
    parent::__construct($arguments);

    $this->description = $description;

    // Taxonomy term fields.
    $data_fields = array(
      'description' => t('Taxonomy term description'),
      'parent_name' => t('Nest under the term with this name'),
    );

    // Source key field: in our case we use the term names, not numeric IDs.
    $id_field = 'name';
    $source_key = array($id_field => t('Taxonomy term'));

    // All the fields to migrate.
    $fields = $source_key + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $id_field, $fields);

    // Destination, giving the machine name of the vocabulary.
    $this->destination = new MigrateDestinationTerm($vocabulary);

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

    // Unmapped fields
    foreach (array('parent', 'weight', 'format') as $unmapped) {
      $this->addFieldMapping($unmapped)
           ->issueGroup(t('DNM'));
    }
  }

}

/**
 * Defines a migration that uses arbitrary int source keys.
 *
 * Most of the migration sources have int keys for the source records, so the
 * map definitions are all similar.
 *
 * @see https://www.drupal.org/node/1007004
 */
abstract class UaDemoIntKeyedMigration extends UaDemoLocalfileMigration {

  /**
   * Name and label for the source key.
   */
  protected $sourceKeyField;

  /**
   * Gets the source key field name and description.
   *
   * @return array
   *   An associative array giving the source key field name and description.
   */
  public function getSourceKeyField() {
    return $this->sourceKeyField;
  }

  /**
   * Gets the source key field name.
   *
   * @return string
   *   The name of the key field in the migration source.
   */
  public function getSourceKeyFieldName() {
    return (array_keys($this->sourceKeyField)[0]);
  }

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   * @param string $id_field
   *   Name of the key field in the source records.
   * @param array $dest_key_schema
   *   A Drupal schema definition for the destination key.
   */
  public function __construct($arguments, $id_field, $dest_key_schema) {
    parent::__construct($arguments);

    $this->sourceKeyField = array($id_field => t('Unique key'));
    // The usual migration map, keyed off the arbitrary source IDs.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        $id_field => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => $this->sourceKeyField[$id_field],
        )
      ),
      $dest_key_schema
    );
  }

}
