# -*- coding: utf-8 -*-
__author__ = 'Zhuoyi Xu'

import sys
from PyQt4 import QtGui
from ui_MainForm import Ui_Form


class MainForm(QtGui.QWidget):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_Form()
        self.ui.setupUi(self)

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    mainForm = MainForm()
    mainForm.show()
    sys.exit(app.exec_())
