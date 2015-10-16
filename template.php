<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */
drupal_add_js('//maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js', array(
        'type' => 'external',
        'group' => JS_THEME,
        'scope' => 'footer',
        'weight' => 3,
        )
);
/**
 ** Add UA Bootstrap
 **/

drupal_add_css('//bitbucket.org/uadigital/ua-bootstrap/downloads/ua-bootstrap-latest.min.css', array('type' => 'external'));
//drupal_add_css(drupal_get_path('theme', 'ua_zen') . '/css/ua-bootstrap-1.0.0-alpha-2.min.css');

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
    $vars['attributes']['class'][] = 'img-responsive';
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
    $variables['content_column_class'] = ' class="column col-sm-6 col-sm-push-3"';
  }
  elseif (!empty($variables['page']['sidebar_first']) && empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="column col-sm-9 col-sm-push-3"';
  }
  elseif (empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="column col-sm-9 col-sm-3"';
  }
  else {
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


function ua_zen_menu_tree__menu_block__ua_second_level(array $variables) {

  $output = '<ul class="nav nav-pills nav-stacked">' . $variables['tree'] . '</ul>';

  return $output;
}
/**
 *  * UA Zen theme wrapper function for the primary menu links.
 *   */
function ua_zen_menu_tree__main_menu(&$variables) {
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
      // $element['#localized_options']['attributes']['data-target'] = '#';
      // $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      // $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
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
