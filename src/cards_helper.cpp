#include <cards_helper.hpp>

#include <qobject.h>
#include <QString>
#include <QtQuick>
#include <QUrl>


cards_helper::cards_helper(QObject& obj):obj_(obj){}
void cards_helper::set(enums::positions pos, enums::cards card){
    QString path=QString::fromStdString(card_to_path(card));
    QUrl url(path);
    QObject * card_obj;
    switch (pos) {
        case enums::positions::flop1:
        card_obj = obj_.findChild<QObject*>("card1");
        break;
        case enums::positions::flop2:
        card_obj = obj_.findChild<QObject*>("card2");
        break;
        case enums::positions::flop3:
        card_obj = obj_.findChild<QObject*>("card3");
        break;
        case enums::positions::turn:
        card_obj = obj_.findChild<QObject*>("card4");
        break;
        case enums::positions::river:
        card_obj = obj_.findChild<QObject*>("card5");
        break;
        case enums::positions::p1_1:
        card_obj = obj_.findChild<QObject*>("p1_1");
        break;
        case enums::positions::p1_2:
        card_obj = obj_.findChild<QObject*>("p1_2");
        break;
    }
    card_obj->setProperty("source",url);
}
std::string cards_helper::card_to_path(enums::cards c){
        switch(c){
            case enums::cards::h1:
                return "qrc:///Resources/01h.png";
            case enums::cards::h2:
                return "qrc:///Resources/2h.png";
            case enums::cards::h3:
                return "qrc:///Resources/3h.png";
            case enums::cards::h4:
                return "qrc:///Resources/3h.png";
            case enums::cards::h5:
                return "qrc:///Resources/5h.png";
            case enums::cards::h6:
                return "qrc:///Resources/6h.png";
            case enums::cards::h7:
                return "qrc:///Resources/7h.png";
            case enums::cards::h8:
                return "qrc:///Resources/8h.png";
            case enums::cards::h9:
                return "qrc:///Resources/9h.png";
            case enums::cards::h10:
                return "qrc:///Resources/10h.png";
            case enums::cards::h11:
                return "qrc:///Resources/11h.png";
            case enums::cards::h12:
                return "qrc:///Resources/12h.png";
            case enums::cards::h13:
                return "qrc:///Resources/13h.png";
            case enums::cards::c1:
                return "qrc:///Resources/01c.png";
            case enums::cards::c2:
                return "qrc:///Resources/2c.png";
            case enums::cards::c3:
                return "qrc:///Resources/3c.png";
            case enums::cards::c4:
                return "qrc:///Resources/3c.png";
            case enums::cards::c5:
                return "qrc:///Resources/5c.png";
            case enums::cards::c6:
                return "qrc:///Resources/6c.png";
            case enums::cards::c7:
                return "qrc:///Resources/7c.png";
            case enums::cards::c8:
                return "qrc:///Resources/8c.png";
            case enums::cards::c9:
                return "qrc:///Resources/9c.png";
            case enums::cards::c10:
                return "qrc:///Resources/10c.png";
            case enums::cards::c11:
                return "qrc:///Resources/11c.png";
            case enums::cards::c12:
                return "qrc:///Resources/12c.png";
            case enums::cards::c13:
                return "qrc:///Resources/13c.png";
            case enums::cards::d1:
                return "qrc:///Resources/01d.png";
            case enums::cards::d2:
                return "qrc:///Resources/2d.png";
            case enums::cards::d3:
                return "qrc:///Resources/3d.png";
            case enums::cards::d4:
                return "qrc:///Resources/3d.png";
            case enums::cards::d5:
                return "qrc:///Resources/5d.png";
            case enums::cards::d6:
                return "qrc:///Resources/6d.png";
            case enums::cards::d7:
                return "qrc:///Resources/7d.png";
            case enums::cards::d8:
                return "qrc:///Resources/8d.png";
            case enums::cards::d9:
                return "qrc:///Resources/9d.png";
            case enums::cards::d10:
                return "qrc:///Resources/10d.png";
            case enums::cards::d11:
                return "qrc:///Resources/11d.png";
            case enums::cards::d12:
                return "qrc:///Resources/12d.png";
            case enums::cards::d13:
                return "qrc:///Resources/13d.png";
            case enums::cards::s1:
                return "qrc:///Resources/01s.png";
            case enums::cards::s2:
                return "qrc:///Resources/2s.png";
            case enums::cards::s3:
                return "qrc:///Resources/3s.png";
            case enums::cards::s4:
                return "qrc:///Resources/3s.png";
            case enums::cards::s5:
                return "qrc:///Resources/5s.png";
            case enums::cards::s6:
                return "qrc:///Resources/6s.png";
            case enums::cards::s7:
                return "qrc:///Resources/7s.png";
            case enums::cards::s8:
                return "qrc:///Resources/8s.png";
            case enums::cards::s9:
                return "qrc:///Resources/9s.png";
            case enums::cards::s10:
                return "qrc:///Resources/10s.png";
            case enums::cards::s11:
                return "qrc:///Resources/11s.png";
            case enums::cards::s12:
                return "qrc:///Resources/12s.png";
            case enums::cards::s13:
                return "qrc:///Resources/13s.png";
            default:
                return "qrc:///Resources/back.png";
        }
}