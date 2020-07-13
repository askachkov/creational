#pragma once

#include "node.h"
#include "factory.h"

class IBuilder
{
public:
    virtual ~IBuilder(){}
    virtual NodePtr build(INodeFactory & f) = 0;
};

class Director
{
public:
    Director();
    NodePtr buidObject(INodeFactory & f);

private:
    typedef std::unique_ptr<IBuilder> Ptr;
    std::vector<Ptr> m_Builders;
};

