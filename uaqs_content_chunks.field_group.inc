<?php
/**
 * @file
 * uaqs_content_chunks.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_content_chunks_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication|node|uaqs_flexible_page|form';
  $field_group->group_name = 'group_publication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_flexible_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_uaqs_summary_fields';
  $field_group->data = array(
    'label' => 'Publication',
    'weight' => '5',
    'children' => array(
      0 => 'field_uaqs_short_title',
      1 => 'field_uaqs_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Publication',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-publication field-group-fieldset',
        'description' => 'Replace the token [site:name] to customize your link output.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_publication|node|uaqs_flexible_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uaqs_main_content|node|uaqs_flexible_page|form';
  $field_group->group_name = 'group_uaqs_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_flexible_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '0',
    'children' => array(
      0 => 'field_uaqs_flexible_page_sub',
      1 => 'field_uaqs_main_content',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-uaqs-main-content field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_uaqs_main_content|node|uaqs_flexible_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uaqs_summary_fields|node|uaqs_flexible_page|form';
  $field_group->group_name = 'group_uaqs_summary_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_flexible_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summary fields',
    'weight' => '3',
    'children' => array(
      0 => 'field_uaqs_photo',
      1 => 'field_uaqs_summary',
      2 => 'group_publication',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Summary fields',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'These fields appear in display modes other that the full page view mode.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_uaqs_summary_fields|node|uaqs_flexible_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main content');
  t('Publication');
  t('Summary fields');

  return $field_groups;
}
