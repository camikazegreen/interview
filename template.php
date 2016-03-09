<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */

include_once dirname(__FILE__) . '/includes/common.inc';

drupal_add_js('//maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js', array(
        'type' => 'external',
        'group' => JS_THEME,
        'scope' => 'footer',
        'weight' => 3,
        )
);
/**
 * Implements hook_css_alter().
 *
 * Adds UA Bootstrap CSS based on theme settings.
 */
function ua_zen_css_alter(&$css) {

  // Exclude specified CSS files from theme.
  $excludes = ua_zen_get_theme_info(NULL, 'exclude][css');
  $ua_bootstrap_path = '';
  $ua_bootstrap_source = theme_get_setting('ua_bootstrap_source');
  $ua_bootstrap_minified = theme_get_setting('ua_bootstrap_minified');

  $ua_bootstrap_css_info = array(
    'every_page' => TRUE,
    'media' => 'all',
    'preprocess' => FALSE,
    'group' => CSS_THEME,
    'browsers' => array('IE' => TRUE, '!IE' => TRUE),
    'weight' => -2,
  );

  if ($ua_bootstrap_source == 'cdn') {
    $ua_bootstrap_cdn_version = theme_get_setting('ua_bootstrap_cdn_version');
    if ($ua_bootstrap_cdn_version == 'stable') {
      $ua_bootstrap_cdn_version = UA_ZEN_UA_BOOTSTRAP_STABLE_VERSION;
    }
    $ua_bootstrap_path = '//bitbucket.org/uadigital/ua-bootstrap/downloads/ua-bootstrap-' . $ua_bootstrap_cdn_version;
    $ua_bootstrap_css_info['type'] = 'external';
  }
  else {
    $ua_bootstrap_path = drupal_get_path('theme', 'ua_zen') . "/css/ua-bootstrap-" . UA_ZEN_UA_BOOTSTRAP_STABLE_VERSION;
    $ua_bootstrap_css_info['type'] = 'file';
  }

  if ($ua_bootstrap_minified) {
    $ua_bootstrap_path .= ".min";
  }
  $ua_bootstrap_path .= ".css";

  $ua_bootstrap_css_info['data'] = $ua_bootstrap_path;
  $css[$ua_bootstrap_path] = $ua_bootstrap_css_info;

  if (!empty($excludes)) {
    $css = array_diff_key($css, drupal_map_assoc($excludes));
  }
}


/**
 * Custom function for the secondary footer logo option.
 */

function ua_zen_footer_logo() {
  $str_return = "";
  $str_footer_logo_path = theme_get_setting('footer_logo_path');

  if (strlen($str_footer_logo_path) > 0) {
    $str_url = file_create_url($str_footer_logo_path);
    $str_return = "<img src=\"" . $str_url . "\" alt=\"\" />";

  }
  return $str_return;
}

// http://getbootstrap.com/css/#overview-responsive-images
function ua_zen_preprocess_image_style(&$vars) {
  if(!module_exists('image_class')){
    $vars['attributes']['class'][] = 'img-responsive';
  }
}


/**
 * Returns HTML for status and/or error messages, grouped by type.
 *
 * An invisible heading identifies the messages for assistive technology.
 * Sighted users see a colored box. See http://www.w3.org/TR/WCAG-TECHS/H69.html
 * for info.
 *
 * @param array $variables
 *   An associative array containing:
 *   - display: (optional) Set to 'status' or 'error' to display only messages
 *     of that type.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_status_messages()
 *
 * @ingroup theme_functions
 */

function ua_zen_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
    'info' => t('Informative message'),
  );

  // Map Drupal message types to their corresponding Bootstrap classes.
  // @see http://twitter.github.com/bootstrap/components.html#alerts
  $status_class = array(
    'status' => 'success',
    'error' => 'danger',
    'warning' => 'warning',
    // Not supported, but in theory a module could send any type of message.
    // @see drupal_set_message()
    // @see theme_status_messages()
    'info' => 'info',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $class = (isset($status_class[$type])) ? ' alert-' . $status_class[$type] : '';
    $output .= "<div class=\"alert alert-block$class messages $type\" role=\"alertdialog\" aria-labelledby=\"$status_class[$type]-label\" aria-describedby=\"$status_class[$type]-description\">\n";
    $output .= "  <span class=\"glyphicon glyphicon-exclamation-sign sr-only\" aria-hidden=\"true\"></span>\n";
    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\" aria-hidden=\"true\"><i class=\"ua-brand-x\" aria-hidden=\"true\"></i></a>\n";

    if (!empty($status_heading[$type])) {
        $output .= "<h4 aria-hidden=\"true\" class=\"sr-only\" id=\"$status_class[$type]-label\">$status_heading[$type]</h4>\n";
    }

    if (count($messages) > 1) {
      $output .= " <ul id=\"$status_class[$type]-description\">\n";
      foreach ($messages as $message) {
        $has_link = strstr($message, 'href');
        if ($has_link){
            $message = str_replace('href=', 'class="alert-link" href=', $message);
        }
        $output .= "  <li role=\"alert\">$message</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
        $has_link = strstr($messages[0], 'href');
        if ($has_link){
            $messages[0] = str_replace('href', 'class="alert-link" href', $messages[0]);
        }
        $output .= "<span id=\"$status_class[$type]-description\" role=\"alert\">$messages[0]</span>";
        }

    $output .= "</div>\n";
  }
  return $output;
}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  ua_zen_preprocess_html($variables, $hook);
  ua_zen_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

