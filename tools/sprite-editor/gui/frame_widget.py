# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'frame_widget.ui'
#
# Created: Fri Jul 25 22:15:50 2014
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
        frame_widget.resize(400, 79)
        self.lbl_frame_img = QtGui.QLabel(frame_widget)
        self.lbl_frame_img.setGeometry(QtCore.QRect(0, 0, 71, 61))
        self.lbl_frame_img.setObjectName(_fromUtf8("lbl_frame_img"))
        self.lbl_id = QtGui.QLabel(frame_widget)
        self.lbl_id.setGeometry(QtCore.QRect(80, 10, 46, 13))
        self.lbl_id.setObjectName(_fromUtf8("lbl_id"))
        self.lbl_width = QtGui.QLabel(frame_widget)
        self.lbl_width.setGeometry(QtCore.QRect(80, 30, 46, 13))
        self.lbl_width.setObjectName(_fromUtf8("lbl_width"))
        self.lbl_height = QtGui.QLabel(frame_widget)
        self.lbl_height.setGeometry(QtCore.QRect(80, 50, 46, 13))
        self.lbl_height.setObjectName(_fromUtf8("lbl_height"))
        self.btn_delete_frame = QtGui.QPushButton(frame_widget)
        self.btn_delete_frame.setGeometry(QtCore.QRect(220, 50, 75, 23))
        self.btn_delete_frame.setObjectName(_fromUtf8("btn_delete_frame"))
        self.btn_move_up = QtGui.QPushButton(frame_widget)
        self.btn_move_up.setGeometry(QtCore.QRect(310, 10, 75, 23))
        self.btn_move_up.setObjectName(_fromUtf8("btn_move_up"))
        self.btn_move_down = QtGui.QPushButton(frame_widget)
        self.btn_move_down.setGeometry(QtCore.QRect(310, 50, 75, 23))
        self.btn_move_down.setObjectName(_fromUtf8("btn_move_down"))

        self.retranslateUi(frame_widget)
        QtCore.QMetaObject.connectSlotsByName(frame_widget)

    def retranslateUi(self, frame_widget):
        frame_widget.setWindowTitle(_translate("frame_widget", "Form", None))
        self.lbl_frame_img.setText(_translate("frame_widget", "N/A", None))
        self.lbl_id.setText(_translate("frame_widget", "Id : 0", None))
        self.lbl_width.setText(_translate("frame_widget", "Width : 0", None))
        self.lbl_height.setText(_translate("frame_widget", "Height : 0", None))
        self.btn_delete_frame.setText(_translate("frame_widget", "Delete", None))
        self.btn_move_up.setText(_translate("frame_widget", "Move Up", None))
        self.btn_move_down.setText(_translate("frame_widget", "Move Down", None))

