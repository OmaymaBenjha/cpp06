#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter
{
    public:
        static void convert(std::string entry);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
};

#endif