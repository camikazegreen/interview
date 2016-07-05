Feature: Content manager creates flexible page.
  As a Content Manager
  I want to use the flexible page content type.
  So that all of my content doesn't look the same.

  Background: Cas is disabled
    Given I run drush dis "-y cas"

  @regression @flexible-page @api @content-manager
    Scenario: Paragraphs item migrated correctly.
    Given I am an anonymous user
    Given I am at 'content/renaming-pride-arizona-marching-band'
    Then I should see the text "Inspired by a famous painting"
    And I should see the text "Reviving little-heard instruments"
    And I should see the text "Superbia (detail)"
    And I should see the text "The seven deadly sins and four last things"
    Given I am at 'news/2015/09/new-light-origins-“bear-down”'
    Then I should see the text "“Button” Salmon"

  @regression @flexible-page @api @content-manager
  Scenario: Paragraphs item types exist.
    Given I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add Image with caption"
    And I should see the text "Add UAQS Plain Text"
    And I should see the text "Add Text with heading"
    And I should see the text "Add Extra info"

  @regression @flexible-page @api @content-manager
  Scenario: Disabled paragraphs item types do not exist.
    Given I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should not see the text "Add Full width background wrapper"
    And I should not see the text "Add Card deck"
    And I should not see the text "Add File attachment"

  @flexible-page @api @content-manager
  Scenario: Paragraphs item type exist after enabling feature.
    Given I run drush en "uaqs_full_width_bg_wrapper_paragraphs_item -y"
    Given I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add Full width background wrapper"