function ua_zen_preprocess_html(&$variables) {
    $variables['html_attributes_array']['class'][]= 'sticky-footer';
}

/**
 * Override or insert variables into the page templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function ua_zen_preprocess_page(&$variables, $hook) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['second_sidebar_column_class'] = ' class="col-sm-3"';
    $variables['content_column_class'] = ' class="column col-sm-6 col-sm-push-3"';
  }
  elseif (!empty($variables['page']['sidebar_first']) && empty($variables['page']['sidebar_second'])) {
    $variables['second_sidebar_column_class'] = ' class="col-sm-3"';
    $variables['content_column_class'] = ' class="column col-sm-9 col-sm-push-3"';
  }
  elseif (empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-7 col-md-8 col-lg-8 col-8 column"';
    $variables['second_sidebar_column_class'] = ' class="col-sm-5 col-md-4 col-lg-4 column"';
  }
  else {
    $variables['second_sidebar_column_class'] = ' class="col-sm-3"';
    $variables['content_column_class'] = ' class="column col-sm-12"';
  }
  // Allows there to be a template file for the UA Header and Footers without
  // allowing blocks to be placed there - regions defined in .info, but
  // commented out.
  if (!isset($variables['page']['header_ua']) || empty($variables['page']['header_ua'])) {
    $variables['page']['header_ua'] = array(
      '#region' => 'header_ua',
      '#weight' => '-10',
      '#theme_wrappers' => array('region'));
  }
  if (!isset($variables['page']['footer']) || empty($variables['page']['footer'])) {
    $variables['page']['footer'] = array(
      '#region' => 'footer',
      '#weight' => '-10',
      '#theme_wrappers' => array('region'));
  }
  // Force sub footer to be rendered.
  if (!isset($variables['page']['footer_sub']) || empty($variables['page']['footer_sub'])) {
    $variables['page']['footer_sub'] = array(
      '#region' => 'footer_sub',
      '#weight' => '-10',
      '#theme_wrappers' => array('region'));
  }
  // Primary nav.
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links.
    $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function.
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }
  // Allow hiding of title of front page node
  if (theme_get_setting('ua_zen_hide_front_title') == 1 && drupal_is_front_page()){
    $variables['title'] = FALSE;
  }

}

/**
 * Override or insert variables into the node templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // ua_zen_preprocess_node_page() or ua_zen_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("region" in this case.)
 */
function ua_zen_preprocess_region(&$variables, $hook) {
  $str_footer_logo_html = "";
  $str_logo_path = "";
  $str_copyright_notice = "";
  switch ($variables['region']) {
    case "footer":
      $str_footer_logo_html = ua_zen_footer_logo();

      if (strlen($str_footer_logo_html) == 0) {
        $str_logo_path = theme_get_setting('logo');
        if (strlen($str_logo_path) > 0) {
          $str_footer_logo_html = "<img class='img-responsive' src='" . file_create_url($str_logo_path) . "' alt='' />";
        }
      }
      break;

    case "footer_sub":
      $str_copyright_notice = theme_get_setting('ua_copyright_notice');
      if (strlen($str_copyright_notice) > 0) {
        $str_copyright_notice = "<p class=\"copyright\">&copy; " . date('Y') . " " . $str_copyright_notice . "</p>";
      }
      else {
        $str_copyright_notice = "<p class=\"copyright\">&copy; " . date('Y') . " The Arizona Board of Regents on behalf of <a href=\"http://www.arizona.edu\" target=\"_blank\">The University of Arizona</a>.</p>";
      }
      break;
  }

  $variables['copyright_notice'] = $str_copyright_notice;
  $variables['footer_logo'] = $str_footer_logo_html;
}

/**
 * Override or insert variables into the block templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function ua_zen_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
 * Implements theme_form_search_block_form_alter.
 */
