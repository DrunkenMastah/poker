#pragma once

#include <qobject.h>
#include <string>
#include <common/enums.hpp>

class cards_helper{
    public:
    
    cards_helper(QObject& obj);
    void set(enums::positions pos,enums::cards card);
    private:

    std::string card_to_path(enums::cards c) ;
    QObject & obj_;

};