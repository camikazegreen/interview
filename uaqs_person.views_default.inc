<?php
/**
 * @file
 * ua_person.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ua_person_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ua_person_directory';
  $view->description = 'Branded displays of the UA Person content type';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'UA Person Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'UA Person Directory';
  $handler->display->display_options['css_class'] = 'ua-person-grid';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'ua-person-row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_ua_person_photo']['id'] = 'field_ua_person_photo';
  $handler->display->display_options['fields']['field_ua_person_photo']['table'] = 'field_data_field_ua_person_photo';
  $handler->display->display_options['fields']['field_ua_person_photo']['field'] = 'field_ua_person_photo';
  $handler->display->display_options['fields']['field_ua_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_photo']['element_wrapper_class'] = 'ua-person-photo';
  $handler->display->display_options['fields']['field_ua_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ua_person_photo']['settings'] = array(
    'image_style' => 'ua_small_square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'ua-person-name';
  /* Field: Content: Job Title(s) */
  $handler->display->display_options['fields']['field_ua_person_titles']['id'] = 'field_ua_person_titles';
  $handler->display->display_options['fields']['field_ua_person_titles']['table'] = 'field_data_field_ua_person_titles';
  $handler->display->display_options['fields']['field_ua_person_titles']['field'] = 'field_ua_person_titles';
  $handler->display->display_options['fields']['field_ua_person_titles']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_titles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_titles']['element_wrapper_class'] = 'ua-person-job-titles';
  $handler->display->display_options['fields']['field_ua_person_titles']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ua_person_titles']['multi_type'] = 'ul';
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_ua_person_email']['id'] = 'field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['table'] = 'field_data_field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['field'] = 'field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_email']['element_wrapper_class'] = 'ua-person-email';
  /* Field: Content: Phone Number(s) */
  $handler->display->display_options['fields']['field_ua_person_phones']['id'] = 'field_ua_person_phones';
  $handler->display->display_options['fields']['field_ua_person_phones']['table'] = 'field_data_field_ua_person_phones';
  $handler->display->display_options['fields']['field_ua_person_phones']['field'] = 'field_ua_person_phones';
  $handler->display->display_options['fields']['field_ua_person_phones']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_phones']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_phones']['element_wrapper_class'] = 'ua-person-phone';
  $handler->display->display_options['fields']['field_ua_person_phones']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ua_person_phones']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ua_person_phones']['multi_type'] = 'ul';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ua_person' => 'ua_person',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people';
  $export['ua_person_directory'] = $view;

  return $export;
}
