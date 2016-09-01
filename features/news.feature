Feature: News
  In order to keep visitors up to date on the latest happenings
  As a UA Unit
  I need to have a news area.

  @regression @news
  Scenario: News is displayed from newest to oldest
    Given I am an anonymous user
    When I visit "/news"
    Then I should see "Wednesday, September 9, 2015" in the ".date-display-single" element
    And I should not see "Saturday, March 14, 2015" in the ".date-display-single" element

  @regression @news
  Scenario: A news block is displayed on the home page.
    Given I am an anonymous user
    When I visit "/"
    Then I should see "News" in the "#block-views-uaqs-news-three-col-news-block" element

  @regression @news
  Scenario: Paragraphs items migrated correctly into the news content type and is visible to anonymous visitors to the site.
    Given I am an anonymous user
    When I am at 'news/2015/09/new-light-origins-“bear-down”'
    Then I should see the text "“Button” Salmon"
