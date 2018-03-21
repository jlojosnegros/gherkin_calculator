#ifndef GHERKIN_CALCULATOR_CALCULATOR_HPP
#define GHERKIN_CALCULATOR_CALCULATOR_HPP

#include <cstdint>
#include <functional>

class Calculator final
{
public:
    explicit Calculator(std::int32_t const& initialValue = 0);
    ~Calculator(void) = default;

    Calculator(Calculator const& rhs) = default;
    Calculator& operator=(Calculator const& rhs) = default;

    Calculator(Calculator&& rhs) noexcept = default;
    Calculator& operator=(Calculator&& rhs) noexcept = default;


    Calculator& Add(std::int32_t const& operand);
    Calculator& Sub(std::int32_t const& operand);
    Calculator& Mul(std::int32_t const& operand);
    Calculator& Div(std::int32_t const& operand);

    std::int64_t Result(void) const;
protected:
private:
    std::int64_t currentValue;
    std::int32_t op1;
    std::function<std::int64_t (std::int32_t, std::int32_t)> operation;
};

#endif //GHERKIN_CALCULATOR_CALCULATOR_HPP
