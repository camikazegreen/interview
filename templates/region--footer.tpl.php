<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($content): ?>
  <footer id="footer_site" class="<?php print $classes; ?>">
  	<div class="container">
  		<?php print $ua_zen_footer_logo; ?>
    	<?php print $content; ?>
  	</div>
  </footer>
<?php endif; ?>
