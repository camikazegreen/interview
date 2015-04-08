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
  		<?php print $footer_logo_url; ?>
    	<?php print $content; ?>
  	</div>
  </footer>
<?php endif; ?>
