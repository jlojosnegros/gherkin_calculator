
#ifndef GHERKIN_CALCULATOR_DIVIDEDBYZEROEXCEPTION_HPP
#define GHERKIN_CALCULATOR_DIVIDEDBYZEROEXCEPTION_HPP

#include <stdexcept>

class DividedByZeroException : public std::runtime_error
{
public:
    DividedByZeroException(void)
            : std::runtime_error("unable to divide by zero")
    {

    }

    ~DividedByZeroException() override = default;

    const char *what() const noexcept override {
        return runtime_error::what();
    }

};

#endif //GHERKIN_CALCULATOR_DIVIDEDBYZEROEXCEPTION_HPP
