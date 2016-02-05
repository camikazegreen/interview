<?php

/**
 * @file
 * Add content to demonstrate the UAQS Program feature.
 */

/**
 * Makes demonstration UAQS Program taxonomy terms from pre-defined data.
 *
 * Terms come from a local JSON-formatted text file.
 *
 * @see UaqsTermMigration
 */
class UaqsDemoProgramTermMigration extends UaqsTermMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'tags',
      t('Add demonstration UAQS Program taxonomy terms to a vocabulary.'));
  }

}

/**
 * Makes demonstration UAQS Program node content from pre-defined data.
 *
 * The field contents come from a JSON file.
 */
class UaqsDemoProgramMigration extends UaqsNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_program',
      t('Make demonstration UAQS Program node content from pre-defined data.'));

    // Documented lists of source data fields.
    // See uaqs_program uaqs_program.features.field_instance.inc
    // First, the single-value text fielda...
    $data_fields = array(
      'title' => t('Program Name'),
      'path' => t('URL path settings'),
      'uaqs_focus_areas' => t('Focus Areas (term references)'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // JSON names to simple content type fields and subfields.
    $this->addSimpleMappings(array('title', 'path'));
    $this->addFieldMapping('field_uaqs_focus_areas', 'uaqs_focus_areas')
         ->separator('|');
  }

}
