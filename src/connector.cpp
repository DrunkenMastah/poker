#include <connector.hpp>
#include <cpr/api.h>
#include <cpr/payload.h>
#include <cpr/response.h>

#include <iostream>

std::string connector::get_text(const std::string & url){

    cpr::Response r = cpr::Get(cpr::Url{url},
                        cpr::Authentication{"user", "pass"},
                        cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    if(r.status_code>400 || r.error.code!=cpr::ErrorCode::OK)
        return "";
    return r.text;                         // JSON text string
}
bool connector::send(const std::string &url,const std::string & payload){
    
    cpr::Response r = cpr::Post(cpr::Url{url},
        cpr::Body{payload},
        cpr::Header{{"Content-Type", "text/plain"}});
    std::cout<<r.text;
    return true;
}
