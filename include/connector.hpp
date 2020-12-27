#pragma once 

#include <cpr/cpr.h>

#include <string>

class connector {
    public:
    static std::string get_text(const std::string & url);
    static bool send(const std::string & url,const std::string& payload);
};
