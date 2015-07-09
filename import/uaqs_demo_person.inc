<?php

/**
 * @file
 * Add content to demonstrate the UA Person feature.
 */

/**
 * Makes demonstration UA Person content from pre-defined data.
 *
 * Most of the content in the UA Person Drupal nodes comes directly from a
 * JSON file, but the alt text for the images gets created on the fly by
 * concatenating the contents of the name fields.
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoPersonMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_person',
      t('Make demonstration UA Person content from pre-defined data.'));

    // Documented lists of source data fields:.
    // @see ua_person ua_person.features.field_instance.inc
    // First, the single-value text fielda...
    $single_value_fields = array(
      'ua_person_lname'  => t('Last Name'),
      'ua_person_fname'  => t('First Name'),
      'ua_person_email'  => t('E-mail'),
      'ua_person_addresses' => t('Office location(s))'),
      'ua_person_bio'    => t('Biography'),
    );
    // Then the multi-value text fields...
    $multi_value_fields = array(
      'ua_person_phones' => t('Phone Number(s)'),
      'ua_person_titles' => t('Job Title(s)'),
    );
    // Image fields need special treatment, isolate them...
    $image_src_field = 'ua_person_photo';
    $image_fields = array(
      $image_src_field => t('Photo filename'),
      'image_alt_text' => t('Photo alt text (derived from other fields)'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $single_value_fields + $multi_value_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // One-to-one correspondence: JSON names and simple content type fields.
    foreach (array_keys($single_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Multi-value fields need an explicit sparator.
    foreach (array_keys($multi_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field)
           ->separator('|');
    }

    // Image fields are more complicated.
    $image_dst_field = 'field_' . $image_src_field;
    $this->addFieldMapping($image_dst_field, $image_src_field);
    $this->addFieldMapping($image_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping($image_dst_field . ':alt', 'image_alt_text');
    // MigrateFileUri works for a local filespec as well as remote URIs.
    $this->addFieldMapping($image_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($image_dst_field . ':source_dir')
         ->defaultValue($this->imagePath());

    // Allow limited HTML markup in the bio field.
    $this->addFieldMapping('field_ua_person_bio:format')
         ->defaultValue('filtered_html');
  }

  /**
   * Implementation of prepareRow(), to concatenate some raw field values.
   *
   * See the Migration migrate_example code, in particular wine.inc.
   *
   * @param $row
   *   Object containing raw source data (from the JSON file).
   *
   * @return bool
   *   TRUE to process this row, FALSE to have the source skip it.
   */
  public function prepareRow($row) {
    // Recommended boilerplate section: invoke the parent classes on the
    // current row first, and pass on their status (whether to process
    // or skip the row).
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Concatenate names and suffix into one derived field.
    $row->image_alt_text = implode(' ', array(
      $row->ua_person_fname,
      $row->ua_person_lname,
      'portrait',
    ));
    return TRUE;
  }

}
