<?php
/**
 * @file
 * ua_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ua_person_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ua_person_contact_area|node|ua_person|default';
  $field_group->group_name = 'group_ua_person_contact_area';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ua_person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'field_ua_person_phones',
      1 => 'field_ua_person_email',
      2 => 'field_ua_person_addresses',
      3 => 'field_ua_person_photo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-ua-person-contact-area field-group-div clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ua_person_contact_area|node|ua_person|default'] = $field_group;

  return $export;
}
