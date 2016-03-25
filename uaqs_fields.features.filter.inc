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

  // Exported format: UAQS Textual Content.
  $formats['uaqs_textual_content'] = array(
    'format' => 'uaqs_textual_content',
    'name' => 'UAQS Textual Content',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <abbr> <b> <bdi> <bdo> <br> <cite> <code> <data> <del> <dfn> <em> <i> <ins> <kbd> <mark> <q> <rb> <rp> <rt> <rtc> <ruby> <s> <samp> <small> <span> <strong> <sub> <sup> <time> <u> <var> <wbr>',
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
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <abbr> <article> <aside> <b> <bdi> <bdo> <blockquote> <br> <caption> <cite> <code> <col> <colgroup> <data> <del> <dfn> <div> <dl> <em> <h1> <h2> <h3> <h4> <h5> <h6> <i> <ins> <kbd> <mark> <ol> <p> <pre> <q> <rb> <rp> <rt> <rtc> <ruby> <s> <samp> <section> <small> <span> <strong> <sub> <sup> <table> <tbody> <td> <tfoot> <th> <thead> <time> <tr> <u> <var> <wbr>',
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

  return $formats;
}
