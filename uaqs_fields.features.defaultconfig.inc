<?php
/**
 * @file
 * uaqs_fields.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uaqs_fields_defaultconfig_features() {
  return array(
    'uaqs_fields' => array(
      'field_default_fields' => 'field_default_fields',
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function uaqs_fields_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_uaqs_contacts-field_uaqs_contact_email'.
  $fields['field_collection_item-field_uaqs_contacts-field_uaqs_contact_email'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_uaqs_contact_email',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'email',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'field_uaqs_contacts',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'email',
          'settings' => array(
            'field_multiple_limit' => -1,
            'field_multiple_limit_offset' => 0,
          ),
          'type' => 'email_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_uaqs_contact_email',
      'label' => 'Contact Email',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'email_textfield',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_uaqs_contacts-field_uaqs_contact_name'.
  $fields['field_collection_item-field_uaqs_contacts-field_uaqs_contact_name'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_uaqs_contact_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'field_uaqs_contacts',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Full name if possible',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'field_multiple_limit' => -1,
            'field_multiple_limit_offset' => 0,
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_uaqs_contact_name',
      'label' => 'Contact Name',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 1,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_uaqs_contacts-field_uaqs_contact_phone'.
  $fields['field_collection_item-field_uaqs_contacts-field_uaqs_contact_phone'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_uaqs_contact_phone',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'field_uaqs_contacts',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '<strong>Suggested format:</strong> 520-626-0000',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'field_multiple_limit' => -1,
            'field_multiple_limit_offset' => 0,
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_uaqs_contact_phone',
      'label' => 'Contact Phone',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 3,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<strong>Suggested format:</strong> 520-626-0000');
  t('Contact Email');
  t('Contact Name');
  t('Contact Phone');
  t('Full name if possible');

  return $fields;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function uaqs_fields_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'title_bean';
  $strongarm->value = array(
    'auto_attach' => array(
      'title' => 0,
    ),
    'hide_label' => array(
      'page' => 0,
      'entity' => 0,
    ),
  );
  $export['title_bean'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'title_node';
  $strongarm->value = array(
    'auto_attach' => array(
      'title' => 'title',
    ),
    'hide_label' => array(
      'page' => 'page',
      'entity' => 'entity',
    ),
  );
  $export['title_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'title_taxonomy_term';
  $strongarm->value = array(
    'auto_attach' => array(
      'name' => 0,
      'description' => 0,
    ),
    'hide_label' => array(
      'page' => 0,
      'entity' => 0,
    ),
  );
  $export['title_taxonomy_term'] = $strongarm;

  return $export;
}
