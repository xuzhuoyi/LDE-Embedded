import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

import "."
import "QChart.js"        as Charts
import "QChartGallery.js" as ChartsData

Item {

    property alias t5:text5
    property alias t8: text8

    property int chart_width: 200;
    property int chart_height: 200;
    property int chart_spacing: 20;
    property int text_height: 80;
    property int row_height: 8;

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
            width: 48
            height: 48
            source: "images/Apps-akonadi-icon.png"
        }

        Text {
            id: text1
            x: 14
            y: 70
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
            x: 95
            y: 24
            width: 164
            height: 40
            color: "#ffffff"
            text: qsTr("传感器中心")
            font.pixelSize: 32
        }

        Text {
            id: text3
            x: 95
            y: 73
            width: 31
            height: 15
            color: "#ffffff"
            text: qsTr("Beta")
            font.pixelSize: 14
        }

        Text {
            id: text4
            x: 24
            y: 106
            color: "#ffffff"
            text: qsTr("DHT-11 传感器数据")
            font.pixelSize: 14
        }

        Text {
            id: text5
            x: 32
            y: 138
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
            x: 109
            y: 138
            color: "#ffffff"
            text: qsTr("温度")
            font.bold: true
            font.pixelSize: 24
        }

        Text {
            id: text7
            x: 108
            y: 177
            color: "#ffffff"
            text: qsTr("摄氏度")
            font.pixelSize: 12
        }

        Text {
            id: text8
            x: 173
            y: 138
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
            y: 138
            color: "#ffffff"
            text: qsTr("湿度")
            font.bold: true
            font.pixelSize: 24
        }

        Text {
            id: text10
            x: 249
            y: 177
            color: "#ffffff"
            text: qsTr("%")
            font.pixelSize: 12
        }

            Rectangle {
                id: rectangle2
                x: 320
                y: 125
                width: 304
                height: 200
                color: "#000000"

                Chart {
                      id: chart_line;
                      width: 300;
                      height: 300;
                      chartAnimated: true;
                      chartAnimationEasing: Easing.InOutElastic;
                      chartAnimationDuration: 2000;
                      chartData: ChartsData.ChartLineData;
                      chartType: Charts.ChartType.LINE;
                }
            }

            Rectangle {
                id: rectangle3
                x: 22
                y: 223
                width: 275
                height: 217
                color: "#000000"

                Chart {
                      id: chart_bar;
                      width: 300;
                      height: 200;
                      chartAnimated: true;
                      chartAnimationEasing: Easing.OutBounce;
                      chartAnimationDuration: 2000;
                      chartData: ChartsData.ChartBarData;
                      chartType: Charts.ChartType.BAR;
                    }
            }
    }
}
