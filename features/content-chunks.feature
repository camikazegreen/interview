Feature: Content manager creates flexible page.
  As a Content Manager
  I want to use the flexible page content type.
  So that all of my content doesn't look the same.

  Background: Cas is disabled
    Given I run drush dis "-y cas"

  @regression @flexible-page
  Scenario: Paragraphs items migrated correctly into the flexible page content type and is visible to anonymous visitors to the site.
    Given I am an anonymous user
    When I am at 'content/renaming-pride-arizona-marching-band'
    Then I should see the text "Inspired by a famous painting"
    And I should see the text "Reviving little-heard instruments"
    And I should see the text "Superbia (detail)"
    And I should see the text "The seven deadly sins and four last things"

  @regression @news
  Scenario: Paragraphs items migrated correctly into the news content type and is visible to anonymous visitors to the site.
    Given I am an anonymous user
    When I am at 'news/2015/09/new-light-origins-“bear-down”'
    Then I should see the text "“Button” Salmon"

  @regression @flexible-page @api
  Scenario: Basic paragraphs item types are available for use by administrators editing a piece of flexible content.
    Given I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add Image with caption"
    And I should see the text "Add UAQS Plain Text"
    And I should see the text "Add Text with heading"
    And I should see the text "Add Extra info"

  @regression @flexible-page @api
  Scenario: As an administrator there are some paragraphs item types I do not want to see when editing a flexible page.
    Given I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should not see the text "Add Full width background wrapper"
    And I should not see the text "Add Card deck"
    And I should not see the text "Add File attachment"
    And I should not see the text "Add HTML Field"

  @regression @flexible-page @api
  Scenario: Paragraphs item type "Full width background wrapper" is usable by administrators after enabling the feature.
    Given I run drush en "-y uaqs_content_chunks_full_width_bg_wrapper"
    And I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add Full width background wrapper"

  @regression @flexible-page @api
  Scenario: Paragraphs item type "Card deck" is usable by administrators after enabling the feature.
    Given I run drush en "-y uaqs_content_chunks_card_deck"
    And I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add Card deck"

  @regression @flexible-page @api
  Scenario: Paragraphs item type "File attachment" is usable by administrators after enabling the feature.
    Given I run drush en "-y uaqs_content_chunks_file_download"
    And I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add File attachment"

  @regression @flexible-page @api
  Scenario: Paragraphs item type "HTML Field" is usable by administrators after enabling the feature.
    Given I run drush en "-y uaqs_content_chunks_html"
    And I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add HTML Field"
