import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias mfText1:text1

    Rectangle {
        id: rectangle1
        x: 0
        y: 8
        width: 640
        height: 464
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 1
                color: "#6fcefe"
            }
        }

        Image {
            id: image1
            x: 41
            y: 358
            width: 64
            height: 64
            source: "images/Apps-accessories-calculator-icon.png"
        }

        Image {
            id: image2
            x: 119
            y: 358
            width: 64
            height: 64
            source: "images/Apps-esd-icon.png"
        }

        Image {
            id: image3
            x: 196
            y: 358
            width: 64
            height: 64
            source: "images/Apps-system-file-manager-icon.png"
        }

        Image {
            id: image4
            x: 275
            y: 358
            width: 64
            height: 64
            source: "images/Actions-go-bottom-icon.png"
        }

        Image {
            id: image5
            x: 356
            y: 358
            width: 64
            height: 64
            source: "images/Apps-preferences-web-browser-shortcuts-icon.png"
        }

        Image {
            id: image6
            x: 438
            y: 358
            width: 64
            height: 64
            source: "images/Apps-scribus-icon.png"
        }

        Image {
            id: image7
            x: 521
            y: 358
            width: 64
            height: 64
            source: "images/Apps-yakuake-icon.png"
        }

        Text {
            id: text1
            x: 521
            y: 24
            width: 76
            height: 30
            text: qsTr("Text")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }
    }
}
