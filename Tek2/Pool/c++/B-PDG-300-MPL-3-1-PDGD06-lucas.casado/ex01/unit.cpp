/*
** EPITECH PROJECT, 2022
** C++
** File description:
** eof
*/

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

auto condition_buffer(std::string unit)
{
    const char *buffer;
    const auto cel = "Celsius";
    const auto fahrenheit = "Fahrenheit";
    
    if (unit == "celsius") {
        buffer = fahrenheit;
    }
    if (unit == "fahrenheit") {
        buffer = cel;
    }
    return(buffer);
}

auto condition_value(std::string unit, float value)
{
    float var = (5.0 / 9.0); 
    
    if (unit == "celsius")
        var = value / var + 32;
    if (unit == "fahrenheit")
        var *= (value-32);
    return(var);
}

int main(int argc, char **argv)
{
    std::string str;
    std::string unit;
    std::stringstream stream;
    float value;
    float var = (5.0 / 9.0);
    std::string buffer;

    std::getline(std::cin, str);
    stream << str;
    stream >> value;
    stream >> unit;
    std::transform(unit.begin(), unit.end(), unit.begin(), ::tolower);
    buffer = condition_buffer(unit);
    var = condition_value(unit, value);
    std::cout << std::setw(16) << std::fixed <<
    std::setprecision(3) << var << std::setw(16) << buffer << std::endl;
}