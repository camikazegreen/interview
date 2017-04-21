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
  $field_group->identifier = 'group_card_block|node|uaqs_flexible_page|uaqs_card';
  $field_group->group_name = 'group_card_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_flexible_page';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = 'group_link';
  $field_group->data = array(
    'label' => 'Card block',
    'weight' => '11',
    'children' => array(
      0 => 'field_uaqs_summary',
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
  $field_groups['group_card_block|node|uaqs_flexible_page|uaqs_card'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_h4|node|uaqs_flexible_page|uaqs_card';
  $field_group->group_name = 'group_h4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_flexible_page';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'h4',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'h4',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-title card-header margin-zero-top margin-zero-bottom',
        'element' => 'h4',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_h4|node|uaqs_flexible_page|uaqs_card'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link|node|uaqs_flexible_page|uaqs_card';
  $field_group->group_name = 'group_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_flexible_page';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_photo',
      1 => 'group_card_block',
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
  $field_groups['group_link|node|uaqs_flexible_page|uaqs_card'] = $field_group;

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
      0 => 'field_uaqs_link',
      1 => 'field_uaqs_short_title',
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
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_flexible_page_sub',
      1 => 'field_uaqs_main_content',
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
    'weight' => '2',
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
  t('Card block');
  t('Link');
  t('Main content');
  t('Publication');
  t('Summary fields');
  t('h4');

  return $field_groups;
}
