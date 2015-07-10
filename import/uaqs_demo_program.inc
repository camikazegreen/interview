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
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'tags',
      t('Add demonstration UA Program taxonomy terms to a vocabulary.'));
  }

}

/**
 * Makes demonstration UA Program node content from pre-defined data.
 *
 * The field contents come from a JSON file.
 */
class UaDemoProgramMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_program',
      t('Make demonstration UA Program node content from pre-defined data.'));

    // Documented lists of source data fields.
    // @see ua_program ua_program.features.field_instance.inc
    // First, the single-value text fielda...
    $data_fields = array(
      'title' => t('Program Name'),
      'path' => t('URL path settings'),
      'ua_program_focus_areas' => t('Focus Areas (term references)'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // JSON names to simple content type fields and subfields.
    $this->addSimpleMappings(array('title'));
    $this->addSimpleMappings(array('path'));
    $this->addFieldMapping('field_ua_program_focus_areas', 'ua_program_focus_areas')
         ->separator('|');
  }

}
