<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($footer_logo || $content): ?>
<div class="container">
	<?php if ($footer_logo): ?>
		<div class="footer-logo">
			<?php print $footer_logo; ?>
		</div>
	<?php endif; ?>
	<?php if ($content): ?>
		<div class="footer-content clearfix">
			<?php print $content; ?>
		</div>
	<?php endif; ?>
</div>
<?php endif; ?>