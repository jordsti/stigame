# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'frame_widget.ui'
#
# Created: Tue Jul 29 20:34:01 2014
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

class Ui_frame_widget(object):
    def setupUi(self, frame_widget):
        frame_widget.setObjectName(_fromUtf8("frame_widget"))
        frame_widget.resize(533, 114)
        self.horizontalLayoutWidget = QtGui.QWidget(frame_widget)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(0, 10, 521, 91))
        self.horizontalLayoutWidget.setObjectName(_fromUtf8("horizontalLayoutWidget"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setSpacing(4)
        self.horizontalLayout.setMargin(4)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.lbl_frame_img = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_frame_img.setStyleSheet(_fromUtf8("text-align: center;\n"
"border: 1px solid white;\n"
"background-color: black;"))
        self.lbl_frame_img.setObjectName(_fromUtf8("lbl_frame_img"))
        self.horizontalLayout.addWidget(self.lbl_frame_img)
        self.verticalLayout = QtGui.QVBoxLayout()
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.lbl_id = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_id.setObjectName(_fromUtf8("lbl_id"))
        self.verticalLayout.addWidget(self.lbl_id)
        self.lbl_width = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_width.setObjectName(_fromUtf8("lbl_width"))
        self.verticalLayout.addWidget(self.lbl_width)
        self.lbl_height = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_height.setObjectName(_fromUtf8("lbl_height"))
        self.verticalLayout.addWidget(self.lbl_height)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.gridLayout = QtGui.QGridLayout()
        self.gridLayout.setObjectName(_fromUtf8("gridLayout"))
        self.btn_move_down = QtGui.QPushButton(self.horizontalLayoutWidget)
        self.btn_move_down.setObjectName(_fromUtf8("btn_move_down"))
        self.gridLayout.addWidget(self.btn_move_down, 2, 0, 1, 1)
        self.btn_move_up = QtGui.QPushButton(self.horizontalLayoutWidget)
        self.btn_move_up.setObjectName(_fromUtf8("btn_move_up"))
        self.gridLayout.addWidget(self.btn_move_up, 0, 0, 1, 1)
        self.btn_delete_frame = QtGui.QPushButton(self.horizontalLayoutWidget)
        self.btn_delete_frame.setObjectName(_fromUtf8("btn_delete_frame"))
        self.gridLayout.addWidget(self.btn_delete_frame, 1, 0, 1, 1)
        self.horizontalLayout.addLayout(self.gridLayout)

        self.retranslateUi(frame_widget)
        QtCore.QMetaObject.connectSlotsByName(frame_widget)

    def retranslateUi(self, frame_widget):
        frame_widget.setWindowTitle(_translate("frame_widget", "Form", None))
        self.lbl_frame_img.setText(_translate("frame_widget", "N/A", None))
        self.lbl_id.setText(_translate("frame_widget", "Id : 0", None))
        self.lbl_width.setText(_translate("frame_widget", "Width : 0", None))
        self.lbl_height.setText(_translate("frame_widget", "Height : 0", None))
        self.btn_move_down.setText(_translate("frame_widget", "Move Down", None))
        self.btn_move_up.setText(_translate("frame_widget", "Move Up", None))
        self.btn_delete_frame.setText(_translate("frame_widget", "Delete", None))

