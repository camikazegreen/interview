<?php
/**
 * @file
 * ua_navigation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ua_navigation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_secondary_links_source';
  $strongarm->value = 'ua-utility-links';
  $export['menu_secondary_links_source'] = $strongarm;

  return $export;
}
