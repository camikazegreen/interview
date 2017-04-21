<?php
/**
 * @file
 * uaqs_content_chunks_extra_info.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_content_chunks_extra_info_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bottom_buffer_30|paragraphs_item|uaqs_extra_info|default';
  $field_group->group_name = 'group_bottom_buffer_30';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_extra_info';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'bottom-buffer-30',
    'weight' => '0',
    'children' => array(
      0 => 'field_uaqs_link',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'bottom-buffer-30',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'bottom-buffer-30',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_bottom_buffer_30|paragraphs_item|uaqs_extra_info|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('bottom-buffer-30');

  return $field_groups;
}
