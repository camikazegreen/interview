<?php

/**
 * @file
 * Migrations for Basic Nodes.
 */

class UaDemoPage extends Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->description = t('Import sample pages.');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $import_path = drupal_get_path('module', 'ua_demo') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'ua_demo.page.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('ua_page');

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('filtered_html');
    $this->addFieldMapping('created', 'created');
  }

  protected function csvcolumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('path', 'Path');
    $columns[2] = array('body', 'Body');
    $columns[3] = array('created', 'Created');
    return $columns;
  }

}

class UaDemoCarouselItem extends Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->description = t('Import sample carousel items.');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $import_path = drupal_get_path('module', 'ua_demo') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'ua_demo.carousel_item.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('ua_carousel_item');

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_slide_image', 'image');
    $this->addFieldMapping('field_slide_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_slide_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'ua_demo') . '/import/images');
    $this->addFieldMapping('field_call_to_action', 'url');
    $this->addFieldMapping('field_call_to_action:title', 'action');
    $this->addFieldMapping('field_short_summary', 'summary');
    $this->addFieldMapping('created', 'created');
  }

  protected function csvcolumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('image', 'Image');
    $columns[2] = array('action', 'Call to action');
    $columns[3] = array('url', 'Link');
    $columns[4] = array('summary', 'Summary');
    $columns[5] = array('created', 'Created');
    return $columns;
  }

}
