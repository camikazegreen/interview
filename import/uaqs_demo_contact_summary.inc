<?php

/**
 * @file
 * Add content to demonstrate a UA Contact Summary block.
 */

/**
 * Makes demonstration UA Contact Summary bean content from pre-defined data.
 *
 * The UA Block Types feature for fieldable blocks based on the Bean module
 * provides the entity used for this.
 *
 * The field contents come from a JSON file.
 */
class UaDemoContactSummaryMigration extends UaDemoBeanMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_contact_summary',
      t('Make demonstration UA Contact Summary content from pre-defined data.'));

    // Documented lists of source data fields.
    // See ua_block_types.features.field_instance.inc.
    $data_fields = array(
      'label' => t('Descriptive title that the administrative interface uses'),
      'ua_contact_address' => t('Postal address'),
      'ua_contact_email' => t('Email address'),
      'ua_contact_phone' => t('Phone number'),
    );

    // Titles for links...
    $link_title_fields = array(
      'ua_contact_email_title' => t('Email address title'),
      'ua_contact_phone_title' => t('Phone number title'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $data_fields + $link_title_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // JSON names to fields mappings.
    $this->addSimpleMappings(array('label'));

    $this->addFieldMapping('field_ua_contact_address', 'ua_contact_address')
         ->separator('|');
    $this->addFieldMapping('field_ua_contact_email', 'ua_contact_email');
    $this->addFieldMapping('field_ua_contact_phone', 'ua_contact_phone');

    $this->addFieldMapping('field_ua_contact_email:title', 'ua_contact_email_title');
    $this->addFieldMapping('field_ua_contact_phone:title', 'ua_contact_phone_title');
  }

}
