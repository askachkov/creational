#pragma once

#include <string>

class IDrawer
{
public:
    virtual ~IDrawer(){}
    virtual void draw(const std::string & s) = 0;
    virtual void draw(char ch) = 0;
    virtual void draw(double n) = 0;
};

class ConsoleDrawer:
    public IDrawer
{
public:
    void draw(const std::string & s) override;
    void draw(char ch) override;
    void draw(double n) override;
};