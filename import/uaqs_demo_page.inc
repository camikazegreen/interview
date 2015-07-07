<?php

/**
 * @file
 * Add content to demonstrate the UA Basic Page feature.
 */

/**
 * Makes demonstration UA Basic Page content from pre-defined data.
 *
 * The field contents come from a JSON file.
 */
class UaDemoPageMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'ua_page',
      t('Make demonstration UA Basic Page node content from pre-defined data.'));

    // Documented lists of source data fields.
    // @see ua_page ua_page.features.field_instance.inc
    $data_fields = array(
      'title' => t('Title'),
      'path' => t('URL path settings'),
      'ua_page_body' => t('Page body'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addSimpleMappings(array('title'));
    $this->addSimpleMappings(array('path'));
    $this->addSimpleMappings(array('ua_page_body'));
    // Allow limited HTML markup in the page body field
    $this->addFieldMapping('ua_page_body:format')
         ->defaultValue('filtered_html');

  }
}