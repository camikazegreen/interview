@flexible-page @api @content-manager
Feature: Content manager creates flexible page.
  As a Content Manager
  I want to create a flexible page.
  So that all of my content doesn't look the same.

  Background: Cas is disabled
    Given I run drush dis "-y cas"

  Scenario: Paragraphs item types exist.
    Given I am logged in as a user with the administrator role
    And I am viewing my "Flexible Page" with the title "Renaming the Pride of Arizona marching band"
    When I click Edit
    Then I should see the text "Add Image with caption"
    And I should see the text "Add UAQS Plain Text"
    And I should see the text "Add Text with heading"
    And I should see the text "Add Extra info"
