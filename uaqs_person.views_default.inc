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
  $handler->display->display_options['css_class'] = 'ua-person-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'image_style' => 'ua_medium_square',
    'image_link' => 'content',
  );
  /* Field: Content: Full Name (node title) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Content: Full Name (node title)';
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
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_ua_person_email']['id'] = 'field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['table'] = 'field_data_field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['field'] = 'field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_email']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_ua_person_photo' => 0,
    'title' => 0,
    'field_ua_person_titles' => 0,
    'field_ua_person_phones' => 0,
  );
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

  /* Display: Grid Page */
  $handler = $view->new_display('page', 'Grid Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'ua-person-grid';
  $handler->display->display_options['path'] = 'people';

  /* Display: Row Page */
  $handler = $view->new_display('page', 'Row Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'ua-person-row row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_ua_person_photo']['id'] = 'field_ua_person_photo';
  $handler->display->display_options['fields']['field_ua_person_photo']['table'] = 'field_data_field_ua_person_photo';
  $handler->display->display_options['fields']['field_ua_person_photo']['field'] = 'field_ua_person_photo';
  $handler->display->display_options['fields']['field_ua_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_photo']['element_wrapper_class'] = 'ua-person-photo col-sm-3';
  $handler->display->display_options['fields']['field_ua_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ua_person_photo']['settings'] = array(
    'image_style' => 'ua_medium_square',
    'image_link' => 'content',
  );
  /* Field: Content: Full Name (node title) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Content: Full Name (node title)';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_ua_person_titles']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ua_person_titles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_titles']['element_wrapper_class'] = 'ua-person-job-titles';
  $handler->display->display_options['fields']['field_ua_person_titles']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ua_person_titles']['multi_type'] = 'ul';
  /* Field: Content: Phone Number(s) */
  $handler->display->display_options['fields']['field_ua_person_phones']['id'] = 'field_ua_person_phones';
  $handler->display->display_options['fields']['field_ua_person_phones']['table'] = 'field_data_field_ua_person_phones';
  $handler->display->display_options['fields']['field_ua_person_phones']['field'] = 'field_ua_person_phones';
  $handler->display->display_options['fields']['field_ua_person_phones']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_phones']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ua_person_phones']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_phones']['element_wrapper_class'] = 'ua-person-phone';
  $handler->display->display_options['fields']['field_ua_person_phones']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ua_person_phones']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ua_person_phones']['multi_type'] = 'ul';
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_ua_person_email']['id'] = 'field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['table'] = 'field_data_field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['field'] = 'field_ua_person_email';
  $handler->display->display_options['fields']['field_ua_person_email']['label'] = '';
  $handler->display->display_options['fields']['field_ua_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ua_person_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ua_person_email']['element_wrapper_class'] = 'ua-person-email';
  /* Field: Custom text: Name and titles */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Custom text: Name and titles';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3 class="ua-person-name">[title]</h3>
<div class="ua-person-job-titles">[field_ua_person_titles]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'ua-person-col col-sm-5';
  /* Field: Custom text: Contact info */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Custom text: Contact info';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="ua-person-phone">[field_ua_person_phones]</div>
<div class="ua-person-email">[field_ua_person_email]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'ua-person-col col-sm-4';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_ua_person_photo' => 0,
    'title' => 0,
    'field_ua_person_titles' => 0,
    'field_ua_person_phones' => 0,
  );
  $handler->display->display_options['path'] = 'people-list';
  $export['ua_person_directory'] = $view;

  return $export;
}
