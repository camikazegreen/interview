<?php
/**
 * @file
 * uaqs_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uaqs_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uaqs_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'UAQS News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Slide Image */
  $handler->display->display_options['fields']['field_uaqs_photo']['id'] = 'field_uaqs_photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['table'] = 'field_data_field_uaqs_photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['field'] = 'field_uaqs_photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_photo']['element_wrapper_class'] = 'uaqs-news-photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uaqs_photo']['settings'] = array(
    'image_style' => 'uaqs_spotlight',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_uaqs_photo']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_uaqs_photo']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_uaqs_photo']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'uaqs-news-title';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['field_uaqs_published']['id'] = 'field_uaqs_published';
  $handler->display->display_options['fields']['field_uaqs_published']['table'] = 'field_data_field_uaqs_published';
  $handler->display->display_options['fields']['field_uaqs_published']['field'] = 'field_uaqs_published';
  $handler->display->display_options['fields']['field_uaqs_published']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_published']['element_wrapper_class'] = 'uaqs-news-published';
  $handler->display->display_options['fields']['field_uaqs_published']['type'] = 'ap_date';
  $handler->display->display_options['fields']['field_uaqs_published']['settings'] = array(
    'interval' => 2,
    'interval_display' => 'time ago',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_uaqs_summary']['id'] = 'field_uaqs_summary';
  $handler->display->display_options['fields']['field_uaqs_summary']['table'] = 'field_data_field_uaqs_summary';
  $handler->display->display_options['fields']['field_uaqs_summary']['field'] = 'field_uaqs_summary';
  $handler->display->display_options['fields']['field_uaqs_summary']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_summary']['element_wrapper_class'] = 'uaqs-news-summary';
  /* Sort criterion: Content: Published (field_uaqs_published) */
  $handler->display->display_options['sorts']['field_uaqs_published_value']['id'] = 'field_uaqs_published_value';
  $handler->display->display_options['sorts']['field_uaqs_published_value']['table'] = 'field_data_field_uaqs_published';
  $handler->display->display_options['sorts']['field_uaqs_published_value']['field'] = 'field_uaqs_published_value';
  $handler->display->display_options['sorts']['field_uaqs_published_value']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uaqs_news' => 'uaqs_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'row';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'column col-sm-12 card-block';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'uaqs_teaser_list';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'news';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'News';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'home_3_col_news_block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'row';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-sm-4';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Slide Image */
  $handler->display->display_options['fields']['field_uaqs_photo']['id'] = 'field_uaqs_photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['table'] = 'field_data_field_uaqs_photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['field'] = 'field_uaqs_photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_photo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_uaqs_photo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_uaqs_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_photo']['element_wrapper_class'] = 'uaqs-news-photo';
  $handler->display->display_options['fields']['field_uaqs_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uaqs_photo']['settings'] = array(
    'image_style' => 'uaqs_spotlight',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_uaqs_photo']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_uaqs_photo']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_uaqs_photo']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'uaqs-news-title';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['field_uaqs_published']['id'] = 'field_uaqs_published';
  $handler->display->display_options['fields']['field_uaqs_published']['table'] = 'field_data_field_uaqs_published';
  $handler->display->display_options['fields']['field_uaqs_published']['field'] = 'field_uaqs_published';
  $handler->display->display_options['fields']['field_uaqs_published']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_published']['element_wrapper_class'] = 'uaqs-news-published';
  $handler->display->display_options['fields']['field_uaqs_published']['type'] = 'ap_date';
  $handler->display->display_options['fields']['field_uaqs_published']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_uaqs_summary']['id'] = 'field_uaqs_summary';
  $handler->display->display_options['fields']['field_uaqs_summary']['table'] = 'field_data_field_uaqs_summary';
  $handler->display->display_options['fields']['field_uaqs_summary']['field'] = 'field_uaqs_summary';
  $handler->display->display_options['fields']['field_uaqs_summary']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_summary']['element_wrapper_class'] = 'uaqs-news-summary';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Published (field_uaqs_published) */
  $handler->display->display_options['sorts']['field_uaqs_published_value']['id'] = 'field_uaqs_published_value';
  $handler->display->display_options['sorts']['field_uaqs_published_value']['table'] = 'field_data_field_uaqs_published';
  $handler->display->display_options['sorts']['field_uaqs_published_value']['field'] = 'field_uaqs_published_value';
  $handler->display->display_options['sorts']['field_uaqs_published_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uaqs_news' => 'uaqs_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Home News Block';
  $export['uaqs_news'] = $view;

  return $export;
}
