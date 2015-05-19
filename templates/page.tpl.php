<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="l_page">
  <?php //Defined in template file: region--header-ua.tpl.php ?>
  <?php print render($page['header_ua']); ?>

  <?php // dsm($page); ?>

  <header class="header" id="header_site" role="banner">
    <div class="container">

      <?php if ($logo): //If the logo option is on, do not display the site name and slogan ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
      <?php endif; ?>

      <?php if ($secondary_menu): ?><!-- Using Secondary Menu for Utility Links -->
        <div class="header__secondary-menu" id="utility_links" role="navigation"> <!-- id was #secondary-menu -->
          <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
        </div>
      <?php endif; ?>

      <?php print render($page['header']); ?>

    </div> <!-- /.container -->
    <nav id="main_nav">
      <div class="container">
        <?php print render($page['navigation']); ?>
      </div>
    </nav>
  </header>

  <div id="main">
    <section id="content_featured">
      <?php print render($page['content_featured']); ?>
    </section>

    <div class="container">
      <div id="content" class="column" role="main">
        <?php print render($page['highlighted']); ?>
        <?php print $breadcrumb; ?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </div>

      <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first  = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);
      ?>

      <?php if ($sidebar_first || $sidebar_second): ?>
        <aside class="sidebars">
          <?php print $sidebar_first; ?>
          <?php print $sidebar_second; ?>
        </aside>
      <?php endif; ?>

    </div> <!-- /.container -->
  </div> <!-- /.main -->
  <footer id="footer_site" class="<?php print $classes; ?>">
    <?php print render($page['footer']); ?>
    <?php print render($page['footer_sub']); ?>
  </footer>
</div>

<?php print render($page['bottom']); ?>
