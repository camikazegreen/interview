# UA Zen #

The UA Zen theme is a Drupal subtheme of Zen using the UA's new branding guidelines.
It incorporates the the UA Bootstrap framework to provide lots of helpful classes for designers and developers.

## Dependencies

Bootstrap javascript requires jQuery 1.9+

If you don't want to use jQuery Update, and add the required jQuery version another way, you can suppress the jQuery version message within the theme settings.

## Making a UA Zen subtheme ##

The following instructions make a new subtheme called ua_zen_subtheme.
Change any instance of this into whatever you want your subtheme to be called, but make sure to use underscores, not spaces or dashes.

1. Create a new directory in your sites/all/themes called ua_zen_subtheme.

2. Create a new .info file in your subtheme's folder, ua_zen_subtheme.info

3. Add the .info example below in your new .info file:

4. Create the css folder in your subtheme.

5. Create the overrides.css and place it in the css folder. Add some new styles like in the styles example below.

6. If you already have a logo for your site, place it in the subtheme's folder as `logo.png`. If not, copy the placeholder from ua_zen.

.info Example:

    name = UA Zen Subtheme
    description = The University of Arizona's official sub-theme for UA Zen. Make all of your changes in this theme so that you can update to the latest UAZen.
    core = 7.x
    base theme = ua_zen

    ; Optionally add some Javacript files to your theme.
    ; scripts[] = js/script.js

    ; Optionally add an overrides file.
    stylesheets[all][] = css/overrides.css

styles Example:

    body {
      background: red;
    }
