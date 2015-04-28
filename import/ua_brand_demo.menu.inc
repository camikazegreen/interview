<?php

/**
 * @file
 * Migrations for Menu items.
 */

class UaBrandDemoMenu extends Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->description = t('Import menu items.');
    $this->dependencies = array('UaBrandDemoPage');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mlid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of destination link',
        ),
      ),
      MigrateDestinationMenuLinks::getKeySchema()
    );

    $import_path = drupal_get_path('module', 'ua_brand_demo') . '/import/data/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'ua_brand_demo.menu.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationMenuLinks();

    $this->addFieldMapping('menu_name', 'menu');
    $this->addFieldMapping('plid', 'ref_parent')->sourceMigration($this->getMachineName());
    $this->addFieldMapping('link_path', 'path');
    $this->addFieldMapping('router_path')->defaultValue('node/%');
    $this->addFieldMapping('link_title', 'title');
    $this->addFieldMapping('external')->defaultValue('0');
    $this->addFieldMapping('expanded')->defaultValue('0');
    $this->addFieldMapping('weight','weight');
    $this->addFieldMapping('customized')->defaultValue('1');
    $this->addFieldMapping('has_children')->defaultValue('0');
    $this->addFieldMapping('depth')->defaultValue('1');
  }

  function prepareRow($row) {
    // Convert the alias to the node path.
    $node_path = drupal_lookup_path('source', $row->path);
    if ($node_path == FALSE) {
      return FALSE;
    }

    $row->path = $node_path;
  }

  protected function csvcolumns() {
    $columns[0] = array('mlid', 'Menu link ID');
    $columns[1] = array('menu', 'Menu name');
    $columns[2] = array('path', 'Path');
    $columns[3] = array('title', 'Title');
    $columns[4] = array('ref_parent', 'Parent');
    $columns[5] = array('weight', 'Weight');
    return $columns;
  }

}
