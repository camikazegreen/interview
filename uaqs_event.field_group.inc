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
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-summary field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_summary|node|uaqs_event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Card block');
  t('Center');
  t('Link');
  t('Summary fields');

  return $field_groups;
}
