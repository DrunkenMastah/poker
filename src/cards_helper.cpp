#include <cards_helper.hpp>

#include <qobject.h>
#include <QString>
#include <QtQuick>
#include <QUrl>


cards_helper::cards_helper(QObject& obj):obj_(obj){}
void cards_helper::set(positions pos, cards card){
    QString path=QString::fromStdString(card_to_path(card));
    QUrl url(path);
    QObject * card_obj;
    switch (pos) {
        case positions::flop1:
        card_obj = obj_.findChild<QObject*>("card1");
        break;
        case positions::flop2:
        card_obj = obj_.findChild<QObject*>("card2");
        break;
        case positions::flop3:
        card_obj = obj_.findChild<QObject*>("card3");
        break;
        case positions::turn:
        card_obj = obj_.findChild<QObject*>("card4");
        break;
        case positions::river:
        card_obj = obj_.findChild<QObject*>("card5");
        break;
        case positions::p1_1:
        card_obj = obj_.findChild<QObject*>("p1_1");
        break;
        case positions::p1_2:
        card_obj = obj_.findChild<QObject*>("p1_2");
        break;
    }
    card_obj->setProperty("source",url);
}
std::string cards_helper::card_to_path(cards c){
        switch(c){
            case cards::h1:
                return "qrc:///Resources/01h.png";
            case cards::h2:
                return "qrc:///Resources/2h.png";
            case cards::h3:
                return "qrc:///Resources/3h.png";
            case cards::h4:
                return "qrc:///Resources/3h.png";
            case cards::h5:
                return "qrc:///Resources/5h.png";
            case cards::h6:
                return "qrc:///Resources/6h.png";
            case cards::h7:
                return "qrc:///Resources/7h.png";
            case cards::h8:
                return "qrc:///Resources/8h.png";
            case cards::h9:
                return "qrc:///Resources/9h.png";
            case cards::h10:
                return "qrc:///Resources/10h.png";
            case cards::h11:
                return "qrc:///Resources/11h.png";
            case cards::h12:
                return "qrc:///Resources/12h.png";
            case cards::h13:
                return "qrc:///Resources/13h.png";
            case cards::c1:
                return "qrc:///Resources/01c.png";
            case cards::c2:
                return "qrc:///Resources/2c.png";
            case cards::c3:
                return "qrc:///Resources/3c.png";
            case cards::c4:
                return "qrc:///Resources/3c.png";
            case cards::c5:
                return "qrc:///Resources/5c.png";
            case cards::c6:
                return "qrc:///Resources/6c.png";
            case cards::c7:
                return "qrc:///Resources/7c.png";
            case cards::c8:
                return "qrc:///Resources/8c.png";
            case cards::c9:
                return "qrc:///Resources/9c.png";
            case cards::c10:
                return "qrc:///Resources/10c.png";
            case cards::c11:
                return "qrc:///Resources/11c.png";
            case cards::c12:
                return "qrc:///Resources/12c.png";
            case cards::c13:
                return "qrc:///Resources/13c.png";
            case cards::d1:
                return "qrc:///Resources/01d.png";
            case cards::d2:
                return "qrc:///Resources/2d.png";
            case cards::d3:
                return "qrc:///Resources/3d.png";
            case cards::d4:
                return "qrc:///Resources/3d.png";
            case cards::d5:
                return "qrc:///Resources/5d.png";
            case cards::d6:
                return "qrc:///Resources/6d.png";
            case cards::d7:
                return "qrc:///Resources/7d.png";
            case cards::d8:
                return "qrc:///Resources/8d.png";
            case cards::d9:
                return "qrc:///Resources/9d.png";
            case cards::d10:
                return "qrc:///Resources/10d.png";
            case cards::d11:
                return "qrc:///Resources/11d.png";
            case cards::d12:
                return "qrc:///Resources/12d.png";
            case cards::d13:
                return "qrc:///Resources/13d.png";
            case cards::s1:
                return "qrc:///Resources/01s.png";
            case cards::s2:
                return "qrc:///Resources/2s.png";
            case cards::s3:
                return "qrc:///Resources/3s.png";
            case cards::s4:
                return "qrc:///Resources/3s.png";
            case cards::s5:
                return "qrc:///Resources/5s.png";
            case cards::s6:
                return "qrc:///Resources/6s.png";
            case cards::s7:
                return "qrc:///Resources/7s.png";
            case cards::s8:
                return "qrc:///Resources/8s.png";
            case cards::s9:
                return "qrc:///Resources/9s.png";
            case cards::s10:
                return "qrc:///Resources/10s.png";
            case cards::s11:
                return "qrc:///Resources/11s.png";
            case cards::s12:
                return "qrc:///Resources/12s.png";
            case cards::s13:
                return "qrc:///Resources/13s.png";
            default:
                return "qrc:///Resources/back.png";
        }
}