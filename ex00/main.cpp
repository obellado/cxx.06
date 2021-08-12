#include <iostream>
#include <string>
#include <exception>
#include "Scalar.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return -1;
    Scalar sca(argv[1]);

    std::cout << "char: ";
    try
    {
        char a = sca.toChar();
        std::cout << "\'" << a << "\'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "int: ";
    try
    {
        int b = sca.toInt();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "float: ";
    try
    {
        float c = sca.toFloat();
        if (c - (int)c == (float)0 && sca.getCount() < 7)
            std::cout << c << ".0f" << std::endl;
        else
            std::cout << c << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "double: ";
    try
    {
        double d = sca.toDouble();
        if (d - (int)d == (double)0 && sca.getCount() < 7)  
            std::cout << d << ".0" << std::endl;
        else
            std::cout << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}