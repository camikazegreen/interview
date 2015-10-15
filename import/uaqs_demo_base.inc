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
  public function __construct(array $arguments) {
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
  public function __construct(array $arguments, $vocabulary, $description) {
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
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // One-to-one correspondence: JSON names and taxonomy fields.
    $this->addSimpleMappings(array_keys($fields));

    // Unmapped fields.
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
    $key_field = array_keys($this->sourceKeyField);
    return $key_field[0];
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
  public function __construct(array $arguments, $id_field, array $dest_key_schema) {
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
        ),
      ),
      $dest_key_schema
    );
  }

}

/**
 * Defines a customized migration into Drupal nodes.
 *
 * The Migration module's standard MigrateDestinationNode is the basis of this
 * which makes some assumptions to match the rest of the UA Demo migrations.
 *
 * @see https://www.drupal.org/node/1349696
 */
abstract class UaDemoNodeMigration extends UaDemoIntKeyedMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   * @param string $bundle
   *   Node type name.
   * @param string $description
   *   Detailed information describing the migration.
   */
  public function __construct(array $arguments, $bundle, $description) {
    parent::__construct($arguments, 'id', MigrateDestinationNode::getKeySchema());

    $this->description = $description;

    // Destination.
    $this->destination = new MigrateDestinationNode($bundle);

    // Defaults and ignored destination fields...
    $this->addUnmigratedDestinations(array(
      'status', 'promote', 'sticky', 'revision', 'log', 'language', 'tnid',
      'translate', 'revision_uid', 'is_new',
    ));
    // The only user we can count on is User 1.
    $this->addFieldMapping('uid')
         ->defaultValue(1);
    $arbitrary_timestamp = "2015-07-21 09:38:00";
    $this->addFieldMapping('created')
         ->defaultValue($arbitrary_timestamp);
    $this->addFieldMapping('changed')
         ->defaultValue($arbitrary_timestamp);
  }

}

/**
 * Defines a migration into a Field Collection.
 *
 * The Migration module has no direct support for Field Collections
 * (which are use freestanding entities, distinct from nodes), but the
 * Field Collection module itself defines a Migration api. Here we adopt some
 * additional constraints: the host entity is always a node, and there is
 * only one migration dependency, which is also the source migration.
 *
 * @see https://www.drupal.org/node/1900640
 */
abstract class UaDemoFieldCollectionMigration extends UaDemoIntKeyedMigration {

  /**
   * Name and label for the foreign key.
   */
  protected $foreignKeyField;

  /**
   * Gets the foreign key field name and description.
   *
   * @return array
   *   An associative array giving the foreign key field name and description.
   */
  public function getForeignKeyField() {
    return $this->foreignKeyField;
  }

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   * @param string $bundle
   *   Name of the field where the collection attaches to the node.
   * @param string $host_entity_id
   *   Name of the field holding the foreign key (the associated node id).
   * @param string $host_entity_migration
   *   Name of the migration for the associated nodes.
   * @param string $description
   *   Detailed information describing the migration.
   */
  public function __construct(array $arguments, $bundle, $host_entity_id, $host_entity_migration, $description) {
    parent::__construct($arguments, 'id', MigrateDestinationFieldCollection::getKeySchema());

    $this->description = $description;

    // Foreign key.
    $this->foreignKeyField = array(
      $host_entity_id => t('ID of the parent item'),
    );
    $this->destination = new MigrateDestinationFieldCollection(
      $bundle,
      array('host_entity_type' => 'node')
    );

    // Linking back to parent items on the foreign key.
    $this->addFieldMapping('host_entity_id', $host_entity_id)
         ->sourceMigration($host_entity_migration);
  }

}

/**
 * Defines a customized migration into Drupal menu items.
 *
 * The Migration module's standard MigrateDestinationMenuLinks is the basis of
 * this, which makes some assumptions to match the rest of the UA Demo
 * migrations.
 */
abstract class UaDemoMenuLinksMigration extends UaDemoIntKeyedMigration {

  /**
   * Name and label for the foreign key.
   */
  protected $parentLinkField;

  /**
   * Gets the parent link field name and description.
   *
   * @return array
   *   An associative array giving the parent link field name and description.
   */
  public function getParentLinkField() {
    return $this->parentLinkField;
  }

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   * @param string $plid
   *   Name of the field holding the menu item's parent link ID.
   * @param string $description
   *   Detailed information describing the migration.
   */
  public function __construct(array $arguments, $plid, $description) {
    parent::__construct($arguments, 'mlid', MigrateDestinationMenuLinks::getKeySchema());

    $this->description = $description;

    // Parent of this menu item.
    $this->parentLinkField = array(
      $plid => t('ID of the parent item'),
    );

    // Destination.
    $this->destination = new MigrateDestinationMenuLinks();

    // Look up the parent ID using our own map.
    $this->addFieldMapping('plid', $plid)
         ->sourceMigration($this->getMachineName());

    // Defaults and ignored destination fields...
    $this->addUnmigratedDestinations(array(
      'options', 'module', 'hidden',
      'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8', 'p9', 'updated',
    ));
    $this->addFieldMapping('router_path')
         ->defaultValue('node/%');
    $this->addFieldMapping('has_children')
         ->defaultValue('0');
    $this->addFieldMapping('expanded')
         ->defaultValue('0');
    $this->addFieldMapping('depth')
         ->defaultValue('1');
    $this->addFieldMapping('customized')
         ->defaultValue('1');
  }

}
