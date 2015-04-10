<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Custom function for the secondary footer logo option
 */
function ua_zen_footer_logo() {
  $ialias = '/';
  $ifid = theme_get_setting('footer_logo_file');
  if ($ifid) {
    $ifile = file_load($ifid);
    if ($ifile) {
      $iuri = $ifile->uri;
      $ipath = file_create_url($iuri);
      $ipath = parse_url($ipath);
      $ialias = $ipath['path'];
    }
  }  
  return $ialias;
}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  ua_zen_preprocess_html($variables, $hook);
  ua_zen_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

function ua_zen_preprocess_html(&$variables) {
  // Add external stylesheets from UA
  // drupal_add_css('https://catstrap.css', array('type' => 'external'));

}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

function ua_zen_preprocess_page(&$variables, $hook) {

  //Allows there to be a template file for the UA Header and Footers without allowing blocks to be placed there - regions defined in .info, but commented out
  if (!isset($variables['page']['header_ua']) || empty($variables['page']['header_ua'])) {
    $variables['page']['header_ua'] = array(
      '#region' => 'header_ua',
      '#weight' => '-10',
      '#theme_wrappers' => array('region'));
  }
  if (!isset($variables['page']['footer_ua']) || empty($variables['page']['footer_ua'])) {
    $variables['page']['footer_ua'] = array(
      '#region' => 'footer_ua',
      '#weight' => '-10',
      '#theme_wrappers' => array('region'));
  }
  if (!isset($variables['page']['footer_ua_hidden']) || empty($variables['page']['footer_ua_hidden'])) {
    $variables['page']['footer_ua_hidden'] = array(
      '#region' => 'footer_ua_hidden',
      '#weight' => '-10',
      '#theme_wrappers' => array('region'));
  }

}


/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // ua_zen_preprocess_node_page() or ua_zen_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
function ua_zen_preprocess_region(&$variables, $hook) {
  if ($variables['region'] == 'footer') {
    $variables['ua_zen_footer_logo'] = ua_zen_footer_logo();
    $variables['logo'] = theme_get_setting('logo'); // Make logo available in footer region for display logic
  }
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
 * Implements theme_form_search_block_form_alter
 */
function ua_zen_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['placeholder'] = t('Search Site');
  $form['search_block_form']['#attributes']['onfocus'] = "this.placeholder = ''";
  $form['search_block_form']['#attributes']['onblur'] = "this.placeholder = '" . t('Search Site') . "'";
}