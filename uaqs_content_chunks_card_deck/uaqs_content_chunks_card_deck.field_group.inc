<?php
/**
 * @file
 * uaqs_content_chunks_card_deck.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_content_chunks_card_deck_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_block|field_collection_item|field_uaqs_cards|default';
  $field_group->group_name = 'group_card_block';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_uaqs_cards';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card';
  $field_group->data = array(
    'label' => 'Card Block',
    'weight' => '9',
    'children' => array(
      0 => 'field_uaqs_links',
      1 => 'field_uaqs_summary',
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
  $field_groups['group_card_block|field_collection_item|field_uaqs_cards|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_deck_wrapper|paragraphs_item|uaqs_card_deck|default';
  $field_group->group_name = 'group_card_deck_wrapper';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_card_deck';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Card deck wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'group_card_deck',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card deck wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-deck-wrapper',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_deck_wrapper|paragraphs_item|uaqs_card_deck|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_deck|paragraphs_item|uaqs_card_deck|default';
  $field_group->group_name = 'group_card_deck';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_card_deck';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card_deck_wrapper';
  $field_group->data = array(
    'label' => 'Card Deck',
    'weight' => '4',
    'children' => array(
      0 => 'field_uaqs_cards',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Deck',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-deck',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_deck|paragraphs_item|uaqs_card_deck|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_header|field_collection_item|field_uaqs_cards|default';
  $field_group->group_name = 'group_card_header';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_uaqs_cards';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card';
  $field_group->data = array(
    'label' => 'Card Header',
    'weight' => '7',
    'children' => array(
      0 => 'group_card_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Header',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-header',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_header|field_collection_item|field_uaqs_cards|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_title|field_collection_item|field_uaqs_cards|default';
  $field_group->group_name = 'group_card_title';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_uaqs_cards';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_card_header';
  $field_group->data = array(
    'label' => 'Card Title',
    'weight' => '6',
    'children' => array(
      0 => 'field_uaqs_short_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-title',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_title|field_collection_item|field_uaqs_cards|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card|field_collection_item|field_uaqs_cards|default';
  $field_group->group_name = 'group_card';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_uaqs_cards';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Card',
    'weight' => '0',
    'children' => array(
      0 => 'field_uaqs_photo',
      1 => 'group_card_block',
      2 => 'group_card_header',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card|field_collection_item|field_uaqs_cards|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Card');
  t('Card Block');
  t('Card Deck');
  t('Card Header');
  t('Card Title');
  t('Card deck wrapper');

  return $field_groups;
}
