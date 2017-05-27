<?php
/**
 * @file
 * uaqs_fields_media.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uaqs_fields_media_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cite|file|image|default';
  $field_group->group_name = 'group_cite';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_figcaption';
  $field_group->data = array(
    'label' => 'Cite',
    'weight' => '10',
    'children' => array(
      0 => 'field_uaqs_image_credit',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Cite',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'small clearfix',
        'element' => 'cite',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_cite|file|image|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cite|file|image|uaqs_medium';
  $field_group->group_name = 'group_cite';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_medium';
  $field_group->parent_name = 'group_figcaption';
  $field_group->data = array(
    'label' => 'Cite',
    'weight' => '5',
    'children' => array(
      0 => 'field_uaqs_image_credit',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Cite',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'small clearfix',
        'element' => 'cite',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_cite|file|image|uaqs_medium'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cite|file|image|uaqs_small';
  $field_group->group_name = 'group_cite';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_small';
  $field_group->parent_name = 'group_figcaption';
  $field_group->data = array(
    'label' => 'Cite',
    'weight' => '3',
    'children' => array(
      0 => 'field_uaqs_image_credit',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Cite',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'small clearfix',
        'element' => 'cite',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_cite|file|image|uaqs_small'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cite|file|image|uaqs_square';
  $field_group->group_name = 'group_cite';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_square';
  $field_group->parent_name = 'group_figcaption';
  $field_group->data = array(
    'label' => 'Cite',
    'weight' => '7',
    'children' => array(
      0 => 'field_uaqs_image_credit',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Cite',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'small clearfix',
        'element' => 'cite',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_cite|file|image|uaqs_square'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figcaption|file|image|default';
  $field_group->group_name = 'group_figcaption';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_figure';
  $field_group->data = array(
    'label' => 'Figcaption',
    'weight' => '2',
    'children' => array(
      0 => 'field_uaqs_caption_text',
      1 => 'group_cite',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figcaption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-muted',
        'element' => 'figcaption',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figcaption|file|image|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figcaption|file|image|uaqs_medium';
  $field_group->group_name = 'group_figcaption';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_medium';
  $field_group->parent_name = 'group_figure';
  $field_group->data = array(
    'label' => 'Figcaption',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_caption_text',
      1 => 'group_cite',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figcaption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-muted',
        'element' => 'figcaption',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figcaption|file|image|uaqs_medium'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figcaption|file|image|uaqs_small';
  $field_group->group_name = 'group_figcaption';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_small';
  $field_group->parent_name = 'group_figure';
  $field_group->data = array(
    'label' => 'Figcaption',
    'weight' => '2',
    'children' => array(
      0 => 'field_uaqs_caption_text',
      1 => 'group_cite',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figcaption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-muted',
        'element' => 'figcaption',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figcaption|file|image|uaqs_small'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figcaption|file|image|uaqs_square';
  $field_group->group_name = 'group_figcaption';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_square';
  $field_group->parent_name = 'group_figure';
  $field_group->data = array(
    'label' => 'Figcaption',
    'weight' => '1',
    'children' => array(
      0 => 'field_uaqs_caption_text',
      1 => 'group_cite',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figcaption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-muted',
        'element' => 'figcaption',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figcaption|file|image|uaqs_square'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figure|file|image|default';
  $field_group->group_name = 'group_figure';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Figure',
    'weight' => '0',
    'children' => array(
      0 => 'file',
      1 => 'group_figcaption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figure',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'figure',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figure|file|image|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figure|file|image|uaqs_medium';
  $field_group->group_name = 'group_figure';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_medium';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Figure',
    'weight' => '0',
    'children' => array(
      0 => 'file',
      1 => 'group_figcaption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figure',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'figure',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figure|file|image|uaqs_medium'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figure|file|image|uaqs_small';
  $field_group->group_name = 'group_figure';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_small';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Figure',
    'weight' => '0',
    'children' => array(
      0 => 'file',
      1 => 'group_figcaption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figure',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'figure',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figure|file|image|uaqs_small'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_figure|file|image|uaqs_square';
  $field_group->group_name = 'group_figure';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_square';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Figure',
    'weight' => '0',
    'children' => array(
      0 => 'file',
      1 => 'group_figcaption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Figure',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'figure',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_figure|file|image|uaqs_square'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_body|file|image|uaqs_media_list';
  $field_group->group_name = 'group_media_body';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_media_list';
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Media body',
    'weight' => '7',
    'children' => array(
      0 => 'field_uaqs_caption_text',
      1 => 'field_uaqs_image_credit',
      2 => 'group_media_heading',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media body',
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
  $field_groups['group_media_body|file|image|uaqs_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_heading|file|image|uaqs_media_list';
  $field_group->group_name = 'group_media_heading';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_media_list';
  $field_group->parent_name = 'group_media_body';
  $field_group->data = array(
    'label' => 'Media heading',
    'weight' => '6',
    'children' => array(
      0 => 'group_strong',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media heading',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-heading',
        'element' => 'h5',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_media_heading|file|image|uaqs_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_object|file|image|uaqs_media_list';
  $field_group->group_name = 'group_media_object';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_media_list';
  $field_group->parent_name = 'group_media_position';
  $field_group->data = array(
    'label' => 'Media object',
    'weight' => '11',
    'children' => array(
      0 => 'file',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media object',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-object',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_media_object|file|image|uaqs_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_position|file|image|uaqs_media_list';
  $field_group->group_name = 'group_media_position';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_media_list';
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Media position',
    'weight' => '8',
    'children' => array(
      0 => 'group_media_object',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Media position',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'media-right',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_media_position|file|image|uaqs_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|file|image|uaqs_media_list';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_media_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '0',
    'children' => array(
      0 => 'group_media_body',
      1 => 'group_media_position',
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
  $field_groups['group_media|file|image|uaqs_media_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_strong|file|image|uaqs_media_list';
  $field_group->group_name = 'group_strong';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'uaqs_media_list';
  $field_group->parent_name = 'group_media_heading';
  $field_group->data = array(
    'label' => 'Strong',
    'weight' => '6',
    'children' => array(
      0 => 'filename_field',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Strong',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'strong',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_strong|file|image|uaqs_media_list'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Cite');
  t('Figcaption');
  t('Figure');
  t('Media');
  t('Media body');
  t('Media heading');
  t('Media object');
  t('Media position');
  t('Strong');

  return $field_groups;
}
