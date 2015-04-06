<?php
/**
 * @file
 * ua_brand_navigation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ua_brand_navigation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
