# language: en
Feature: Calculator Addition
  As a final user
  I want to be able to sum two numbers

  Scenario: Add two numbers
    Given I created a calculator with initial value equals 0
    And I add 10 into the calculator
    And I add 20 into the calculator
    When I ask for the result
    Then the result should be 30 on the screen

  Scenario Outline: Add two numbers
    Given I created a calculator with initial value equals 0
    And I add <input_1> into the calculator
    And I add <input_2> into the calculator
    When I ask for the result
    Then the result should be <output> on the screen

    Examples:
      | input_1 | input_2 | output |
      | 20      | 30      |  50     |
      | 2       | 5       |  7      |
      | 0       | 40      |  40     |
      | 3       | 222     |  225    |
