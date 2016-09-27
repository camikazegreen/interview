<?php
/**
 * @file
 * uaqs_content_chunks_single_card.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_content_chunks_single_card_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_link|paragraphs_item|single_card|default';
  $field_group->group_name = 'group_card_link';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'single_card';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card';
  $field_group->data = array(
    'label' => 'Card Link',
    'weight' => '3',
    'children' => array(
      0 => 'field_link',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Link',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'p',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_link|paragraphs_item|single_card|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_text|paragraphs_item|single_card|default';
  $field_group->group_name = 'group_card_text';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'single_card';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card';
  $field_group->data = array(
    'label' => 'Card Text',
    'weight' => '2',
    'children' => array(
      0 => 'field_uaqs_html',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Text',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-text',
        'element' => 'p',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_text|paragraphs_item|single_card|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_title|paragraphs_item|single_card|default';
  $field_group->group_name = 'group_card_title';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'single_card';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card';
  $field_group->data = array(
    'label' => 'Card Title',
    'weight' => '1',
    'children' => array(
      0 => 'field_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-title',
        'element' => 'h3',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_title|paragraphs_item|single_card|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card|paragraphs_item|single_card|default';
  $field_group->group_name = 'group_card';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'single_card';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Card',
    'weight' => '0',
    'children' => array(
      0 => 'group_card_title',
      1 => 'group_card_text',
      2 => 'group_card_link',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card card-block',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card|paragraphs_item|single_card|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Card');
  t('Card Link');
  t('Card Text');
  t('Card Title');

  return $field_groups;
}
