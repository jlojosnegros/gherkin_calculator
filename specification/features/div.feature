# language: en
Feature: Calculator Division
  As a final user
  I want to be able to divide two numbers

  Scenario: Divide two numbers
    Given I created a calculator with initial value equals 10
    And I divide it with 10
    When I ask for the result
    Then the result should be 1 on the screen

  Scenario: Divide two numbers
    Given I created a calculator with initial value equals 12
    And I divide it with 10
    When I ask for the result
    Then the result should be 1 on the screen

  Scenario: Divide two numbers
    Given I created a calculator with initial value equals 12
    And I divide it with 0
    When I ask for the result, there should be a DividedByZeroException exception
