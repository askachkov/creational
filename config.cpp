#include "config.h"

Config::Config()
{
}

Config & Config::instance()
{
    static Config inst;
    return inst;
}

void Config::set(const String & key, const String & value)
{
    m_Library[key] = value;
}

Config::String Config::get(const String & key)const
{
    auto it = m_Library.find(key);
    if ( it != m_Library.end() ){
        return it->second;
    }
    return "";
}