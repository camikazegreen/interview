<?php
/**
 * @file
 * uaqs_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_news_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_h4|node|uaqs_news|uaqs_teaser_list';
  $field_group->group_name = 'group_h4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'uaqs_teaser_list';
  $field_group->parent_name = 'group_right_column';
  $field_group->data = array(
    'label' => 'h4',
    'weight' => '14',
    'children' => array(
      0 => 'title_field',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'h4',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-heading',
        'element' => 'h4',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_h4|node|uaqs_news|uaqs_teaser_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left_column|node|uaqs_news|uaqs_teaser_list';
  $field_group->group_name = 'group_left_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'uaqs_teaser_list';
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Left Column',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_photos',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Left Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-left',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_left_column|node|uaqs_news|uaqs_teaser_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|uaqs_news|uaqs_teaser_list';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'uaqs_teaser_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '0',
    'children' => array(
      0 => 'group_left_column',
      1 => 'group_right_column',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_media|node|uaqs_news|uaqs_teaser_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right_column|node|uaqs_news|uaqs_teaser_list';
  $field_group->group_name = 'group_right_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'uaqs_teaser_list';
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Right Column',
    'weight' => '2',
    'children' => array(
      0 => 'field_uaqs_summary',
      1 => 'group_h4',
      2 => 'group_text_muted',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Right Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-body',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_right_column|node|uaqs_news|uaqs_teaser_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|node|uaqs_news|default';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '0',
    'children' => array(
      0 => 'group_text_column',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_row|node|uaqs_news|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_column|node|uaqs_news|default';
  $field_group->group_name = 'group_text_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Text Column',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_body',
      1 => 'field_uaqs_byline',
      2 => 'field_uaqs_link',
      3 => 'field_uaqs_published',
      4 => 'field_uaqs_summary_short',
      5 => 'title_field',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Text Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-lg-10 col-lg-push-1',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_text_column|node|uaqs_news|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_muted|node|uaqs_news|teaser';
  $field_group->group_name = 'group_text_muted';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Muted',
    'weight' => '3',
    'children' => array(
      0 => 'field_uaqs_published',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Text Muted',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-muted',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_text_muted|node|uaqs_news|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_muted|node|uaqs_news|uaqs_teaser_list';
  $field_group->group_name = 'group_text_muted';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uaqs_news';
  $field_group->mode = 'uaqs_teaser_list';
  $field_group->parent_name = 'group_right_column';
  $field_group->data = array(
    'label' => 'Text Muted',
    'weight' => '16',
    'children' => array(
      0 => 'field_uaqs_published',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Text Muted',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-muted',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_text_muted|node|uaqs_news|uaqs_teaser_list'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Left Column');
  t('Media');
  t('Right Column');
  t('Row');
  t('Text Column');
  t('Text Muted');
  t('h4');

  return $field_groups;
}
