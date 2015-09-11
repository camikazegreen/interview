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
  <?php // Defined in template file: region--header-ua.tpl.php. ?>
  <?php print render($page['header_ua']); ?>
  <header class="header" id="header_site" role="banner">
    <div class="container">

      <?php // If the logo option is on, do not display the site name and slogan. ?>
      <?php if ($logo):?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
      <?php endif; ?>

      <?php if ($secondary_menu): ?> <!-- Using Secondary Menu for Utility Links -->
        <div class="header__secondary-menu" id="utility_links" role="navigation"> <!-- id was #secondary-menu -->
          <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
        </div>
      <?php endif; ?>

      <?php print render($page['header']); ?>

    </div> <!-- /.container -->
    <div class="container">
      <nav id="main_nav" class="navbar navbar-default navbar-static-top">
        <div class="row">
          <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
              <span class="sr-only">Toggle navigation</span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
            </button>
          </div>
          <div id="navbar" class="navbar-collapse collapse">
            <?php print render($page['navigation']); ?>
          </div>
        </div>
        <!-- /.nav-collapse-->
        </nav>
      </div>
  </header>

  <div id="main">
    <section id="content_featured">
      <?php print render($page['content_featured']); ?>
    </section>

    <div class="container">
      <div class="row">
        <section id="content" <?php print $content_column_class; ?> role="main">
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
        </section>
        <?php if (!empty($page['sidebar_first']) && empty($page['sidebar_second'])): ?>
          <aside class="col-sm-3 col-sm-pull-9" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside>  <!-- /#sidebar-first -->
        <?php endif; ?>
        <?php if (!empty($page['sidebar_first']) && !empty($page['sidebar_second'])): ?>
          <aside class="col-sm-3 col-sm-pull-6" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside>  <!-- /#sidebar-first -->
        <?php endif; ?>
        <?php if (!empty($page['sidebar_second'])): ?>
          <aside class="col-sm-3" role="complementary">
            <?php print render($page['sidebar_second']); ?>
          </aside>  <!-- /#sidebar-second -->
        <?php endif; ?>
      </div>
    </div> <!-- /.container -->
  </div> <!-- /.main -->

  <footer id="footer_site" class="<?php print $classes; ?>">
    <?php print render($page['footer']); ?>
    <?php print render($page['footer_sub']); ?>
  </footer>
</div>

<?php print render($page['bottom']); ?>
