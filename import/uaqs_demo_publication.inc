<?php

/**
 * @file
 * Add content to demonstrate the UA Publication feature.
 */

/**
 * Makes demonstration UA Publication taxonomy terms from pre-defined data.
 *
 * Terms come from a local JSON-formatted text file.
 *
 * @see UaDemoTermMigration
 */
class UaDemoPublicationTermMigration extends UaDemoTermMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'research_categories',
      t('Add demonstration UA Publication taxonomy terms to a vocabulary.'));
  }

}

/**
 * Makes demonstration UA Publication content from pre-defined data.
 *
 * The content from most of the UA Publication fields comes from a JSON file,
 * but note that the entity reference field (related publications) might
 * not be populated.
 */
class UaDemoPublicationMigration extends UaDemoNodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'ua_pub',
      t('Make demonstration UA Publication content from pre-defined data.'));

    // Documented lists of source data fields: all names here MUST match
    // those in the corresponding content type.
    // @see ua_publication ua_publication.features.field_instance.inc
    // First, the node title and path alias fields...
    $title_fields = array(
      'title' => t('Title'),
      'path' => t('URL path settings'),
    );
    // The single-value text fielda...
    $single_value_fields = array(
      'ua_pub_description' => t('Description'),
      'ua_pub_date' => t('Published'),
    );
    // Multi-value fields...
    $multi_value_fields = array(
      'ua_pub_authors' => t('Authors'),
      'ua_pub_addinfo' => t('Additional information (link)'),
      'ua_pub_related_pubs' => t('Related publications (entity references)'),
      'ua_pub_research_categories' => t('Research categories (term references)'),
    );
    $link_title_fields = array(
      'ua_pub_addinfo_title' => t('Information link title'),
    );
    // Image fields...
    $image_src_field = 'ua_pub_photo';
    $image_fields = array(
      $image_src_field => t('Publication photo filename'),
      $image_src_field . '_alt' => t('Alternate text'),
    );

    // All the fields to migrate.
    $fields = $this->getSourceKeyField() + $title_fields + $single_value_fields + $multi_value_fields + $link_title_fields + $image_fields;

    // Source definition.
    $this->source = new MigrateSourceJSON($this->jsonFilePath(), $this->getSourceKeyFieldName(), $fields);

    // The title and path have no prefix.
    $this->addSimpleMappings(array('title'));
    $this->addSimpleMappings(array('path'));

    // One-to-one correspondence: JSON names and simple content type fields.
    foreach (array_keys($single_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field);
    }

    // Multi-value fields).
    foreach (array_keys($multi_value_fields) as $src_field) {
      $this->addFieldMapping('field_' . $src_field, $src_field)
           ->separator('|');
    }

    // Link title is a special case.
    $this->addFieldMapping('field_ua_pub_addinfo:title', 'ua_pub_addinfo_title')
        ->separator('|');

    // Image.
    $image_dst_field = 'field_' . $image_src_field;
    $this->addFieldMapping($image_dst_field, $image_src_field);
    $this->addFieldMapping($image_dst_field . ':file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping($image_dst_field . ':file_class')
         ->defaultValue('MigrateFileUri');
    $this->addFieldMapping($image_dst_field . ':source_dir')
         ->defaultValue($this->imagePath());
    // Image alt field.
    $this->addFieldMapping($image_dst_field . ':alt', $image_src_field . '_alt');

    // Allow limited HTML markup in the description field.
    $this->addFieldMapping('field_ua_pub_description:format')
         ->defaultValue('filtered_html');
  }

}
