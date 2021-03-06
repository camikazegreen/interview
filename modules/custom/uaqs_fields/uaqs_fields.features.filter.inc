<?php
/**
 * @file
 * uaqs_fields.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function uaqs_fields_filter_default_formats() {
  $formats = array();

  // Exported format: UAQS Filtered HTML.
  $formats['uaqs_filtered_html'] = array(
    'format' => 'uaqs_filtered_html',
    'name' => 'UAQS Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -6,
    'editor' => 'ckeditor',
    'editor_settings' => 'a:3:{s:7:"toolbar";a:1:{i:0;a:3:{i:0;a:2:{s:4:"name";s:10:"Formatting";s:5:"items";a:5:{i:0;s:4:"Bold";i:1;s:6:"Italic";i:2;s:12:"NumberedList";i:3;s:12:"BulletedList";i:4;s:10:"Blockquote";}}i:1;a:2:{s:4:"name";s:5:"Tools";s:5:"items";a:2:{i:0;s:6:"Source";i:1;s:8:"Maximize";}}i:2;a:2:{s:4:"name";s:4:"Link";s:5:"items";a:2:{i:0;s:10:"DrupalLink";i:1;s:12:"DrupalUnlink";}}}}s:12:"image_upload";a:5:{s:6:"status";i:0;s:6:"scheme";s:6:"public";s:9:"directory";s:13:"inline-images";s:8:"max_size";s:0:"";s:14:"max_dimensions";a:2:{s:5:"width";s:0:"";s:6:"height";s:0:"";}}s:7:"plugins";a:2:{s:5:"style";a:1:{s:10:"style_list";a:0:{}}s:8:"language";a:1:{s:13:"language_list";s:2:"un";}}}',
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: UAQS Full HTML.
  $formats['uaqs_full_html'] = array(
    'format' => 'uaqs_full_html',
    'name' => 'UAQS Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -7,
    'editor' => 'ckeditor',
    'editor_settings' => 'a:3:{s:7:"toolbar";a:1:{i:0;a:6:{i:0;a:2:{s:4:"name";s:10:"Formatting";s:5:"items";a:3:{i:0;s:4:"Bold";i:1;s:6:"Italic";i:2;s:11:"SpecialChar";}}i:1;a:2:{s:4:"name";s:5:"Media";s:5:"items";a:2:{i:0;s:10:"uaqs_files";i:1;s:10:"Blockquote";}}i:2;a:2:{s:4:"name";s:5:"Tools";s:5:"items";a:4:{i:0;s:6:"Source";i:1;s:8:"Maximize";i:2;s:12:"RemoveFormat";i:3;s:13:"PasteFromWord";}}i:3;a:2:{s:4:"name";s:5:"Lists";s:5:"items";a:2:{i:0;s:12:"BulletedList";i:1;s:12:"NumberedList";}}i:4;a:2:{s:4:"name";s:17:"Additional Styles";s:5:"items";a:2:{i:0;s:6:"Styles";i:1;s:6:"Format";}}i:5;a:2:{s:4:"name";s:5:"Links";s:5:"items";a:2:{i:0;s:10:"DrupalLink";i:1;s:12:"DrupalUnlink";}}}}s:12:"image_upload";a:5:{s:6:"status";i:0;s:6:"scheme";s:6:"public";s:9:"directory";s:13:"inline-images";s:8:"max_size";s:0:"";s:14:"max_dimensions";a:2:{s:5:"width";s:0:"";s:6:"height";s:0:"";}}s:7:"plugins";a:2:{s:5:"style";a:1:{s:10:"style_list";a:25:{i:0;a:3:{s:4:"name";s:14:"Button Default";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-default";}}i:1;a:3:{s:4:"name";s:14:"Button Primary";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-primary";}}i:2;a:3:{s:4:"name";s:13:"Button Hollow";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:14:"btn btn-hollow";}}i:3;a:3:{s:4:"name";s:11:"Button Link";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:8:"btn-link";}}i:4;a:3:{s:4:"name";s:14:"Lead Body Copy";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"lead";}}i:5;a:3:{s:4:"name";s:10:"Small Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:5:"small";}}i:6;a:3:{s:4:"name";s:14:"Dark Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue60b";}}i:7;a:3:{s:4:"name";s:15:"Light Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue30w";}}i:8;a:3:{s:4:"name";s:16:"Sanserif Heading";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"sans";}}i:9;a:3:{s:4:"name";s:16:"Capitalized text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:15:"text-capitalize";}}i:10;a:3:{s:4:"name";s:16:"Triangle Bullets";s:7:"element";s:2:"ul";s:10:"attributes";a:1:{s:5:"class";s:8:"triangle";}}i:11;a:3:{s:4:"name";s:20:"Unordered list pills";s:7:"element";s:2:"ul";s:10:"attributes";a:1:{s:5:"class";s:13:"nav nav-pills";}}i:12;a:3:{s:4:"name";s:13:"Default Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-default";}}i:13;a:3:{s:4:"name";s:13:"Primary Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-primary";}}i:14;a:3:{s:4:"name";s:13:"Success Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-success";}}i:15;a:3:{s:4:"name";s:10:"Info Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:16:"label label-info";}}i:16;a:3:{s:4:"name";s:13:"Warning Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-warning";}}i:17;a:3:{s:4:"name";s:12:"Danger Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:18:"label label-danger";}}i:18;a:3:{s:4:"name";s:16:"Responsive Table";s:7:"element";s:3:"div";s:10:"attributes";a:1:{s:5:"class";s:16:"table-responsive";}}i:19;a:3:{s:4:"name";s:13:"Table Striped";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:13:"table-striped";}}i:20;a:3:{s:4:"name";s:10:"Table Dark";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:10:"table-dark";}}i:21;a:3:{s:4:"name";s:11:"Table Hover";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:11:"table-hover";}}i:22;a:3:{s:4:"name";s:18:"Table Dark & Hover";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:22:"table-dark table-hover";}}i:23;a:3:{s:4:"name";s:21:"Table Hover & Striped";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:25:"table-hover table-striped";}}i:24;a:3:{s:4:"name";s:28:"Table Dark & Hover & Striped";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:36:"table-dark table-hover table-striped";}}}}s:8:"language";a:1:{s:13:"language_list";s:2:"un";}}}',
    'filters' => array(
      'entity_embed' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'editor_align' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: UAQS Standard.
  $formats['uaqs_standard'] = array(
    'format' => 'uaqs_standard',
    'name' => 'UAQS Standard',
    'cache' => 0,
    'status' => 1,
    'weight' => -9,
    'editor' => 'ckeditor',
    'editor_settings' => 'a:3:{s:7:"toolbar";a:1:{i:0;a:7:{i:0;a:2:{s:4:"name";s:10:"Formatting";s:5:"items";a:5:{i:0;s:4:"Bold";i:1;s:9:"Underline";i:2;s:6:"Strike";i:3;s:6:"Italic";i:4;s:11:"SpecialChar";}}i:1;a:2:{s:4:"name";s:9:"Alignment";s:5:"items";a:3:{i:0;s:11:"JustifyLeft";i:1;s:13:"JustifyCenter";i:2;s:12:"JustifyRight";}}i:2;a:2:{s:4:"name";s:5:"Links";s:5:"items";a:2:{i:0;s:10:"DrupalLink";i:1;s:12:"DrupalUnlink";}}i:3;a:2:{s:4:"name";s:5:"Media";s:5:"items";a:3:{i:0;s:10:"uaqs_files";i:1;s:14:"HorizontalRule";i:2;s:10:"Blockquote";}}i:4;a:2:{s:4:"name";s:5:"Lists";s:5:"items";a:2:{i:0;s:12:"BulletedList";i:1;s:12:"NumberedList";}}i:5;a:2:{s:4:"name";s:17:"Additional Styles";s:5:"items";a:4:{i:0;s:6:"Styles";i:1;s:6:"Format";i:2;s:9:"Subscript";i:3;s:11:"Superscript";}}i:6;a:2:{s:4:"name";s:5:"Tools";s:5:"items";a:4:{i:0;s:8:"Maximize";i:1;s:6:"Source";i:2;s:12:"RemoveFormat";i:3;s:13:"PasteFromWord";}}}}s:12:"image_upload";a:5:{s:6:"status";i:0;s:6:"scheme";s:6:"public";s:9:"directory";s:13:"inline-images";s:8:"max_size";s:0:"";s:14:"max_dimensions";a:2:{s:5:"width";s:0:"";s:6:"height";s:0:"";}}s:7:"plugins";a:2:{s:5:"style";a:1:{s:10:"style_list";a:24:{i:0;a:3:{s:4:"name";s:14:"Button Default";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-default";}}i:1;a:3:{s:4:"name";s:14:"Button Primary";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-primary";}}i:2;a:3:{s:4:"name";s:13:"Button Hollow";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:14:"btn btn-hollow";}}i:3;a:3:{s:4:"name";s:11:"Button Link";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:8:"btn-link";}}i:4;a:3:{s:4:"name";s:14:"Lead Body Copy";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"lead";}}i:5;a:3:{s:4:"name";s:10:"Small Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:5:"small";}}i:6;a:3:{s:4:"name";s:14:"Dark Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue60b";}}i:7;a:3:{s:4:"name";s:15:"Light Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue30w";}}i:8;a:3:{s:4:"name";s:16:"Sanserif Heading";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"sans";}}i:9;a:3:{s:4:"name";s:16:"Capitalized Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:15:"text-capitalize";}}i:10;a:3:{s:4:"name";s:15:"UPPERCASED TEXT";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:14:"text-uppercase";}}i:11;a:3:{s:4:"name";s:15:"lowercased text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:14:"text-lowercase";}}i:12;a:3:{s:4:"name";s:16:"Triangle Bullets";s:7:"element";s:2:"ul";s:10:"attributes";a:1:{s:5:"class";s:8:"triangle";}}i:13;a:3:{s:4:"name";s:20:"Unordered List Pills";s:7:"element";s:2:"ul";s:10:"attributes";a:1:{s:5:"class";s:13:"nav nav-pills";}}i:14;a:3:{s:4:"name";s:13:"Default Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-default";}}i:15;a:3:{s:4:"name";s:13:"Primary Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-primary";}}i:16;a:3:{s:4:"name";s:13:"Success Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-success";}}i:17;a:3:{s:4:"name";s:10:"Info Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:16:"label label-info";}}i:18;a:3:{s:4:"name";s:13:"Warning Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-warning";}}i:19;a:3:{s:4:"name";s:12:"Danger Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:18:"label label-danger";}}i:20;a:3:{s:4:"name";s:10:"H1 Heading";s:7:"element";s:1:"p";s:10:"attributes";a:1:{s:5:"class";s:2:"h1";}}i:21;a:3:{s:4:"name";s:10:"H2 Heading";s:7:"element";s:1:"p";s:10:"attributes";a:1:{s:5:"class";s:2:"h2";}}i:22;a:3:{s:4:"name";s:10:"H3 Heading";s:7:"element";s:1:"p";s:10:"attributes";a:1:{s:5:"class";s:2:"h3";}}i:23;a:3:{s:4:"name";s:10:"H4 Heading";s:7:"element";s:1:"p";s:10:"attributes";a:1:{s:5:"class";s:2:"h4";}}}}s:8:"language";a:1:{s:13:"language_list";s:2:"un";}}}',
    'filters' => array(
      'filter_html' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <abbr> <address> <b> <bdi> <bdo> <blockquote> <br> <cite> <code> <data> <dd> <del> <dfn> <dl> <drupal-entity data-*> <dt> <em> <figcaption> <figure> <hr> <i> <ins> <kbd> <li> <mark> <meter> <ol> <p> <pre> <q> <rb> <rp> <rt> <rtc> <ruby> <s> <samp> <small> <span> <strong> <sub> <sup> <time> <u> <ul> <var> <wbr>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'entity_embed' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'editor_align' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: UAQS Textual Content.
  $formats['uaqs_textual_content'] = array(
    'format' => 'uaqs_textual_content',
    'name' => 'UAQS Textual Content',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'editor' => 'ckeditor',
    'editor_settings' => 'a:3:{s:7:"toolbar";a:1:{i:0;a:3:{i:0;a:2:{s:4:"name";s:10:"Formatting";s:5:"items";a:8:{i:0;s:4:"Bold";i:1;s:6:"Italic";i:2;s:9:"Underline";i:3;s:11:"Superscript";i:4;s:9:"Subscript";i:5;s:11:"SpecialChar";i:6;s:6:"Strike";i:7;s:6:"Styles";}}i:1;a:2:{s:4:"name";s:5:"Tools";s:5:"items";a:2:{i:0;s:6:"Source";i:1;s:8:"Maximize";}}i:2;a:2:{s:4:"name";s:4:"Link";s:5:"items";a:2:{i:0;s:10:"DrupalLink";i:1;s:12:"DrupalUnlink";}}}}s:12:"image_upload";a:5:{s:6:"status";i:0;s:6:"scheme";s:6:"public";s:9:"directory";s:13:"inline-images";s:8:"max_size";s:0:"";s:14:"max_dimensions";a:2:{s:5:"width";s:0:"";s:6:"height";s:0:"";}}s:7:"plugins";a:2:{s:5:"style";a:1:{s:10:"style_list";a:16:{i:0;a:3:{s:4:"name";s:14:"Button Default";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-default";}}i:1;a:3:{s:4:"name";s:14:"Button Primary";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-primary";}}i:2;a:3:{s:4:"name";s:13:"Button Hollow";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:14:"btn btn-hollow";}}i:3;a:3:{s:4:"name";s:11:"Button Link";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:8:"btn-link";}}i:4;a:3:{s:4:"name";s:14:"Lead Body Copy";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"lead";}}i:5;a:3:{s:4:"name";s:10:"Small Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:5:"small";}}i:6;a:3:{s:4:"name";s:14:"Dark Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue60b";}}i:7;a:3:{s:4:"name";s:15:"Light Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue30w";}}i:8;a:3:{s:4:"name";s:16:"Sanserif Heading";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"sans";}}i:9;a:3:{s:4:"name";s:16:"Capitalized text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:15:"text-capitalize";}}i:10;a:3:{s:4:"name";s:13:"Default Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-default";}}i:11;a:3:{s:4:"name";s:13:"Primary Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-primary";}}i:12;a:3:{s:4:"name";s:13:"Success Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-success";}}i:13;a:3:{s:4:"name";s:10:"Info Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:16:"label label-info";}}i:14;a:3:{s:4:"name";s:13:"Warning Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-warning";}}i:15;a:3:{s:4:"name";s:12:"Danger Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:18:"label label-danger";}}}}s:8:"language";a:1:{s:13:"language_list";s:2:"un";}}}',
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <abbr> <b> <bdi> <bdo> <br> <cite> <code> <data> <del> <dfn> <em> <i> <ins> <kbd> <mark> <meter> <q> <rb> <rp> <rt> <rtc> <ruby> <s> <samp> <small> <span> <strong> <sub> <sup> <time> <u> <var> <wbr>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: UAQS Unconstrained Markup.
  $formats['uaqs_unconstrained'] = array(
    'format' => 'uaqs_unconstrained',
    'name' => 'UAQS Unconstrained Markup',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'editor' => 'ckeditor',
    'editor_settings' => 'a:3:{s:7:"toolbar";a:1:{i:0;a:8:{i:0;a:2:{s:4:"name";s:10:"Formatting";s:5:"items";a:5:{i:0;s:4:"Bold";i:1;s:9:"Underline";i:2;s:6:"Strike";i:3;s:6:"Italic";i:4;s:11:"SpecialChar";}}i:1;a:2:{s:4:"name";s:9:"Alignment";s:5:"items";a:3:{i:0;s:11:"JustifyLeft";i:1;s:13:"JustifyCenter";i:2;s:12:"JustifyRight";}}i:2;a:2:{s:4:"name";s:5:"Media";s:5:"items";a:2:{i:0;s:10:"uaqs_files";i:1;s:10:"Blockquote";}}i:3;a:2:{s:4:"name";s:5:"Tools";s:5:"items";a:4:{i:0;s:6:"Source";i:1;s:8:"Maximize";i:2;s:12:"RemoveFormat";i:3;s:13:"PasteFromWord";}}i:4;a:2:{s:4:"name";s:5:"Lists";s:5:"items";a:2:{i:0;s:12:"BulletedList";i:1;s:12:"NumberedList";}}i:5;a:2:{s:4:"name";s:17:"Additional Styles";s:5:"items";a:5:{i:0;s:14:"HorizontalRule";i:1;s:6:"Styles";i:2;s:6:"Format";i:3;s:9:"Subscript";i:4;s:11:"Superscript";}}i:6;a:2:{s:4:"name";s:5:"Links";s:5:"items";a:2:{i:0;s:10:"DrupalLink";i:1;s:12:"DrupalUnlink";}}i:7;a:2:{s:4:"name";s:6:"Tables";s:5:"items";a:1:{i:0;s:5:"Table";}}}}s:12:"image_upload";a:5:{s:6:"status";i:0;s:6:"scheme";s:6:"public";s:9:"directory";s:13:"inline-images";s:8:"max_size";s:0:"";s:14:"max_dimensions";a:2:{s:5:"width";s:0:"";s:6:"height";s:0:"";}}s:7:"plugins";a:2:{s:5:"style";a:1:{s:10:"style_list";a:25:{i:0;a:3:{s:4:"name";s:14:"Button Default";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-default";}}i:1;a:3:{s:4:"name";s:14:"Button Primary";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:15:"btn btn-primary";}}i:2;a:3:{s:4:"name";s:13:"Button Hollow";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:14:"btn btn-hollow";}}i:3;a:3:{s:4:"name";s:11:"Button Link";s:7:"element";s:1:"a";s:10:"attributes";a:1:{s:5:"class";s:8:"btn-link";}}i:4;a:3:{s:4:"name";s:16:"Responsive Table";s:7:"element";s:3:"div";s:10:"attributes";a:1:{s:5:"class";s:16:"table-responsive";}}i:5;a:3:{s:4:"name";s:13:"Table Striped";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:13:"table-striped";}}i:6;a:3:{s:4:"name";s:10:"Table Dark";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:10:"table-dark";}}i:7;a:3:{s:4:"name";s:11:"Table Hover";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:11:"table-hover";}}i:8;a:3:{s:4:"name";s:18:"Table Dark & Hover";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:22:"table-dark table-hover";}}i:9;a:3:{s:4:"name";s:21:"Table Hover & Striped";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:25:"table-hover table-striped";}}i:10;a:3:{s:4:"name";s:28:"Table Dark & Hover & Striped";s:7:"element";s:5:"table";s:10:"attributes";a:1:{s:5:"class";s:36:"table-dark table-hover table-striped";}}i:11;a:3:{s:4:"name";s:14:"Lead Body Copy";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"lead";}}i:12;a:3:{s:4:"name";s:10:"Small Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:5:"small";}}i:13;a:3:{s:4:"name";s:14:"Dark Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue60b";}}i:14;a:3:{s:4:"name";s:15:"Light Blue Text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:7:"blue30w";}}i:15;a:3:{s:4:"name";s:16:"Sanserif Heading";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:4:"sans";}}i:16;a:3:{s:4:"name";s:16:"Capitalized text";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:15:"text-capitalize";}}i:17;a:3:{s:4:"name";s:16:"Triangle Bullets";s:7:"element";s:2:"ul";s:10:"attributes";a:1:{s:5:"class";s:8:"triangle";}}i:18;a:3:{s:4:"name";s:20:"Unordered list pills";s:7:"element";s:2:"ul";s:10:"attributes";a:1:{s:5:"class";s:13:"nav nav-pills";}}i:19;a:3:{s:4:"name";s:13:"Default Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-default";}}i:20;a:3:{s:4:"name";s:13:"Primary Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-primary";}}i:21;a:3:{s:4:"name";s:13:"Success Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-success";}}i:22;a:3:{s:4:"name";s:10:"Info Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:16:"label label-info";}}i:23;a:3:{s:4:"name";s:13:"Warning Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:19:"label label-warning";}}i:24;a:3:{s:4:"name";s:12:"Danger Label";s:7:"element";s:4:"span";s:10:"attributes";a:1:{s:5:"class";s:18:"label label-danger";}}}}s:8:"language";a:1:{s:13:"language_list";s:2:"un";}}}',
    'filters' => array(
      'filter_html' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <abbr> <address> <article> <aside> <b> <bdi> <bdo> <blockquote> <br> <caption> <cite> <code> <col> <colgroup> <data> <dd> <del> <dfn> <div> <dl> <drupal-entity data-*> <dt> <em> <figcaption> <figure> <h1> <h2> <h3> <h4> <h5> <h6> <hr> <i> <ins> <kbd> <li> <main> <mark> <meter> <ol> <p> <pre> <q> <rb> <rp> <rt> <rtc> <ruby> <s> <samp> <section> <small> <span> <strong> <sub> <sup> <table> <tbody> <td> <tfoot> <th> <thead> <time> <tr> <u> <ul> <var> <wbr>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'entity_embed' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'editor_align' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
