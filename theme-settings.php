<?php
/**
* Implements hook_form_system_theme_settings_alter().
*
* @param $form
*   Nested array of form elements that comprise the form.
* @param $form_state
*   A keyed array containing the current state of the form.
*/
function ua_zen_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL)  {
// Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }
//Add secondary logo upload field to theme settings. Code source: mjharmon's research on Drupal core & his own knowledge of Drupal internals and development doctrine
//this approach sidesteps the need to mark the file as permanent - which the earlier technique did require because it never copied the file from PHP's temporary 
//holding space. This technique also gives the field a "stock" feel to the user, rather than the bolt on feel the prior solution created.
  $form['logo']['settings']['footer_logo_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to custom footer logo'),
    '#description' => t('The path to the file you would like to use as your logo file instead of the default logo.'),
    '#default_value' => theme_get_setting('footer_logo_path'),
  );
  $form['logo']['settings']['footer_logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Upload footer logo image'),
    '#maxlength' => 40,
    '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
  );

  $form['#validate'][] = 'ua_zen_settings_form_validate';
  $form['#submit'][] = 'ua_zen_settings_form_submit';

/*$form['ua_zen_example'] = array(
'#type'          => 'checkbox',
'#title'         => t('ua_zen sample setting'),
'#default_value' => theme_get_setting('ua_zen_example'),
'#description'   => t("This option doesn't do anything; it's just an example."),
);
// */

// Remove some of the base theme's settings.
/* -- Delete this line if you want to turn off this setting.
unset($form['themedev']['zen_wireframes']); // We don't need to toggle wireframes on this site.
// */

// We are editing the $form in place, so we don't need to return anything.
}

function ua_zen_settings_form_validate($form, &$form_state) {
//validate the incoming file appropriately.
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


  if (!empty($form_state ['values']['footer_logo_path'])) {
    $str_path = _system_theme_settings_validate_path($form_state['values']['footer_logo_path']);
    if (!$str_path) {
      form_set_error('footer_logo_path', t('The custom logo path is invalid.'));
    }
  }
}


/**
* Implements hook_settings_form_submit().
*/
function ua_zen_settings_form_submit($form, &$form_state) {
  $ary_values = $form_state['values'];
  $str_filename = "";

  // If the user uploaded a new logo or favicon, save it to a permanent location
  // and use it in place of the default theme-provided file.
  if (!empty($ary_values['footer_logo_upload'])) {
    $obj_file = $ary_values['footer_logo_upload'];
    unset($form_state['values']['footer_logo_upload']);
    $str_filename = file_unmanaged_copy($obj_file->uri, NULL, FILE_EXISTS_REPLACE);
    $ary_values['footer_logo_path'] = $str_filename;
  }

//if the path as been entered (either automatically or directly) check that it exists. Only store it if does.
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
