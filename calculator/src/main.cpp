#include "Calculator.hpp"
#include "DividedByZeroException.hpp"

#include <iostream>

auto main(void) -> int
{
    std::cout << "Hola Mundo" << std::endl;

    Calculator calculator{0};

    std::cout << "result:" << calculator.Add(10).Sub(5).Mul(2).Div(10).Result() << std::endl;

    try
    {
        calculator.Div(0).Result();
    }
    catch (DividedByZeroException& exception)
    {
        std::cerr << "Exception: " << exception.what() << std::endl;
    }


    return 0;
}

