# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainForm.ui'
#
# Created: Fri May  8 21:42:49 2015
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName(_fromUtf8("Form"))
        Form.resize(480, 320)
        self.graphicsView = QtGui.QGraphicsView(Form)
        self.graphicsView.setGeometry(QtCore.QRect(140, 10, 321, 251))
        self.graphicsView.setObjectName(_fromUtf8("graphicsView"))
        self.toolBox = QtGui.QToolBox(Form)
        self.toolBox.setGeometry(QtCore.QRect(10, 10, 121, 301))
        self.toolBox.setObjectName(_fromUtf8("toolBox"))
        self.page = QtGui.QWidget()
        self.page.setGeometry(QtCore.QRect(0, 0, 121, 233))
        self.page.setObjectName(_fromUtf8("page"))
        self.pushButton = QtGui.QPushButton(self.page)
        self.pushButton.setGeometry(QtCore.QRect(0, 10, 111, 30))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/data/images/Actions-document-open-icon.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton.setIcon(icon)
        self.pushButton.setIconSize(QtCore.QSize(32, 32))
        self.pushButton.setObjectName(_fromUtf8("pushButton"))
        self.pushButton_2 = QtGui.QPushButton(self.page)
        self.pushButton_2.setGeometry(QtCore.QRect(0, 50, 111, 30))
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(_fromUtf8(":/data/images/Actions-dialog-close-icon.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_2.setIcon(icon1)
        self.pushButton_2.setIconSize(QtCore.QSize(32, 32))
        self.pushButton_2.setObjectName(_fromUtf8("pushButton_2"))
        self.pushButton_3 = QtGui.QPushButton(self.page)
        self.pushButton_3.setGeometry(QtCore.QRect(0, 90, 111, 30))
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap(_fromUtf8(":/data/images/Apps-digikam-icon.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_3.setIcon(icon2)
        self.pushButton_3.setIconSize(QtCore.QSize(32, 32))
        self.pushButton_3.setObjectName(_fromUtf8("pushButton_3"))
        self.toolBox.addItem(self.page, _fromUtf8(""))
        self.page_2 = QtGui.QWidget()
        self.page_2.setGeometry(QtCore.QRect(0, 0, 121, 233))
        self.page_2.setObjectName(_fromUtf8("page_2"))
        self.pushButton_4 = QtGui.QPushButton(self.page_2)
        self.pushButton_4.setGeometry(QtCore.QRect(0, 10, 111, 30))
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap(_fromUtf8(":/data/images/Actions-document-preview-archive-icon.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_4.setIcon(icon3)
        self.pushButton_4.setIconSize(QtCore.QSize(32, 32))
        self.pushButton_4.setObjectName(_fromUtf8("pushButton_4"))
        self.pushButton_6 = QtGui.QPushButton(self.page_2)
        self.pushButton_6.setGeometry(QtCore.QRect(0, 50, 111, 30))
        icon4 = QtGui.QIcon()
        icon4.addPixmap(QtGui.QPixmap(_fromUtf8(":/data/images/Categories-preferences-system-icon.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_6.setIcon(icon4)
        self.pushButton_6.setIconSize(QtCore.QSize(32, 32))
        self.pushButton_6.setObjectName(_fromUtf8("pushButton_6"))
        self.pushButton_5 = QtGui.QPushButton(self.page_2)
        self.pushButton_5.setGeometry(QtCore.QRect(0, 90, 111, 30))
        icon5 = QtGui.QIcon()
        icon5.addPixmap(QtGui.QPixmap(_fromUtf8(":/data/images/Actions-application-exit-icon.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_5.setIcon(icon5)
        self.pushButton_5.setIconSize(QtCore.QSize(32, 32))
        self.pushButton_5.setObjectName(_fromUtf8("pushButton_5"))
        self.toolBox.addItem(self.page_2, _fromUtf8(""))
        self.label = QtGui.QLabel(Form)
        self.label.setGeometry(QtCore.QRect(200, 280, 201, 21))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName(_fromUtf8("label"))

        self.retranslateUi(Form)
        self.toolBox.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        Form.setWindowTitle(_translate("Form", "Form", None))
        self.pushButton.setText(_translate("Form", "打开", None))
        self.pushButton_2.setText(_translate("Form", "关闭", None))
        self.pushButton_3.setText(_translate("Form", "从摄像头", None))
        self.toolBox.setItemText(self.toolBox.indexOf(self.page), _translate("Form", "文件", None))
        self.pushButton_4.setText(_translate("Form", "分析人脸", None))
        self.pushButton_6.setText(_translate("Form", "首选项", None))
        self.pushButton_5.setText(_translate("Form", "退出", None))
        self.toolBox.setItemText(self.toolBox.indexOf(self.page_2), _translate("Form", "处理", None))
        self.label.setText(_translate("Form", "LDE 人脸识别模块 V0.1", None))

import fd_rc
