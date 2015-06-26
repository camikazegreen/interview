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
 * @see UaDemoPublicationMigration for more details.
 */
class UaDemoPublicationTermMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Add demonstration UA Publication taxonomy terms to a vocabulary.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    // Taxonomy term fields.
    $data_fields = array(
      'description' => t('Taxonomy term description'),
      'parent_name' => t('Nest under the term with this name'),
    );

    // Source key field.
    $id_field = 'name';
    $source_key = array($id_field => t('Unique key'));

    // All the fields to migrate.
    $fields = $source_key + $data_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    // Destination, giving the machine name of the vocabulary.
    $this->destination = new MigrateDestinationTerm('research_categories');

    // The usual migration map, keyed off the source term names.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        $id_field => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => $source_key[$id_field],
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // One-to-one correspondence: JSON names and taxonomy fields.
    $this->addSimpleMappings(array_keys($fields));
  }
}

/**
 * Makes demonstration UA Publication content from pre-defined data.
 *
 * Currently local files hold the sample data this uses to build the content,
 * in a single JSON-formatted text file and collection of images. The overall
 * approach is similar to the one illustrated for handling JSON imports in the
 * documentation for the Migrate module in the “Using MigrateSourceJSON”
 * subsection.
 *
 * @see https://www.drupal.org/node/1152160
 */
class UaDemoPublicationMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description =
      t('Make demonstration UA Publication content from pre-defined data.');

    // The demonstration data will be within this module's own directory.
    $our_path = drupal_get_path('module', 'ua_demo');

    // Documented lists of source data fields: all names here MUST match
    // those in the corresponding content type.
    // @see ua_publication ua_publication.features.field_instance.inc
    // First, the node title field
    $title_field = array(
      'title' => t('Title'),
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

    // Source key field (must have int values).
    $id_field = 'id';
    $source_key = array($id_field => t('Unique key (int)'));

    // All the fields to migrate.
    $fields = $source_key + $title_field + $single_value_fields + $multi_value_fields + $link_title_fields + $image_fields;

    // Source definition.
    $json_filename = drupal_strtolower($this->machineName) . '.json';
    $import_path = $our_path . '/import/data/';
    $this->source = new MigrateSourceJSON($import_path . $json_filename, $id_field, $fields);

    // Destination.
    $this->destination = new MigrateDestinationNode('ua_pub');

    // The usual migration map, keyed off the arbitrary source IDs.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        $id_field => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => $source_key[$id_field],
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // The title has no prefix
    $this->addSimpleMappings(array('title'));

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
         ->defaultValue($our_path . '/import/images');
    // Image alt field.
    $this->addFieldMapping($image_dst_field . ':alt', $image_src_field . '_alt');

    // Allow limited HTML markup in the description field
    $this->addFieldMapping('field_ua_pub_description:format')
         ->defaultValue('filtered_html');
  }
}
