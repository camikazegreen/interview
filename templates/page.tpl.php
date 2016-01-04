<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
  <?php if (!empty($page['alert'])) : ?>
  <section class="container">
      <div class="row">
          <div class="col-xs-12">
              <?php print render($page['alert']); ?>
          </div>
      </div>
  </section>
  <?php endif; ?>
  <?php // Defined in template file: region--header-ua.tpl.php. ?>
  <?php if (!empty($page['header_ua'])) : ?>
  <?php print render($page['header_ua']); ?>
  <?php endif; ?>
  <header class="header page-row" id="header_site" role="banner">
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
    <?php if (!empty($page['navigation'])) : ?>
    <div class="container">
      <nav id="main_nav" class="navbar navbar-default navbar-static-top">
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
        <!-- /.nav-collapse-->
        </nav>
      </div>
      <?php endif; ?>
  </header>

  <div id="main" class="page-row page-row-expanded">
    <?php if (!empty($page['help']) || ($messages)) : ?>
    <section class="container">
        <div class="row">
            <div class="col-xs-12">
                <?php print $messages; ?>
                <?php if (!empty($page['help'])) : ?>
                <?php print render($page['help']); ?>
                <?php endif; ?>
            </div>
        </div>
    </section>
    <?php endif; ?>
    <?php if (!empty($page['content_featured'])) : ?>
    <section id="content_featured">
      <?php print render($page['content_featured']); ?>
    </section>
    <?php endif; ?>
    <div class="container">
      <div class="row">
        <?php if (!empty($page['highlighted'])) : ?>
        <div class="col-xs-12">
          <?php print render($page['highlighted']); ?>
        </div>
        <?php endif; ?>
        <article id="content" <?php print $content_column_class_top; ?> role="main">
          <?php print $breadcrumb; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php print render($tabs); ?>
          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
          <?php if (!empty($page['content_top'])) : ?>
            <?php print render($page['content_top']); ?>
          <?php endif; ?>
          </article>
          <?php if (!empty($page['sidebar_first_top']) && empty($page['sidebar_second_top'])): ?>
            <aside class="col-sm-3 col-sm-pull-9" role="complementary">
              <?php print render($page['sidebar_first_top']); ?>
            </aside>  <!-- /#sidebar-first-top -->
          <?php endif; ?>
          <?php if (!empty($page['sidebar_first_top']) && !empty($page['sidebar_second_top'])): ?>
            <aside class="col-sm-3 col-sm-pull-6" role="complementary">
              <?php print render($page['sidebar_first_top']); ?>
            </aside>  <!-- /#sidebar-first-top -->
          <?php endif; ?>
          <?php if (!empty($page['sidebar_second_top'])): ?>
            <aside class="col-sm-3" role="complementary">
              <?php print render($page['sidebar_second_top']); ?>
            </aside>  <!-- /#sidebar-second-top -->
          <?php endif; ?>
          <div class="row"></div>
          <?php if (!empty($page['full_width_content_top'])) : ?>
            <?php print render($page['full_width_content_top']); ?>
          <?php endif; ?>
          <article <?php print $content_column_class_body; ?>>
          <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
          </article>
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
          <?php if (!empty($page['full_width_content_bottom'])) : ?>
            <?php print render($page['full_width_content_bottom']) ?>
          <?php endif; ?>
          <?php if (!empty($page['content_2_col_1']) || !empty($page['content_2_col_2'])) : ?>
                  <div class="col-md-6">
                      <?php print render($page['content_2_col_1']); ?>
                  </div>
                  <div class="col-md-6">
                      <?php print render($page['content_2_col_2']); ?>
                  </div>
          <?php endif; ?>
          <?php if (!empty($page['content_3_col_1']) || !empty($page['content_3_col_2']) || !empty($page['content_3_col_3'])) : ?>
                  <div class="col-md-4">
                      <?php print render($page['content_3_col_1']); ?>
                  </div>
                  <div class="col-md-4">
                      <?php print render($page['content_3_col_2']); ?>
                  </div>
                  <div class="col-md-4">
                      <?php print render($page['content_3_col_3']); ?>
                  </div>
          <?php endif; ?>
      <div class="row"></div>
        <article class="col-xs-12" role="complementary">
          <?php if (!empty($page['content_bottom'])) : ?>
             <?php print render($page['content_bottom']); ?>
          <?php endif; ?>
        <?php if (!empty($page['content_4_col_1']) || !empty($page['content_4_col_2']) || !empty($page['content_4_col_3']) || !empty($page['content_4_col_4'])) : ?>
            <div class="row">
            <div class="col-md-3">
                <?php print render($page['content_4_col_1']); ?>
            </div>
            <div class="col-md-3">
                <?php print render($page['content_4_col_2']); ?>
            </div>
            <div class="col-md-3">
                <?php print render($page['content_4_col_3']); ?>
            </div>
            <div class="col-md-3">
                <?php print render($page['content_4_col_4']); ?>
            </div>
            </div>
        <?php endif; ?>
        </article>
      </div> <!-- /.row -->
    </div> <!-- /.container -->
  </div> <!-- /.main -->

  <footer id="footer_site" class="<?php print $classes; ?> page-row">
    <?php print render($page['footer']); ?>
    <?php print render($page['footer_sub']); ?>
  </footer>

<?php print render($page['bottom']); ?>

