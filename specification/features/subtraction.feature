# language: en
Feature: Calculator Subtraction
  As a final user
  I want to be able to subtract two numbers

  Scenario: Subtract two numbers
    Given I created a calculator with initial value equals 10
    And I subtract 5 into the calculator
    When I ask for the result
    Then the result should be 5 on the screen

  Scenario Outline: Subtract two numbers
    Given I created a calculator with initial value equals <input_1>
    And I subtract <input_2> into the calculator
    When I ask for the result
    Then the result should be <output> on the screen

    Examples:
      | input_1 | input_2 | output |
      | 20      | 30      |  -10     |
      | 2       | 5       |  -3      |
      | 0       | 40      |  -40     |
      | 222     | 3       |  219    |
