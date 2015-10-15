# Testing Model #

## Casper Regression Tests ##

Casper is a javascript based testing framework.
We have used it specifically for testing the user interface because Casper drives a web browser and interacts with web pages well.

Therefore, the things being testing are not system components, but the products of the system as a whole.
This makes it an **acceptance test**.
Let's take a look at an example in the form of a news test that was created to fix (and guard against) a bug that caused news items to appear in ascending order.
You can find the code in `suites/ua_news.js` in the suite `'News dates sort properly in the news view'`.

### Example ###

#### Problem ####

The news view shows news items, but they are ordered so that the oldest news item appears first and the latest one appears last.

#### Solution Test ####

In the test, we first navigate to the news view and collect all of the dates available on the page for the news items into an array.
We can rely on the demo content installed to act as text fixtures since a lot of thought and discussion has to go into those to change them.

Then, we create an array of the expected dates in the correct order.
Finally, we have a bunch of assertions to make sure the two arrays match up.
We explicitly declare each assertion, rather than have loops handle the matching logic for us.

We want to strongly emphasize readability and this explicit form is much more readable (even though it is more verbose) than a looping form.

### Process Model ###

1. Someone on the team or from the outside notices a bug.
2. If the team thinks it a good idea to create a test for the bug (especially if the bug is difficult to spot or obscure), we create a ticket (parallel to the bug's ticket) to create a test for it.
3. The test for the bug to be fixed can be added to the main repository for Jenkins before the bug is actually fixed, but the team should be aware that all future builds for Jenkins will fail until the new test passes.
4. The test stays in the suite for as long as it can. It can be rewritten if necessary, but should only be removed if it is causing an issue in passing builds for a product that is behaving as expected or is removed completely. The idea should be to continuously add to the test suite rather than subtract from it.
