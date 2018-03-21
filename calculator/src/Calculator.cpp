
#include "Calculator.hpp"
#include "DividedByZeroException.hpp"

#include <iostream>

Calculator::Calculator(std::int32_t const& initialValue)
        : currentValue(initialValue)
        , op1(0)
{

}

Calculator& Calculator::Add(std::int32_t const& operand)
{
    currentValue += op1;
    op1 = operand;
    operation = [] (std::int32_t a, std::int32_t b) -> std::int64_t { return a + b;};
    return *this;
}

Calculator& Calculator::Sub(std::int32_t const &operand)
{
    op1 = operand;
    operation = [] (std::int32_t a, std::int32_t b) -> std::int64_t { return a - b;};
    return *this;
}

Calculator& Calculator::Mul(std::int32_t const &operand)
{
    op1 = operand;
    operation = [] (std::int32_t a, std::int32_t b) -> std::int64_t { return a * b;};
    return *this;
}

Calculator& Calculator::Div(std::int32_t const &operand)
{
    op1 = operand;
    operation = [] (std::int32_t a, std::int32_t b) -> std::int64_t {
        std::cout << "Division" << std::endl;
        if (0 == b)
        {
            throw DividedByZeroException();
        }
        else
        {
            return a / b;
        }
    };
    return *this;
}

std::int64_t Calculator::Result() const
{
    return operation(currentValue,op1);
}