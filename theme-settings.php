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

  //Add secodary logo upload field to theme settings. Code source: http://stackoverflow.com/questions/12177175/how-do-i-properly-add-file-field-in-drupal-form-via-theme-setting-php
  $form['logo']['footer_logo_file'] = array(
    '#type' => 'managed_file',
    '#required' => FALSE,
    '#title' => t('Footer logo'),
    '#description' => t('The uploaded logo will be displayed in the site\'s footer. If no logo is specified, the main logo for the site will be used.'),
    '#default_value' => theme_get_setting('footer_logo_file'),
    '#upload_location' => 'public://theme/',
    '#upload_validators' => array(
          'file_validate_extensions' => array('gif png jpg jpeg'),
        ),
  );

  // Create the form using Forms API: http://api.drupal.org/api/7

  /* -- Delete this line if you want to use this setting
  $form['ua_zen_example'] = array(
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
