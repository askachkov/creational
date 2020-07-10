#include "flyweight.h"
#include "config.h"
#include <iostream>

std::shared_ptr<StringNode> CashNodeFactory::createString(const std::string & s)
{
    auto it = m_Cash.find(s);
    if ( it != m_Cash.end() ){
        return it->second;
    }
    //std::cout << "LOG [" << Config::instance().get("APP_NAME") << "]: added str: " << s << std::endl;
    auto res = Factory::createString(s);
    m_Cash[s] = res;
    return res;
}