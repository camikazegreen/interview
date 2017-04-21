<?php
/**
 * @file
 * uaqs_content_chunks_marquee.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_content_chunks_marquee_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner_text|paragraphs_item|uaqs_content_chunks_marquee|default';
  $field_group->group_name = 'group_banner_text';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_content_chunks_marquee';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_bs_column';
  $field_group->data = array(
    'label' => 'Banner Text',
    'weight' => '2',
    'children' => array(
      0 => 'group_row',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Banner Text',
      'instance_settings' => array(
        'id' => 'banner-text',
        'classes' => 'banner-text-grid text-center',
        'element' => 'section',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_banner_text|paragraphs_item|uaqs_content_chunks_marquee|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bs_column|paragraphs_item|uaqs_content_chunks_marquee|default';
  $field_group->group_name = 'group_bs_column';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_content_chunks_marquee';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'BS Column',
    'weight' => '1',
    'children' => array(
      0 => 'group_banner_text',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'BS Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-sm-10 col-sm-offset-1',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_bs_column|paragraphs_item|uaqs_content_chunks_marquee|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_h3_banner|paragraphs_item|uaqs_content_chunks_marquee|default';
  $field_group->group_name = 'group_h3_banner';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_content_chunks_marquee';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Headline',
    'weight' => '2',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Headline',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'sans blue60b',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_h3_banner|paragraphs_item|uaqs_content_chunks_marquee|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_headline|paragraphs_item|uaqs_content_chunks_marquee|default';
  $field_group->group_name = 'group_headline';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_content_chunks_marquee';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Headline',
    'weight' => '9',
    'children' => array(
      0 => 'field_uaqs_summary_short',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Headline',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'sans blue60b',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_headline|paragraphs_item|uaqs_content_chunks_marquee|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_banner|paragraphs_item|uaqs_content_chunks_marquee|default';
  $field_group->group_name = 'group_home_banner';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_content_chunks_marquee';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Home Banner',
    'weight' => '0',
    'children' => array(
      0 => 'field_uaqs_photo',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Home Banner',
      'instance_settings' => array(
        'id' => 'home-banner',
        'classes' => '',
        'element' => 'section',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_home_banner|paragraphs_item|uaqs_content_chunks_marquee|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_read_more|paragraphs_item|uaqs_content_chunks_marquee|default';
  $field_group->group_name = 'group_read_more';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_content_chunks_marquee';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Read More',
    'weight' => '12',
    'children' => array(
      0 => 'field_uaqs_link',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Read More',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-center card-block',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_read_more|paragraphs_item|uaqs_content_chunks_marquee|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|paragraphs_item|uaqs_content_chunks_marquee|default';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'uaqs_content_chunks_marquee';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_banner_text';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_summary',
      1 => 'group_headline',
      2 => 'group_read_more',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_row|paragraphs_item|uaqs_content_chunks_marquee|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('BS Column');
  t('Banner Text');
  t('Headline');
  t('Home Banner');
  t('Read More');
  t('Row');

  return $field_groups;
}
