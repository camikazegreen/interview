<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ua_brand_kickstart_form_install_configure_form_alter(&$form, &$form_state) {
  // Hide some messages from various modules that are just too chatty!
  drupal_get_messages('status');
  drupal_get_messages('warning');

  // Set a default country so we can benefit from it on Address Fields.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Phoenix';

  // Disable JS timezone detection.  It doesn't seem to work for AZ.
  $key = array_search('timezone-detect', $form['server_settings']['date_default_timezone']['#attributes']['class']);
  if ($key !== FALSE) {
    unset($form['server_settings']['date_default_timezone']['#attributes']['class'][$key]);
  }
}

/**
 * Prepares an executes database queries to insert blocks based on an array of
 * nested block data arrays.
 */
function ua_brand_kickstart_insert_blocks($blocks = array()) {
  $block_defaults = array(
    'status' => 1,
    'weight' => 0,
    'visibility' => 0,
    'pages' => '',
    'title' => '',
  );

  // Merge default values.
  if (!empty($blocks)) {
    $merged_blocks = array();
    foreach ($blocks as $block) {
      $merged_blocks[] = array_merge($block_defaults, $block);
    }
    $blocks = $merged_blocks;

    foreach ($blocks as $record) {
      db_insert('block')
        ->fields($record)
        ->execute();
    }
  }
}
