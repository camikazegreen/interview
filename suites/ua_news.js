/**
 * UA Quickstart News test suite.
 */
casper.test.begin('News dates sort properly in the news view', function suite(test) {
  casper.start("/news", function() {
    test.assertTitleMatch(/News/, 'has News in the title');

    var dates = this.evaluate(function() {
      var dateClass = '.date-display-single';
      var elements = __utils__.findAll(dateClass);
      return elements.map(function(e) {
        return e.innerHTML;
      });
    });

    var expected = ['Wednesday, September 9, 2015',
                    'Tuesday, July 21, 2015',
                    'Monday, May 4, 2015',
                    'Saturday, March 14, 2015',];

    test.assertEquals(dates[0], expected[0]);
    test.assertEquals(dates[1], expected[1]);
    test.assertEquals(dates[2], expected[2]);
    test.assertEquals(dates[3], expected[3]);

    test.assertNotEquals(dates[0], expected[1]);
    test.assertNotEquals(dates[0], expected[2]);
    test.assertNotEquals(dates[0], expected[3]);
    test.assertNotEquals(dates[1], expected[0]);
    test.assertNotEquals(dates[1], expected[2]);
    test.assertNotEquals(dates[1], expected[3]);
    test.assertNotEquals(dates[2], expected[0]);
    test.assertNotEquals(dates[2], expected[1]);
    test.assertNotEquals(dates[2], expected[3]);
  });

  casper.run(function() {
    test.done();
  });
});
