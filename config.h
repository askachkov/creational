#pragma once

#include <map>
#include <string>

class Config
{
    Config();
    Config(const Config&) = delete;
    void operator=(const Config&) = delete;
public:
    typedef std::string String;
    typedef std::map<String, String> Library;

    static Config & instance();
    void set(const String & key, const String & value);
    String get(const String & key)const;

private:
    Library m_Library;
};