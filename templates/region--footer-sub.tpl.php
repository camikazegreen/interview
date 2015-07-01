<?php
/**
 * @file
 * Returns the HTML for the sub footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($copyright_notice || $content): ?>
<div id="footer_sub" class="<?php print $classes; ?>">
  	<div class="container">
    	<?php print $content; ?>
	    <?php print $copyright_notice ?>
  	</div>
</div>
<?php endif ?>
