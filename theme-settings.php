<?php
/**
 * Implements hook_form_system_theme_settings_alter().
 */
function ua_zen_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  // Add secondary logo upload field to theme settings. Code source: mjharmon's
  // research on Drupal core & his own knowledge of Drupal internals and
  // development doctrine this approach sidesteps the need to mark the file as
  // permanent - which the earlier technique did require because it never
  // copied the file from PHP's temporary holding space. This technique also
  // gives the field a "stock" feel to the user, rather than the bolt on feel
  // the prior solution created.
  $form['logo']['settings']['footer_logo_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to custom footer logo'),
    '#description' => t('The path to the file you would like to use as your footer logo file instead of the logo in the header.'),
    '#default_value' => theme_get_setting('footer_logo_path'),
  );

  $form['logo']['settings']['footer_logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Upload footer logo image'),
    '#maxlength' => 40,
    '#description' => t("If you don't have direct file access to the server, use this field to upload your footer logo."),
  );

  $form['ua_settings']['settings']['ua_copyright_notice'] = array(
    '#type' => 'textfield',
    '#title' => t('Copyright notice'),
    '#description' => t('A copyright notice for this site. The value here will appear after a "Copyright YYYY" notice (where YYYY is the current year).'),
    '#default_value' => theme_get_setting('ua_copyright_notice'),
  );

  $form['#validate'][] = 'ua_zen_settings_form_validate';
  $form['#submit'][] = 'ua_zen_settings_form_submit';

  // We are editing the $form in place, so we don't need to return anything.
}

/**
 * Custom validation handler for theme settings form.
 */
function ua_zen_settings_form_validate($form, &$form_state) {
  // Validate the incoming file appropriately.
  $ary_validators = array('file_validate_is_image' => array(), 'file_validate_extensions' => array('png gif jpg jpeg'));
  $str_path = "";
  // Check for a new uploaded logo.
  $obj_file = file_save_upload('footer_logo_upload', $ary_validators);

  if (isset($obj_file)) {
    // File upload was attempted.
    if ($obj_file) {
      // Put the temporary file in form_values so we can save it on submit.
      $form_state['values']['footer_logo_upload'] = $obj_file;
    }
    else {
      // File upload failed.
      form_set_error('footer_logo_upload', t('The footer logo could not be uploaded.'));
    }
  }

  if (!empty($form_state['values']['footer_logo_path'])) {
    $str_path = _system_theme_settings_validate_path($form_state['values']['footer_logo_path']);
    if (!$str_path) {
      form_set_error('footer_logo_path', t('The custom logo path is invalid.'));
    }
  }
}

/**
 * Custom submit handler for theme settings form.
 */
function ua_zen_settings_form_submit($form, &$form_state) {
  $ary_values = $form_state['values'];
  $str_filename = "";

  // If the user uploaded a new logo, save it to a permanent location.
  if (!empty($ary_values['footer_logo_upload'])) {
    $obj_file = $ary_values['footer_logo_upload'];
    unset($form_state['values']['footer_logo_upload']);
    $str_filename = file_unmanaged_copy($obj_file->uri, NULL, FILE_EXISTS_REPLACE);
    $ary_values['footer_logo_path'] = $str_filename;
  }

  // If the path as been entered (either automatically or directly) check that
  // it exists. Only store it if does.
  if (!empty($ary_values['footer_logo_path'])) {
    $str_filename = _system_theme_settings_validate_path($ary_values['footer_logo_path']);
    if ($str_filename === FALSE) {
      $form_state['values']['footer_logo_path'] = "";
    }
    else {
      $form_state['values']['footer_logo_path'] = $str_filename;
    }
  }
}
