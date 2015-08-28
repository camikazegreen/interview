/**
 * UA Quickstart Calendar test suite.
 */
casper.test.begin('Calendar page is formatted properly', 10, function suite(test) {
  casper.start("/calendar", function() {
    test.assertTitleMatch(/UA Events/, 'has UA Events in the title');
    var header = '.date-heading';
    var date = new Date();
    test.assertSelectorHasText(header, date.getFullYear());
    test.assertSelectorDoesntHaveText(header, '1,', 'it looks like the date header has the first day of the month');
    test.assertSelectorDoesntHaveText(header, 'Sunday');
    test.assertSelectorDoesntHaveText(header, 'Monday');
    test.assertSelectorDoesntHaveText(header, 'Tuesday');
    test.assertSelectorDoesntHaveText(header, 'Wednesday');
    test.assertSelectorDoesntHaveText(header, 'Thursday');
    test.assertSelectorDoesntHaveText(header, 'Friday');
    test.assertSelectorDoesntHaveText(header, 'Saturday');
  });

  casper.run(function() {
    test.done();
  });
});
