<?php

/**
 * @file
 * Add content to demonstrate the UAQS Basic Page feature.
 */

/**
 * Makes demonstration UAQS Basic Page content from pre-defined data.
 *
 * The field contents come from a JSON file.
 */
class UaqsDemoPageMigration extends UaqsNodeMigration {

  /**
   * Numeric ID of the JSON file entry for the front page.
   */
  const FRONT_PAGE_SOURCE_ID = 4;

  /**
   * The UAQS Basic Page (as a Drupal node) to use as the site front page.
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
    parent::__construct($arguments, 'uaqs_page',
      t('Make demonstration UAQS Basic Page node content from pre-defined data.'));

    // Documented lists of source data fields.
    // See uaqs_page uaqs_page.features.field_instance.inc.
    $data_fields = array(
      'title' => t('Title'),
      'uaqs_summary_short' => t('Sub-title'),
      'field_uaqs_body' => t('Page body'),
      'path' => t('URL path settings'),
      'pathauto' => t('Pathauto flag: generate automatic URL alias'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // Map JSON names to simple content type fields and subfields.
    $this->addSimpleMappings(array('title'));
    $this->addFieldMapping('field_uaqs_summary_short', 'uaqs_summary_short');
    $this->addSimpleMappings(array('path'));
    $this->addFieldMapping('pathauto', 'pathauto')
         ->defaultValue(0);
    $this->addSimpleMappings(array('field_uaqs_body'));
    // Allow limited HTML markup in the page body field.
    $this->addFieldMapping('field_uaqs_body:format')
         ->defaultValue('uaqs_unconstrained');

  }

}
