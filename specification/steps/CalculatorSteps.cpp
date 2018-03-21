
#include "calculator/Calculator.hpp"
#include "calculator/DividedByZeroException.hpp"

#include <GUnit/GMock.h>
#include <GUnit/GTest.h>
#include <GUnit/GSteps.h>


GSTEPS("Calculator Addition.Add two numbers")
{
    using namespace testing;
    std::int64_t result{};

    Given("I created a calculator with initial value equals {initialValue}"_step) =
            [&](std::int32_t initialValue)
            {
                Calculator calculator{initialValue};


                Given("I add {operand} into the calculator") =
                        [&](std::int32_t operand)
                        {
                            calculator.Add(operand);
                        };

                When("I ask for the result") =
                [&]
                {
                    result = calculator.Result();
                };

                Then("the result should be {expected} on the screen") =
                [&](std::int64_t expected)
                {
                    EXPECT_EQ(expected, result);
                };
            };
}


GSTEPS("Calculator Subtraction.Subtract two numbers")
{
    using namespace testing;
    std::int64_t result{};

    Given("I created a calculator with initial value equals {initialValue}"_step) =
            [&](std::int32_t initialValue)
            {
                Calculator calculator{initialValue};


                Given("I subtract {operand} into the calculator") =
                        [&](std::int32_t operand)
                        {
                            calculator.Sub(operand);
                        };

                When("I ask for the result") =
                        [&]
                        {
                            result = calculator.Result();
                        };

                Then("the result should be {expected} on the screen") =
                        [&](std::int64_t expected)
                        {
                            EXPECT_EQ(expected, result);
                        };
            };
}

GSTEPS("Calculator Multiplication.Multiply two numbers")
{
    using namespace testing;
    std::int64_t result{};

    Given("I created a calculator with initial value equals {initialValue}"_step) =
            [&](std::int32_t initialValue)
            {
                Calculator calculator{initialValue};


                Given("I multiply it by {operand}") =
                        [&](std::int32_t operand)
                        {
                            calculator.Mul(operand);
                        };

                When("I ask for the result") =
                        [&]
                        {
                            result = calculator.Result();
                        };

                Then("the result should be {expected} on the screen") =
                        [&](std::int64_t expected)
                        {
                            EXPECT_EQ(expected, result);
                        };
            };
}

GSTEPS("Calculator Division.Divide two numbers")
{
    using namespace testing;
    std::int64_t result{};

    Given("I created a calculator with initial value equals {initialValue}"_step) =
            [&](std::int32_t initialValue)
            {
                Calculator calculator{initialValue};


                Given("I divide it with {operand}") =
                        [&](std::int32_t operand)
                        {
                            calculator.Div(operand);
                        };

                When("I ask for the result") =
                        [&]
                        {
                            result = calculator.Result();
                        };

                When("I ask for the result, there should be a {expected} exception") =
                        [&](std::int64_t expected)
                        {
                            EXPECT_THROW(calculator.Result(), DividedByZeroException);
                        };

                Then("the result should be {expected} on the screen") =
                        [&](std::int64_t expected)
                        {
                            EXPECT_EQ(expected, result);
                        };


            };
}