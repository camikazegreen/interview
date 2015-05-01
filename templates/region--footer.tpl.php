<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($logo || $content): ?>
<div class="container">
	<?php if ($logo): ?>
		<div class="footer-logo">
			<?php if ($ua_zen_footer_logo != "/"): ?>
					<img src="<?php print $ua_zen_footer_logo; ?>" alt="" />
			<?php else: ?>
					<img src="<?php print $logo; ?>" alt="" />
			<?php endif; ?>
		</div>
	<?php endif; ?>
	<?php if ($content): ?>
		<div class="footer-content clearfix">
			<?php print $content; ?>
		</div>
	<?php endif; ?>
</div>
<?php endif; ?>