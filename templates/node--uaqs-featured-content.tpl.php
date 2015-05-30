<?php print render($title_prefix); ?>
<a href="<?php print render($ua_featured_content['path']); ?>">
  <div class="slide-image-container" style="background-image: url('<?php print render($ua_featured_content['image_path']); ?>')">
      <div class="mask white">
        <h2 class="white noWidows"><?php print render($title); ?></h2>
        <?php print render($content); ?>
      </div>
  </div>
</a>
<?php print render($title_suffix); ?>