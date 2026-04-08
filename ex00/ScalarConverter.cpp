#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}
ScalarConverter::~ScalarConverter(){}

int    checkPseudoLiterals(std::string entry)
{
    std::string pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    int i;
    for (i = 0 ; i < 6 ;  i++)
    {
        if (entry == pseudo[i])
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (i < 3)
            {
                std::cout << "float: " << entry << std::endl;
                std::cout << "double: " << entry.substr(0, entry.length() - 1) << std::endl;
            }
            else if (i >= 3)
            {
                std::cout << "float: " << entry + "f" << std::endl;
                std::cout << "double: " << entry << std::endl;
            }
            return 1;
        }
    }
    return 0;
}

int checkChar(std::string entry)
{
    if (entry.length() == 1 && !isdigit(entry[0]))
    {
        std::cout << "char: " << '\''  << entry[0] << '\'' << std::endl;
        std::cout << "int: " << static_cast<int>(entry[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(entry[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(entry[0]) << ".0" << std::endl;
        return 1;
    }
    return 0;
}
int isprintable(char c)
{
    return (c >= 32 &&  c < 127);
}

int checkInt(std::string entry)
{
    for (size_t i = 0; i < entry.length(); i++) {
        if (i == 0 && (entry[i] == '-' || entry[i] == '+')) continue;
        if (!isdigit(entry[i])) return 0;
    }

    double double_val;
    std::stringstream ss(entry);
    ss >> double_val;
    
    if (!ss.fail() && ss.eof())
    {
        if (double_val > std::numeric_limits<int>::max() || double_val < std::numeric_limits<int>::min())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            
            std::cout << "float: " << static_cast<float>(double_val) << "f" << std::endl; 
            std::cout << "double: " << double_val << std::endl;
            return 1;
        }

        int int_val = static_cast<int>(double_val);
        if (int_val >= 0 && int_val <= 127 && isprintable(static_cast<char>(int_val)))
            std::cout << "char: '" << static_cast<char>(int_val) << "'" << std::endl;
        else if (int_val >= 0 && int_val <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
            
        std::cout << "int: " << int_val << std::endl;
        
        std::cout << "float: " << static_cast<float>(int_val);
        if (int_val > -1000000 && int_val < 1000000) std::cout << ".0";
        std::cout << "f" << std::endl; 
        
        std::cout << "double: " << static_cast<double>(int_val);
        if (int_val > -1000000 && int_val < 1000000) std::cout << ".0";
        std::cout << std::endl;
        
        return 1;
    }
    return 0;
}

int checkFloat(std::string entry)
{
    if ((entry.find('.') != std::string::npos) && 
        (entry[entry.length() - 1] == 'F' || entry[entry.length() - 1] == 'f'))
    {
        float float_val;
        std::stringstream ss(entry.substr(0, entry.length() - 1));
        ss >> float_val;
        if (!ss.fail() && ss.eof())
        {
            if (float_val >= 0 && float_val <= 127 && isprintable(static_cast<char>(float_val)))
                std::cout << "char: '" << static_cast<char>(float_val) << "'" << std::endl;
            else if (float_val >= 0 && float_val <= 127)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: impossible" << std::endl;

            if (float_val > static_cast<float>(std::numeric_limits<int>::max()) || float_val < static_cast<float>(std::numeric_limits<int>::min()))
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(float_val) << std::endl;

            std::cout << "float: " << float_val;
            if (float_val > -1000000 && float_val < 1000000 && float_val == static_cast<int>(float_val)) 
                std::cout << ".0";
            std::cout << "f" << std::endl;

            std::cout << "double: " << set<< static_cast<double>(float_val);
            if (float_val > -1000000 && float_val < 1000000 && float_val == static_cast<int>(float_val)) 
                std::cout << ".0";
            std::cout << std::endl;
            
            return 1;
        }
    }
    return 0;
}

int checkDouble(std::string entry)
{
    if (entry.find('.') != std::string::npos)
    {
        double db_value;
        std::stringstream ss(entry);
        ss >> db_value;
        if (!ss.fail() && ss.eof())
        {
            if (db_value >= 0 && db_value <= 127 && isprintable(static_cast<char>(db_value)))
                std::cout << "char: '" << static_cast<char>(db_value) << "'" << std::endl;
            else if (db_value >= 0 && db_value <= 127)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: impossible" << std::endl;

            if (db_value > std::numeric_limits<int>::max() || db_value < std::numeric_limits<int>::min())
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(db_value) << std::endl;

            std::cout << "float: " << static_cast<float>(db_value);
            if (db_value > -1000000 && db_value < 1000000 && db_value == static_cast<int>(db_value)) 
                std::cout << ".0";
            std::cout << "f" << std::endl;
            
            std::cout << "double: " << db_value;
            if (db_value > -1000000 && db_value < 1000000 && db_value == static_cast<int>(db_value)) 
                std::cout << ".0";
            std::cout << std::endl;
            
            return 1;
        }
    }
    return 0;
}


void    ScalarConverter::convert(std::string entry)
{

    if (checkPseudoLiterals(entry))
        return;
    else if (checkChar(entry))
        return;
    else if (checkInt(entry))
        return;
    else if (checkFloat(entry))
        return;
    else if (checkDouble(entry))
        return;
    else
        std::cout << "Invalid input" << std::endl;


}