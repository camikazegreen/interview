<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<footer id="footer_site" class="<?php print $classes; ?>">
  	<div class="container">
  		<div class="footer-logo">
		  	<?php if ($ua_zen_footer_logo != "/"): ?>
		  		<img src="<?php print $ua_zen_footer_logo; ?>" alt="" />
		  	<?php else: ?>
		  		<img src="<?php print $logo; ?>" alt="" />
	    	<?php endif; ?>
    	</div>
    	<?php print $content; ?>
  	</div>
</footer>
