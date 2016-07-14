<?php
/**
 * @file
 * uaqs_content_chunks_full_width_bg_wrapper.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_content_chunks_full_width_bg_wrapper_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_columns|paragraphs_item|uaqs_full_width_bg_wrapper|default';
  $field_group->group_name = 'group_columns';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_full_width_bg_wrapper';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Columns',
    'weight' => '0',
    'children' => array(
      0 => 'field_uaqs_summary',
      1 => 'group_h1',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Columns',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-sm-12',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_columns|paragraphs_item|uaqs_full_width_bg_wrapper|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_h1|paragraphs_item|uaqs_full_width_bg_wrapper|default';
  $field_group->group_name = 'group_h1';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_full_width_bg_wrapper';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_columns';
  $field_group->data = array(
    'label' => 'H1',
    'weight' => '5',
    'children' => array(
      0 => 'field_uaqs_summary_short',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'H1',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'h1',
        'element' => 'h1',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_h1|paragraphs_item|uaqs_full_width_bg_wrapper|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Columns');
  t('H1');

  return $field_groups;
}
