
import QtQuick 2.0
import "Resources"
import "Card"

Rectangle {
    id: window

    width: 780; height: 420
    color: "darkgreen"
        Column{
            anchors.centerIn: parent; spacing: 10

        Row {
            spacing: 10
            Card { source: "Resources/13h.png"; angle: 180; xAxis: 1;objectName:"card1"}
            Card { source: "Resources/01h.png"; angle: 180; xAxis: 1;objectName:"card2"}
            Card { source: "Resources/01d.png"; angle: 180; xAxis: 1;objectName:"card3"}
            Card { source: "Resources/01s.png"; angle: 180; xAxis: 1;objectName:"card4"}
            Card { source: "Resources/01c.png"; angle: 180; xAxis: 1;objectName:"card5"}
        }
        Row {
            spacing:-100
            Card { source: "Resources/13c.png"; angle: 180; xAxis: 1;objectName:"p1_1"}
            Card { source: "Resources/13s.png"; angle: 180; xAxis: 1;objectName:"p1_2"}
           
        }
    }
}

