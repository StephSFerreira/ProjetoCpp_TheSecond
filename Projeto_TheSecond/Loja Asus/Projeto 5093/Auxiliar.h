#pragma once
#include <iostream>
#include <limits> // necess�rio para numeric_limits
#include<string>
#include <cctype> // Para isalpha()


class Auxiliar
{



public:
    static int getValidNumber();

    static bool getValidString( std::string& input);

};