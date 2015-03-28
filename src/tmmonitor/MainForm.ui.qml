import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 640
        height: 480
        color: "#000000"

        Image {
            id: image1
            x: 24
            y: 24
            width: 64
            height: 64
            source: "images/Apps-akonadi-icon.png"
        }

        Text {
            id: text1
            x: 22
            y: 94
            width: 68
            height: 18
            color: "#ffffff"
            text: qsTr("LDE-Emb")
            textFormat: Text.AutoText
            font.pixelSize: 15
        }

        Text {
            id: text2
            x: 111
            y: 24
            width: 164
            height: 40
            color: "#ffffff"
            text: qsTr("传感器中心")
            font.pixelSize: 32
        }

        Text {
            id: text3
            x: 111
            y: 70
            width: 31
            height: 15
            color: "#ffffff"
            text: qsTr("Beta")
            font.pixelSize: 14
        }
    }
}
