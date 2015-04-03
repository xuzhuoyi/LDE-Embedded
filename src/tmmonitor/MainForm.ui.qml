import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {

    property alias t5:text5
    property alias t8: text8

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
            horizontalAlignment: Text.AlignHCenter
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

        Text {
            id: text4
            x: 24
            y: 125
            color: "#ffffff"
            text: qsTr("DHT-11 传感器数据")
            font.pixelSize: 14
        }

        Text {
            id: text5
            x: 45
            y: 161
            width: 60
            height: 56
            color: "#20be17"
            text: qsTr("19")
            horizontalAlignment: Text.AlignRight
            font.bold: true
            font.pixelSize: 42
        }

        Text {
            id: text6
            x: 115
            y: 161
            color: "#ffffff"
            text: qsTr("温度")
            font.bold: true
            font.pixelSize: 24
        }

        Text {
            id: text7
            x: 115
            y: 200
            color: "#ffffff"
            text: qsTr("摄氏度")
            font.pixelSize: 12
        }

        Text {
            id: text8
            x: 179
            y: 161
            width: 60
            height: 56
            color: "#20be17"
            text: qsTr("45")
            horizontalAlignment: Text.AlignRight
            font.bold: true
            font.pixelSize: 42
        }

        Text {
            id: text9
            x: 249
            y: 161
            color: "#ffffff"
            text: qsTr("湿度")
            font.bold: true
            font.pixelSize: 24
        }

        Text {
            id: text10
            x: 249
            y: 200
            color: "#ffffff"
            text: qsTr("%")
            font.pixelSize: 12
        }

        Text {
            id: text11
            x: 24
            y: 232
            width: 132
            height: 17
            color: "#ffffff"
            text: qsTr("DS18B20 传感器数据")
            font.pixelSize: 14
        }
    }
}
