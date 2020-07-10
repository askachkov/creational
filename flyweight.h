#pragma once

#include "factory.h"
#include <map>

class CashNodeFactory: public Factory
{
public:
    std::shared_ptr<StringNode> createString(const std::string & s) override;

private:
    std::map<std::string, std::shared_ptr<StringNode> > m_Cash;
};

