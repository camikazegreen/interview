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
 * @see UaDemoTermMigration
 */
class UaDemoUnitTermMigration extends UaDemoTermMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'tags',
      t('Add demonstration UA Unit taxonomy terms to a vocabulary.'));
  }

}

/**
 * Makes demonstration UA Unit node content from pre-defined data.
 *
 * A local JSON-formatted text file holds the sample data.
 */
class UaDemoUnitMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_unit',
      t('Make demonstration UA Unit node content from pre-defined data.'));

    // Documented lists of source data fields.
    // See ua_unit ua_unit.features.field_instance.inc
    // First, the single-value text fielda...
    $data_fields = array(
      'title' => t('Unit Name'),
      'path' => t('URL path settings'),
      'ua_unit_contact' => t('Person to contact about this unit'),
      'ua_unit_leadership_info' => t('Leadership Information'),
      'ua_unit_location' => t('Location map URL'),
      'ua_unit_location_title' => t('Location description'),
      'ua_unit_focus_areas' => t('Focus Areas (term references)'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // JSON names to simple content type fields and subfields.
    $this->addSimpleMappings(array('title', 'path'));
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
