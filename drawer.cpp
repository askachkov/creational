#include "drawer.h"
#include <iostream>

void ConsoleDrawer::draw(const std::string & s)
{
    std::cout << s;
}

void ConsoleDrawer::draw(char ch)
{
    std::cout << ch;
}

void ConsoleDrawer::draw(double n)
{
    std::cout << n;
}
