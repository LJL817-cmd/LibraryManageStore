#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Utils::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool Utils::isNumber(string str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

string Utils::getCurrentDate()
{
    time_t t = time(nullptr);
    tm* tm = localtime(&t);
    char buf[20];
    sprintf(buf, "%04d-%02d-%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
    return string(buf);
}