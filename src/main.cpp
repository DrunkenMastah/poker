
#include <QDebug>
#include <qobject.h>
#include <QtQuick>

#include <cards_helper.hpp>
#include <common/game_state.hpp>
#include <connector.hpp>

#include <thread>
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
    unsigned player_id=1;
    
    //h.set(cards_helper::positions::flop1, a.value());
    //h.set(cards_helper::positions::flop2, poker_deck.spit().value());
    //h.set(cards_helper::positions::flop3, poker_deck.spit().value());
    //h.set(cards_helper::positions::turn, poker_deck.spit().value());
    //h.set(cards_helper::positions::river, poker_deck.spit().value());
    //h.set(cards_helper::positions::p1_1, poker_deck.spit().value());
    //h.set(cards_helper::positions::p1_2, *(poker_deck.spit()));
    connector req;
    int y=5;
    int x(y);
    server::round_state prev_state{};
    server::round_state current_state{prev_state};
    std::thread a([&](){
        while(true){
            std::stringstream s(req.get_text("http://localhost:9081/common_data"));
            s>>current_state;
            if(current_state!=prev_state)
            {
                //do things
            }
            prev_state=current_state;
        }
        }
    );
    a.detach();
    return app.exec();

}