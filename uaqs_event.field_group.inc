<?php
/**
 * @file
 * uaqs_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_block|node|uaqs_event|uaqs_card';
  $field_group->group_name = 'group_card_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = 'group_link';
  $field_group->data = array(
    'label' => 'Card block',
    'weight' => '1',
    'children' => array(
      0 => 'group_center_title',
      1 => 'group_center',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card block',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-block',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_block|node|uaqs_event|uaqs_card'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center_title|node|uaqs_event|uaqs_card';
  $field_group->group_name = 'group_center_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = 'group_card_block';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '19',
    'children' => array(
      0 => 'title_field',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-center text-red',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_center_title|node|uaqs_event|uaqs_card'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center|node|uaqs_event|uaqs_card';
  $field_group->group_name = 'group_center';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = 'group_card_block';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '18',
    'children' => array(
      0 => 'field_uaqs_date',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-center h5 bold text-red',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_center|node|uaqs_event|uaqs_card'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_col_one|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_col_one';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Column one',
    'weight' => '43',
    'children' => array(
      0 => 'group_short_date',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Column one',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-xs-4 col-md-2',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_col_one|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_col_two|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_col_two';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Column two',
    'weight' => '44',
    'children' => array(
      0 => 'group_summary',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Column two',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-xs-8 col-md-10',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_col_two|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_day|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_day';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_short_date';
  $field_group->data = array(
    'label' => 'Day',
    'weight' => '49',
    'children' => array(
      0 => 'uaqs_event_day_short',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Day',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'h3 text-center margin-zero-top margin-zero-bottom',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_day|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_heading|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_heading';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_summary';
  $field_group->data = array(
    'label' => 'Heading',
    'weight' => '53',
    'children' => array(
      0 => 'group_text_red_30b',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Heading',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'h4 margin-zero-top',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_heading|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link|node|uaqs_event|uaqs_card';
  $field_group->group_name = 'group_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '0',
    'children' => array(
      0 => 'group_card_block',
    ),
    'format_type' => 'link',
    'format_settings' => array(
      'label' => 'Link',
      'instance_settings' => array(
        'link_to' => 'field_uaqs_link',
        'custom_url' => '',
        'custom_url_normalize' => 0,
        'target' => 'default',
        'classes' => 'list-link-block no-margin no-padding',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_link|node|uaqs_event|uaqs_card'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '0',
    'children' => array(
      0 => 'group_row',
    ),
    'format_type' => 'link',
    'format_settings' => array(
      'label' => 'Link',
      'instance_settings' => array(
        'link_to' => 'entity',
        'custom_url' => '',
        'custom_url_normalize' => 0,
        'target' => 'default',
        'classes' => 'uaqs-event-row',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_link|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_margin_align_bottom|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_margin_align_bottom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_summary';
  $field_group->data = array(
    'label' => 'Align bottom',
    'weight' => '54',
    'children' => array(
      0 => 'field_uaqs_summary',
      1 => 'group_strong',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Align bottom',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-ash',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_margin_align_bottom|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_body|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_media_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Media body',
    'weight' => '23',
    'children' => array(
      0 => 'field_uaqs_date',
      1 => 'title_field',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media body',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-body',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_media_body|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_object|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_media_object';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Media object',
    'weight' => '24',
    'children' => array(
      0 => 'uaqs_event_month_short',
      1 => 'uaqs_event_day_short',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media object',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-object',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_media_object|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_link';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '9',
    'children' => array(
      0 => 'group_media_body',
      1 => 'group_media_object',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_media|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_month|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_month';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_short_date';
  $field_group->data = array(
    'label' => 'Month',
    'weight' => '47',
    'children' => array(
      0 => 'uaqs_event_month_short',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Month',
      'instance_settings' => array(
        'id' => '',
        'classes' => ' h5 text-center margin-zero-top margin-zero-bottom text-uppercase',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_month|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_link';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '39',
    'children' => array(
      0 => 'group_col_one',
      1 => 'group_col_two',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_row|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_short_date|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_short_date';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_col_one';
  $field_group->data = array(
    'label' => 'Short Date',
    'weight' => '58',
    'children' => array(
      0 => 'group_day',
      1 => 'group_month',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Short Date',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'bg-ash-tint event-date card-block embed-responsive-item',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_short_date|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_strong|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_strong';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_margin_align_bottom';
  $field_group->data = array(
    'label' => 'Strong',
    'weight' => '14',
    'children' => array(
      0 => 'field_uaqs_date',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Strong',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-ash',
        'element' => 'strong',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_strong|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary|node|uaqs_event|form';
  $field_group->group_name = 'group_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summary fields',
    'weight' => '13',
    'children' => array(
      0 => 'field_uaqs_link',
      1 => 'field_uaqs_short_title',
      2 => 'field_uaqs_summary',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Summary fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-summary field-group-tab',
        'description' => 'For use in feeds and content listings.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_summary|node|uaqs_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_col_two';
  $field_group->data = array(
    'label' => 'Summary',
    'weight' => '52',
    'children' => array(
      0 => 'group_heading',
      1 => 'group_margin_align_bottom',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Summary',
      'instance_settings' => array(
        'id' => '',
        'classes' => ' bg-ash-tint card-block',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_summary|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_red_30b|node|uaqs_event|uaqs_med_media_list';
  $field_group->group_name = 'group_text_red_30b';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_event';
  $field_group->mode = 'uaqs_med_media_list';
  $field_group->parent_name = 'group_heading';
  $field_group->data = array(
    'label' => 'Dark red text',
    'weight' => '61',
    'children' => array(
      0 => 'title_field',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Dark red text',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-red30b',
        'element' => 'span',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_text_red_30b|node|uaqs_event|uaqs_med_media_list'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Align bottom');
  t('Card block');
  t('Center');
  t('Column one');
  t('Column two');
  t('Dark red text');
  t('Day');
  t('Heading');
  t('Link');
  t('Media');
  t('Media body');
  t('Media object');
  t('Month');
  t('Row');
  t('Short Date');
  t('Strong');
  t('Summary');
  t('Summary fields');

  return $field_groups;
}
