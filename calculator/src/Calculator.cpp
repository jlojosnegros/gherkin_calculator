
#include "Calculator.hpp"
#include "DividedByZeroException.hpp"

Calculator::Calculator(std::int32_t const& initialValue)
        : currentValue(initialValue)
{

}

Calculator& Calculator::Add(std::int32_t const& operand)
{
    currentValue += operand;
    return *this;
}

Calculator& Calculator::Sub(std::int32_t const &operand)
{
    currentValue -= operand;
    return *this;
}

Calculator& Calculator::Mul(std::int32_t const &operand)
{
    currentValue *= operand;
    return *this;
}

Calculator& Calculator::Div(std::int32_t const &operand)
{
    if ( 0 == operand)
    {
        throw DividedByZeroException();
    }
    currentValue /= operand;
    return *this;
}

std::int64_t Calculator::Result() const
{
    return currentValue;
}