<?php

/**
 * @file
 * Add content to demonstrate the UA Unit feature.
 */

/**
 * Makes demonstration UA Unit taxonomy terms from pre-defined data.
 *
 * Terms come from a local JSON-formatted text file.
 *
 * @see UaDemoUnitMigration for more details.
 */
class UaDemoUnitTermMigration extends UaDemoLocalfileMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Add demonstration UA Unit taxonomy terms to a vocabulary.');

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
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $id_field, $fields);

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
 * Makes demonstration UA Unit node content from pre-defined data.
 *
 * A local JSON-formatted text file holds the sample data this uses to build
 * the node contents. The overall approach is similar to the one illustrated
 * for handling JSON imports in the documentation for the Migrate module in the
 * “Using MigrateSourceJSON” subsection.
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoUnitMigration extends UaDemoLocalfileMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Make demonstration UA Unit node content from pre-defined data.');

    // Documented lists of source data fields.
    // @see ua_unit ua_unit.features.field_instance.inc
    // First, the single-value text fielda...
    $data_fields = array(
      'title' => t('Unit Name'),
      'ua_unit_contact' => t('Person to contact about this unit'),
      'ua_unit_leadership_info' => t('Leadership Information'),
      'ua_unit_location' => t('Location map URL'),
      'ua_unit_location_title' => t('Location description'),
      'ua_unit_focus_areas' => t('Focus Areas (term references)'),
    );

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key'));

    // All the fields to migrate.
    $fields = $source_key + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $id_field, $fields);

    // Destination.
    $this->destination = new MigrateDestinationNode('ua_unit');

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
    $this->addFieldMapping('field_ua_unit_contact', 'ua_unit_contact');
    $this->addFieldMapping('field_ua_unit_leadership_info', 'ua_unit_leadership_info');
    $this->addFieldMapping('field_ua_unit_leadership_info:format')
         ->defaultValue('filtered_html');
    $this->addFieldMapping('field_ua_unit_location', 'ua_unit_location');
    $this->addFieldMapping('field_ua_unit_location:title', 'ua_unit_location_title');
    $this->addFieldMapping('field_ua_unit_focus_areas', 'ua_unit_focus_areas')
         ->separator('|');
  }
}