<?php
/**
 * @file
 * uaqs_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_person_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_block_1|node|uaqs_person|uaqs_card';
  $field_group->group_name = 'group_card_block_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'uaqs_card';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Card Block',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'field_uaqs_email',
      2 => 'field_uaqs_phones',
      3 => 'field_uaqs_titles',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Block',
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
  $field_groups['group_card_block_1|node|uaqs_person|uaqs_card'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_left|node|uaqs_person|teaser';
  $field_group->group_name = 'group_column_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Left Column',
    'weight' => '0',
    'children' => array(
      0 => 'field_uaqs_photo',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Left Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-3',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_column_left|node|uaqs_person|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_middle|node|uaqs_person|teaser';
  $field_group->group_name = 'group_column_middle';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Middle Column',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'field_uaqs_titles',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Middle Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-5',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_column_middle|node|uaqs_person|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_one|node|uaqs_person|default';
  $field_group->group_name = 'group_column_one';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row_one';
  $field_group->data = array(
    'label' => 'Column',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_photo',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-xs-12 col-md-4',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_column_one|node|uaqs_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_right|node|uaqs_person|teaser';
  $field_group->group_name = 'group_column_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Right Column',
    'weight' => '2',
    'children' => array(
      0 => 'field_uaqs_email',
      1 => 'field_uaqs_phones',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Right Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-4',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_column_right|node|uaqs_person|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_three|node|uaqs_person|default';
  $field_group->group_name = 'group_column_three';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row_two';
  $field_group->data = array(
    'label' => 'Column',
    'weight' => '9',
    'children' => array(
      0 => 'field_uaqs_bio',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-lg-12',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_column_three|node|uaqs_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_two|node|uaqs_person|default';
  $field_group->group_name = 'group_column_two';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row_one';
  $field_group->data = array(
    'label' => 'Column',
    'weight' => '2',
    'children' => array(
      0 => 'field_uaqs_addresses',
      1 => 'field_uaqs_email',
      2 => 'field_uaqs_phones',
      3 => 'title_field',
      4 => 'group_lead',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-xs-12 col-md-8',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_column_two|node|uaqs_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lead|node|uaqs_person|default';
  $field_group->group_name = 'group_lead';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_column_two';
  $field_group->data = array(
    'label' => 'Heading',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_titles',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Heading',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'margin-zero-top',
        'element' => 'h4',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_lead|node|uaqs_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_one|node|uaqs_person|default';
  $field_group->group_name = 'group_row_one';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '0',
    'children' => array(
      0 => 'group_column_one',
      1 => 'group_column_two',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row margin-align-bottom',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_row_one|node|uaqs_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_two|node|uaqs_person|default';
  $field_group->group_name = 'group_row_two';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '3',
    'children' => array(
      0 => 'group_column_three',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row margin-align-middle',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_row_two|node|uaqs_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|node|uaqs_person|teaser';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_person';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '3',
    'children' => array(
      0 => 'group_column_left',
      1 => 'group_column_middle',
      2 => 'group_column_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row border-separator',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_row|node|uaqs_person|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Card Block');
  t('Column');
  t('Heading');
  t('Left Column');
  t('Middle Column');
  t('Right Column');
  t('Row');

  return $field_groups;
}
