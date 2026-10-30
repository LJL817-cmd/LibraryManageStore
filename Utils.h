#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
using namespace std;

class Utils
{
public:
    static void clearScreen();
    static bool isNumber(string str);
    static string getCurrentDate();
};
