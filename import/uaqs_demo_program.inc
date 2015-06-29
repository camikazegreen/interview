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
 * @see UaDemoTermMigration
 */
class UaDemoProgramTermMigration extends UaDemoTermMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'tags',
      t('Add demonstration UA Program taxonomy terms to a vocabulary.'));
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
class UaDemoProgramMigration extends UaDemoIntKeyedMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'id', MigrateDestinationNode::getKeySchema());

    $this->description =
      t('Make demonstration UA Program node content from pre-defined data.');

    // Documented lists of source data fields.
    // @see ua_program ua_program.features.field_instance.inc
    // First, the single-value text fielda...
    $data_fields = array(
      'title' => t('Program Name'),
      'ua_program_focus_areas' => t('Focus Areas (term references)'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Destination.
    $this->destination = new MigrateDestinationNode('ua_program');

    // JSON names to simple content type fields and subfields.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_ua_program_focus_areas', 'ua_program_focus_areas')
         ->separator('|');
  }

}
