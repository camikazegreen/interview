<?php
/**
 * @file
 * ua_block_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ua_block_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_block_1|bean|ua_card|default';
  $field_group->group_name = 'group_card_block_1';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'ua_card';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card';
  $field_group->data = array(
    'label' => 'Card Block',
    'weight' => '12',
    'children' => array(
      0 => 'field_ua_blurb_text',
      1 => 'field_call_to_action',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Block',
      'instance_settings' => array(
        'classes' => 'card-block',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_card_block_1|bean|ua_card|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_header|bean|ua_card|default';
  $field_group->group_name = 'group_card_header';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'ua_card';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card';
  $field_group->data = array(
    'label' => 'Card Header',
    'weight' => '11',
    'children' => array(
      0 => 'group_card_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Header',
      'instance_settings' => array(
        'classes' => 'card-header',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_card_header|bean|ua_card|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_title|bean|ua_card|default';
  $field_group->group_name = 'group_card_title';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'ua_card';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card_header';
  $field_group->data = array(
    'label' => 'Card Title',
    'weight' => '7',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Title',
      'instance_settings' => array(
        'classes' => 'card-title',
        'element' => 'h4',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_card_title|bean|ua_card|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card|bean|ua_card|default';
  $field_group->group_name = 'group_card';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'ua_card';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Card',
    'weight' => '2',
    'children' => array(
      0 => 'field_slide_image',
      1 => 'group_card_block_1',
      2 => 'group_card_header',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card',
      'instance_settings' => array(
        'classes' => 'card',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_card|bean|ua_card|default'] = $field_group;

  return $export;
}
