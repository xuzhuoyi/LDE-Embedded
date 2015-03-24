import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

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
            x: 30
            y: 375
            width: 64
            height: 64
            source: "images/Apps-accessories-calculator-icon.png"
        }
    }
}
