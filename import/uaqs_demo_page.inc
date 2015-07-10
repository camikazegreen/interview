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
   * Numeric ID of the JSON file entry for the front page.
   */
  const FRONT_PAGE_SOURCE_ID = 4;

  /**
   * The UA Basic Page (as a Drupal node) to use as the site front page.
   *
   * @return string
   *   The non-aliased Drupal node path, or 'node' if there is none.
   */
  public function getFrontPageNode() {
    $dest_keys = $this->getMap()->lookupDestinationID(array(self::FRONT_PAGE_SOURCE_ID));
    if (is_array($dest_keys)) {
      $front_nid = reset($dest_keys);
      return "node/{$front_nid}";
    }
    else {
      return 'node';
    }
  }

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_page',
      t('Make demonstration UA Basic Page node content from pre-defined data.'));

    // Documented lists of source data fields.
    // Seesee ua_page ua_page.features.field_instance.inc
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
    // Allow limited HTML markup in the page body field.
    $this->addFieldMapping('ua_page_body:format')
         ->defaultValue('filtered_html');

  }

}
