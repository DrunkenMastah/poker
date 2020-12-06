#pragma once 

#include <cpr/cpr.h>
#include <iostream>
class requester {
    public:
    static std::string get_text(const std::string & url){

    cpr::Response r = cpr::Get(cpr::Url{url},
                      cpr::Authentication{"user", "pass"},
                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    return r.text;                         // JSON text string
    }
};
