# language: en
Feature: Calculator Multiplication
  As a final user
  I want to be able to multiply two numbers

  Scenario: Multiply two numbers
    Given I created a calculator with initial value equals 10
    And I multiply it by 20
    When I ask for the result
    Then the result should be 200 on the screen

  Scenario Outline: Multiply two numbers
    Given I created a calculator with initial value equals <input_1>
    And I multiply it by <input_2>
    When I ask for the result
    Then the result should be <output> on the screen

    Examples:
      | input_1 | input_2 | output |
      | 20       | -30      |  -600 |
      | -2       | -5       |  10   |
      | 0        | 40      |  0     |
      | 3        | 222     |  666   |
