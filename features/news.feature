Feature: News
  In order to keep visitors up to date on the latest happenings
  As a UA Unit
  I need to have a news area.

  @regression @javascript
  Scenario: News is displayed from newest to oldest
    Given I am an anonymous user
    When I visit "/news"
    Then I should see "Wednesday, September 9, 2015" in the ".date-display-single" element
    And I should not see "Saturday, March 14, 2015" in the ".date-display-single" element
