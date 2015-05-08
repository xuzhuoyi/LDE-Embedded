# -*- coding: utf-8 -*-
__author__ = 'Zhuoyi Xu'

import sys
import os
from PyQt4 import QtCore, QtGui
from ui_MainForm import Ui_Form


class MainForm(QtGui.QWidget):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_Form()
        self.ui.setupUi(self)
        self.connect(self.ui.pushButton, QtCore.SIGNAL("clicked()"), self.open_file)
        self.connect(self.ui.pushButton_2, QtCore.SIGNAL("clicked()"), self.close_file)
        self.connect(self.ui.pushButton_5, QtCore.SIGNAL("clicked()"), self.exit_program)
        self.connect(self.ui.pushButton_4, QtCore.SIGNAL("clicked()"), self.analyse_faces)

    def open_file(self):
        global s
        s = QtGui.QFileDialog.getOpenFileName(self, "Open file dialog", "/", "JPEG files(*.jpg)")
        scene = QtGui.QGraphicsScene()
        pixmap = QtGui.QPixmap(s)
        self.ui.graphicsView.setScene(scene)
        scene.addPixmap(pixmap)

    def close_file(self):
        scene = QtGui.QGraphicsScene()
        self.ui.graphicsView.setScene(scene)

    @staticmethod
    def analyse_faces():
        global s
        print "%s" % s
        os.execl("/usr/bin/python", "python", "FaceDetect.py", s)

    @staticmethod
    def exit_program():
        sys.exit(0)

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    mainForm = MainForm()
    mainForm.show()
    sys.exit(app.exec_())
