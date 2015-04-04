import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import LDE.Tmmonitor.TmCore 0.1

import "QChartGallery.js" as ChartsData

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        id:mainForm
        height: 480
        anchors.bottomMargin: 0
        anchors.fill: parent
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    TmCore {
        id: tmMain

        }

    Timer {
        interval: 1;
        running: true;
        repeat: false;
        onTriggered: {
            tmMain.setTemp();
            tmMain.setHumi();
            mainForm.t5.text = tmMain.temp;
            mainForm.t8.text = tmMain.humi;
        }
    }
}
