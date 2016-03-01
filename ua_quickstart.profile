<?php
/**
 * @file
 * Enables modules and site configuration for a UA QuickStart site installation.
 */

/**
 * Set profile-specific flags for the installation..
 *
 * @param $install_state
 *   An array of information about the current installation state.
 */
function ua_quickstart_install_flags(&$install_state) {
  variable_set('uaqs_verbose', $install_state['uaqs_verbosity']);
}

/**
 * Implements hook_install_tasks_alter().
 *
 * We need to insert our flag-setting hack after we can modify an existing
 * form to include the flag settings, after there's a database in which
 * to store variables, but before installing most of the package's modules.
 *
 * @param $tasks
 *   The array of all available installation tasks.
 * @param $install_state
 *   The array of information about the current installation state.
 */
function ua_quickstart_install_tasks_alter(&$tasks, $install_state) {
  $flaghack = array('ua_quickstart_install_flags' => array());
  $offset = array_search('install_bootstrap_full', array_keys($tasks));
  $tasks = array_merge(array_slice($tasks, 0, $offset), $flaghack, array_slice($tasks, $offset));
}

/**
 * Pre-process the UA Quickstart additions to the validation handler.
 *
 * The submit handler will not see our additional field states in
 * $form_state['values'], so we have to copy them to $form_state['storage']
 * instead. The blog post
 * https://www.previousnext.com.au/blog/collecting-and-writing-configuration-settings-settingphp-install-profile
 * gives an example of the same approach.
 *
 * @param $form
 *   The nested array of form elements that defines the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function uaqs_install_settings_form_validate($form, &$form_state) {
  global $install_state;
  $form_state['storage']['uaqs_verbosity'] = $form_state['values']['uaqs_verbosity'];
}

/**
 * Pre-process the UA Quickstart additions to the submit handler.
 *
 * @param $form
 *   The nested array of form elements that defines the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function uaqs_install_settings_form_submit($form, &$form_state) {
  global $install_state;
  $install_state['uaqs_verbosity'] = (! empty($form_state['storage']['uaqs_verbosity']));
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Note that this is an ugly hack: we're trying to force our additional
 * form fields into the same form that Drupal Core is using to record the
 * database configuration settings. Instead, we should provide a distinct form
 * with its own handlers for these extras, but at the moment that would mean
 * presenting the user with another complete configuration screen for just
 * two radio buttons. See http://drupal.org/node/1153646 for more discussion.
 *
 * @param $form
 *   The nested array of form elements that defines the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function system_form_install_settings_form_alter(&$form, &$form_state) {
  $form['uaqs_verbosity'] = array(
    '#type' => 'radios',
    '#title' => st('How much detail to show in optional messages during installation'),
    '#options' => array(
      0 => st('Terse (for normal users)'),
      1 => st('Verbose (for developers)'),
    ),
    '#default_value' => 0,
  );
  $form['#validate'] = array(
    'uaqs_install_settings_form_validate',
    'install_settings_form_validate',
  );
  $form['actions']['save']['#submit'] = array(
    'uaqs_install_settings_form_submit',
    'install_settings_form_submit',
  );
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ua_quickstart_form_install_configure_form_alter(&$form, &$form_state) {
  // Hide some messages from various modules that are just too chatty!
  drupal_get_messages('status');
  drupal_get_messages('warning');

  // Set a default country and timezone.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Phoenix';

  // Disable JS timezone detection.  It doesn't seem to work reliably for AZ.
  $key = array_search('timezone-detect', $form['server_settings']['date_default_timezone']['#attributes']['class']);
  if ($key !== FALSE) {
    unset($form['server_settings']['date_default_timezone']['#attributes']['class'][$key]);
  }
}
