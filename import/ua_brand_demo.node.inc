<?php

/**
 * @file
 * Migrations for Basic Nodes.
 */

class UaBrandDemoNode extends Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->description = t('Import nodes.');

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

    $import_path = drupal_get_path('module', 'ua_brand_demo') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'ua_brand_demo.node.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('page');

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
