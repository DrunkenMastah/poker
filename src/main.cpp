
#include <QDebug>
#include <qobject.h>
#include <QtQuick>

#include <cards_helper.hpp>
#include <requester.hpp>

int main(int argc ,char *argv[])
{
    QGuiApplication app(argc,argv);
    app.setApplicationName(QFileInfo(app.applicationFilePath()).baseName());
    QQuickView view;
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
    new QQmlFileSelector(view.engine(), &view);
    view.setSource(QUrl("flipable.qml")); 
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();
    QObject *object = view.rootObject();
    cards_helper h(*object);
    
    
    //h.set(cards_helper::positions::flop1, a.value());
    //h.set(cards_helper::positions::flop2, poker_deck.spit().value());
    //h.set(cards_helper::positions::flop3, poker_deck.spit().value());
    //h.set(cards_helper::positions::turn, poker_deck.spit().value());
    //h.set(cards_helper::positions::river, poker_deck.spit().value());
    //h.set(cards_helper::positions::p1_1, poker_deck.spit().value());
    //h.set(cards_helper::positions::p1_2, *(poker_deck.spit()));
    requester req;
    //qDebug()<<QString::fromStdString(req.get_text("http://localhost:9081/A"));
    return app.exec();

}