<?php

/**
 * @file
 * Default theme implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top class.
 * - $region: The name of the region variable as defined in the theme's .info file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="<?php print $classes; ?> l-arizona-header red-bg" id="header_ua">
  <div class="ua-redbar-v1">
    <nav class="redbar navbar-static-top" role="navigation">
      <div class="container">
        <div class="navbar-header">
          <a class="redbar-brand" href="http://www.arizona.edu"><p>The University of Arizona</p></a>
        </div>
      </div>
    </nav>
  </div>
 <!-- Chris Green's code: -->
	<!-- commenting out for now
  <button class="hamburger pull-left hidden-md hidden-sm hidden-lg" data-target=".arizona-menu-collapse" data-toggle="collapse" type="button">
    <span class="sr-only">Toggle navigation</span>
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
  </button> -->
  <!--
  <a class="arizona-logo arizona-line-logo" href="http://www.arizona.edu" title="The University of Arizona homepage" target="_blank">
    <img alt="The University of Arizona Wordmark Line Logo White" class="arizona-line-logo" src="/<?php print drupal_get_path('theme',$GLOBALS['theme']); ?>/images/ua_wordmark_line_logo_white_RGB.svg" />
  </a> -->
  <!-- commenting out for now
  <div class="collapse arizona-menu-collapse">
    <ul class="arizona-menu">
      <li class="first">
        <a href="http://arizona.edu/apply">apply</a>
      </li>                
      <li>
        <a href="http://arizona.edu/visit">visit</a>
      </li>                
      <li>
        <a href="http://arizona.edu/give">give<span class="caret"></span></a>
      </li>
    </ul>
  </div> -->
</div>
