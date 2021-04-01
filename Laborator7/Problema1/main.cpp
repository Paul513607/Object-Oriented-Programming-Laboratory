#include <iostream>
#include <iomanip>

float operator"" _Kelvin(const char* value)
{
    double val=atof(value);
    return val-273.15;
}

float operator"" _Fahrenheit(const char* value)
{
    double val=atof(value);
    return (val-32)/1.8;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << std::fixed << std::setprecision(2) << a << " " << b;
    return 0;
    return 0;
}
