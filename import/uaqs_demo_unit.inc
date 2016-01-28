<?php

/**
 * @file
 * Add content to demonstrate the UAQS Unit feature.
 */

/**
 * Makes demonstration UAQS Unit taxonomy terms from pre-defined data.
 *
 * Terms come from a local JSON-formatted text file.
 *
 * @see UaqsDemoTermMigration
 */
class UaqsDemoUnitTermMigration extends UaqsDemoTermMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'tags',
      t('Add demonstration UAQS Unit taxonomy terms to a vocabulary.'));
  }

}

/**
 * Makes demonstration UAQS Unit node content from pre-defined data.
 *
 * A local JSON-formatted text file holds the sample data.
 */
class UaqsDemoUnitMigration extends UaqsDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'uaqs_unit',
      t('Make demonstration UAQS Unit node content from pre-defined data.'));

    // Documented lists of source data fields.
    // See uaqs_unit uaqs_unit.features.field_instance.inc
    // First, the single-value text fielda...
    $data_fields = array(
      'title' => t('Unit Name'),
      'path' => t('URL path settings'),
      'uaqs_contact' => t('Person to contact about this unit'),
      'uaqs_leadership_info' => t('Leadership Information'),
      'uaqs_location' => t('Location map URL'),
      'uaqs_location_title' => t('Location description'),
      'uaqs_focus_areas' => t('Focus Areas (term references)'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // JSON names to simple content type fields and subfields.
    $this->addSimpleMappings(array('title', 'path'));
    $this->addFieldMapping('field_uaqs_contact', 'uaqs_contact');
    $this->addFieldMapping('field_uaqs_leadership_info', 'uaqs_leadership_info');
    $this->addFieldMapping('field_uaqs_leadership_info:format')
         ->defaultValue('filtered_html');
    $this->addFieldMapping('field_uaqs_location', 'uaqs_location');
    $this->addFieldMapping('field_uaqs_location:title', 'uaqs_location_title');
    $this->addFieldMapping('field_uaqs_focus_areas', 'uaqs_focus_areas')
         ->separator('|');
  }

}
