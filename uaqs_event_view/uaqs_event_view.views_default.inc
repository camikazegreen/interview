<?php
/**
 * @file
 * uaqs_event_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uaqs_event_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uaqs_events';
  $view->description = 'Lists of events made with the UAQS Event content type.';
  $view->tag = 'uaqs_event';
  $view->base_table = 'node';
  $view->human_name = 'UAQS Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = '';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'uaqs-event-row';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_uaqs_date']['id'] = 'field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['table'] = 'field_data_field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['field'] = 'field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_uaqs_date']['element_wrapper_class'] = 'uaqs-event-date';
  $handler->display->display_options['fields']['field_uaqs_date']['settings'] = array(
    'format_type' => 'event_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uaqs_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date']['delta_offset'] = '0';
  /* Sort criterion: Content: Event Date -  start date (field_uaqs_date) */
  $handler->display->display_options['sorts']['field_uaqs_date_value']['id'] = 'field_uaqs_date_value';
  $handler->display->display_options['sorts']['field_uaqs_date_value']['table'] = 'field_data_field_uaqs_date';
  $handler->display->display_options['sorts']['field_uaqs_date_value']['field'] = 'field_uaqs_date_value';
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
    'uaqs_event' => 'uaqs_event',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'second';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_uaqs_date.field_uaqs_date_value' => 'field_data_field_uaqs_date.field_uaqs_date_value',
    'field_data_field_uaqs_date.field_uaqs_date_value2' => 'field_data_field_uaqs_date.field_uaqs_date_value2',
  );

  /* Display: Full Calendar */
  $handler = $view->new_display('page', 'Full Calendar', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'uaqs-event-calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uaqs_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'uaqs_med_media_list';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<em>There are no events listed for this time span.</em>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_uaqs_date']['id'] = 'field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['table'] = 'field_data_field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['field'] = 'field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_uaqs_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_uaqs_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_uaqs_date']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_uaqs_date']['field_api_classes'] = TRUE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_uaqs_date_1']['id'] = 'field_uaqs_date_1';
  $handler->display->display_options['fields']['field_uaqs_date_1']['table'] = 'field_data_field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date_1']['field'] = 'field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date_1']['settings'] = array(
    'format_type' => 'uaqs_event_full_month_and_year',
    'custom_date_format' => '',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_uaqs_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_uaqs_date_1']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'calendar';

  /* Display: Event list block */
  $handler = $view->new_display('block', 'Event list block', 'list_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<hr>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<p>&nbsp;</p>
<div class="text-center"><a href="/calendar" class="btn btn-arrow btn-sand text-uppercase">View all events on the calendar</a></div>
<hr>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_uaqs_date']['id'] = 'field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['table'] = 'field_data_field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['field'] = 'field_uaqs_date';
  $handler->display->display_options['fields']['field_uaqs_date']['label'] = '';
  $handler->display->display_options['fields']['field_uaqs_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_uaqs_date']['element_wrapper_class'] = 'uaqs-event-date';
  $handler->display->display_options['fields']['field_uaqs_date']['settings'] = array(
    'format_type' => 'event_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uaqs_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_uaqs_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'uaqs-event-title';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['block_description'] = 'UAQS Event list block';

  /* Display: Event card group */
  $handler = $view->new_display('block', 'Event card group', 'card_group_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['display_description'] = 'Use in a region that spans at least 12 columns.';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Full Calendar »';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'uaqs_card';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<p>&nbsp;</p>
<div class="text-center"><a href="/calendar" class="btn btn-arrow btn-sand text-uppercase">View all events on the calendar</a></div>
<hr>';
  $handler->display->display_options['block_description'] = 'UAQS Event card group';
  $export['uaqs_events'] = $view;

  return $export;
}
