/**
 * ua_quickstart generated home page content.
 *
 * Check the basic layout of the default homepage that ua_quickstart
 * generates on a new site.
 */
casper.test.begin("UA Quickstart homepage", 7, function suite(test) {
  var rootpath = '/'; // Assuming we're in the context of a running Drupal site.

  casper.start();

  casper.thenOpen(rootpath function() {
    test.assertHttpStatus(200, 'opens with an HTTP Success status code');
    // Major page region structure
    test.assertExists('#l_page', 'has the outermost page container (#l_page)');
    test.assertExists('#l_page #header_ua', 'has the UofA header (#header_ua)');
    test.assertExists('#l_page #header_site', 'has the site-specific header (#header_site)');
    test.assertExists('#l_page #content_featured', 'has the featured content region (#content_featured)');
    test.assertExists('#l_page #content', 'has the main content (#content)');
    test.assertExists('#l_page #footer_site', 'has the site-specific footer (#footer_site)');
  });

  casper.run(function() {
    test.done();
  });
});