function ua_zen_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['placeholder'] = t('Search Site');
  $form['search_block_form']['#attributes']['onfocus'] = "this.placeholder = ''";
  $form['search_block_form']['#attributes']['onblur'] = "this.placeholder = '" . t('Search Site') . "'";
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $variables
 *   - title: An optional string to be used as a navigational heading to give
 *     context for breadcrumb links to screen-reader users.
 *   - title_attributes_array: Array of HTML attributes for the title. It is
 *     flattened into a string within the theme function.
 *   - breadcrumb: An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function ua_zen_preprocess_breadcrumb(&$variables) {
  $breadcrumb = &$variables['breadcrumb'];

  // Optionally get rid of the homepage link.
  $show_breadcrumb_home = theme_get_setting('zen_breadcrumb_home');
  if (!$show_breadcrumb_home) {
    array_shift($breadcrumb);
  }

  if (theme_get_setting('zen_breadcrumb_title') && !empty($breadcrumb)) {
    $item = menu_get_item();
    $breadcrumb[] = array(
      // If we are on a non-default tab, use the tab's title.
      'data' => !empty($item['tab_parent']) ? check_plain($item['title']) : drupal_get_title(),
      'class' => array('active'),
    );
  }
}

function ua_zen_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $output = '';

  // Determine if we are to display the breadcrumb.
  $show_breadcrumb = theme_get_setting('zen_breadcrumb');
  if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {
    $output = theme('item_list', array(
      'attributes' => array(
        'class' => array('breadcrumb'),
      ),
      'items' => $breadcrumb,
      'type' => 'ol',
    ));
  }
  return $output;
}

/**
 * Overrides theme_menu_local_tasks().
 */
function ua_zen_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="sr-only">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs--primary nav nav-tabs">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="sr-only">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 *  Theme wrapper function for the uaqs_second_level menu block.
 */
function ua_zen_menu_tree__menu_block__uaqs_second_level(array $variables) {

  $output = '<ul class="nav nav-pills nav-stacked">' . $variables['tree'] . '</ul>';

  return $output;
}

/**
 *  Theme wrapper function for the primary menu links.
 */
function ua_zen_menu_tree__primary(&$variables) {
      return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul><div class="clearfix"></div>';
}

/**
 * Overrides theme_menu_link().
 */
function ua_zen_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if (($element['#original_link']['depth'] <= 1)) {
      $element['#localized_options']['attributes']['class'][] = 'text-uppercase';
  }
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
      $element['#localized_options']['attributes']['role'] = 'button';
      $element['#localized_options']['attributes']['aria-haspopup'] = 'true';
      $element['#localized_options']['attributes']['aria-expanded'] = 'false';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Overrides theme_menu_link().
 *
 * Restores default behavior for menu blocks.
 *
 * @see https://www.drupal.org/node/1850194
 */
function ua_zen_menu_link__menu_block($variables) {
  return theme_menu_link($variables);
}

/**
 * Returns HTML for a query pager.
 *
 * Menu callbacks that display paged query results should call theme('pager') to
 * retrieve a pager control so that users can view other results. Format a list
 * of nearby pages with additional query results.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tags: An array of labels for the controls in the pager.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *   - quantity: The number of pages in the list.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_pager()
 *
 * @ingroup theme_functions
 */
function ua_zen_pager($variables) {
  $output = "";
  $items = array();
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];

  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }

  // End of generation loop preparation.
  $li_first = theme('pager_first', array(
    'text' => (isset($tags[0]) ? $tags[0] : t('first')),
    'element' => $element,
    'parameters' => $parameters,
  ));
  $li_previous = theme('pager_previous', array(
    'text' => (isset($tags[1]) ? $tags[1] : t('previous')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));
  $li_next = theme('pager_next', array(
    'text' => (isset($tags[3]) ? $tags[3] : t('next')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));
  $li_last = theme('pager_last', array(
    'text' => (isset($tags[4]) ? $tags[4] : t('last')),
    'element' => $element,
    'parameters' => $parameters,
  ));
  if ($pager_total[$element] > 1) {

    // Only show "first" link if set on components' theme setting
    if ($li_first && theme_get_setting('ua_zen_pager_first_and_last')) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('prev'),
        'data' => $li_previous,
      );
    }
    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            // 'class' => array('pager-item'),
            'data' => theme('pager_previous', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            )),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            // Add the active class.
            'class' => array('active'),
            'data' => "<span>$i</span>",
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'data' => theme('pager_next', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            )),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('next'),
        'data' => $li_next,
      );
    }
    // // Only show "last" link if set on components' theme setting
    if ($li_last && theme_get_setting('ua_zen_pager_first_and_last')) {
      $items[] = array(
       'class' => array('pager-last'),
       'data' => $li_last,
      );
    }

    $build = array(
      '#theme_wrappers' => array('container__pager'),
      '#attributes' => array(
        'class' => array(
          'text-center',
        ),
      ),
      'pager' => array(
        '#theme' => 'item_list',
        '#items' => $items,
        '#attributes' => array(
          'class' => array('pagination'),
        ),
      ),
    );
    return drupal_render($build);
  }
  return $output;
}
