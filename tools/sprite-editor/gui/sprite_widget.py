# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'sprite_widget.ui'
#
# Created: Fri Jul 25 22:16:21 2014
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

class Ui_SpriteWidget(object):
    def setupUi(self, SpriteWidget):
        SpriteWidget.setObjectName(_fromUtf8("SpriteWidget"))
        SpriteWidget.resize(517, 418)
        self.btn_add_frame = QtGui.QPushButton(SpriteWidget)
        self.btn_add_frame.setGeometry(QtCore.QRect(30, 60, 111, 23))
        self.btn_add_frame.setObjectName(_fromUtf8("btn_add_frame"))
        self.sa_frames = QtGui.QScrollArea(SpriteWidget)
        self.sa_frames.setGeometry(QtCore.QRect(20, 100, 371, 251))
        self.sa_frames.setWidgetResizable(True)
        self.sa_frames.setObjectName(_fromUtf8("sa_frames"))
        self.scrollAreaWidgetContents = QtGui.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 369, 249))
        self.scrollAreaWidgetContents.setObjectName(_fromUtf8("scrollAreaWidgetContents"))
        self.verticalLayoutWidget = QtGui.QWidget(self.scrollAreaWidgetContents)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(-1, -1, 371, 251))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.layout_frames = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.layout_frames.setMargin(0)
        self.layout_frames.setObjectName(_fromUtf8("layout_frames"))
        self.sa_frames.setWidget(self.scrollAreaWidgetContents)
        self.lbl_name = QtGui.QLabel(SpriteWidget)
        self.lbl_name.setGeometry(QtCore.QRect(10, 20, 46, 20))
        self.lbl_name.setObjectName(_fromUtf8("lbl_name"))
        self.le_name = QtGui.QLineEdit(SpriteWidget)
        self.le_name.setGeometry(QtCore.QRect(60, 20, 113, 20))
        self.le_name.setObjectName(_fromUtf8("le_name"))

        self.retranslateUi(SpriteWidget)
        QtCore.QMetaObject.connectSlotsByName(SpriteWidget)

    def retranslateUi(self, SpriteWidget):
        SpriteWidget.setWindowTitle(_translate("SpriteWidget", "Form", None))
        self.btn_add_frame.setText(_translate("SpriteWidget", "Add a frame...", None))
        self.lbl_name.setText(_translate("SpriteWidget", "Name :", None))

