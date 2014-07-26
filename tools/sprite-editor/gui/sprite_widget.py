# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'sprite_widget.ui'
#
# Created: Sat Jul 26 17:34:33 2014
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
        SpriteWidget.resize(566, 457)
        self.btn_add_frame = QtGui.QPushButton(SpriteWidget)
        self.btn_add_frame.setGeometry(QtCore.QRect(390, 20, 111, 23))
        self.btn_add_frame.setObjectName(_fromUtf8("btn_add_frame"))
        self.sa_frames = QtGui.QScrollArea(SpriteWidget)
        self.sa_frames.setGeometry(QtCore.QRect(20, 150, 471, 271))
        self.sa_frames.setWidgetResizable(True)
        self.sa_frames.setObjectName(_fromUtf8("sa_frames"))
        self.scrollAreaWidgetContents = QtGui.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 469, 269))
        self.scrollAreaWidgetContents.setObjectName(_fromUtf8("scrollAreaWidgetContents"))
        self.sa_frames.setWidget(self.scrollAreaWidgetContents)
        self.lbl_frames = QtGui.QLabel(SpriteWidget)
        self.lbl_frames.setGeometry(QtCore.QRect(20, 130, 46, 13))
        self.lbl_frames.setObjectName(_fromUtf8("lbl_frames"))
        self.gp_preview = QtGui.QGroupBox(SpriteWidget)
        self.gp_preview.setGeometry(QtCore.QRect(240, 10, 141, 111))
        self.gp_preview.setObjectName(_fromUtf8("gp_preview"))
        self.lbl_preview = QtGui.QLabel(self.gp_preview)
        self.lbl_preview.setGeometry(QtCore.QRect(20, 20, 31, 31))
        self.lbl_preview.setObjectName(_fromUtf8("lbl_preview"))
        self.sp_fps = QtGui.QSpinBox(self.gp_preview)
        self.sp_fps.setGeometry(QtCore.QRect(80, 20, 41, 22))
        self.sp_fps.setMinimum(15)
        self.sp_fps.setMaximum(150)
        self.sp_fps.setObjectName(_fromUtf8("sp_fps"))
        self.gb_sprite = QtGui.QGroupBox(SpriteWidget)
        self.gb_sprite.setGeometry(QtCore.QRect(0, 10, 221, 111))
        self.gb_sprite.setObjectName(_fromUtf8("gb_sprite"))
        self.formLayoutWidget = QtGui.QWidget(self.gb_sprite)
        self.formLayoutWidget.setGeometry(QtCore.QRect(20, 20, 191, 74))
        self.formLayoutWidget.setObjectName(_fromUtf8("formLayoutWidget"))
        self.formLayout = QtGui.QFormLayout(self.formLayoutWidget)
        self.formLayout.setMargin(0)
        self.formLayout.setObjectName(_fromUtf8("formLayout"))
        self.lbl_name = QtGui.QLabel(self.formLayoutWidget)
        self.lbl_name.setObjectName(_fromUtf8("lbl_name"))
        self.formLayout.setWidget(0, QtGui.QFormLayout.LabelRole, self.lbl_name)
        self.le_name = QtGui.QLineEdit(self.formLayoutWidget)
        self.le_name.setObjectName(_fromUtf8("le_name"))
        self.formLayout.setWidget(0, QtGui.QFormLayout.FieldRole, self.le_name)
        self.lbl_width = QtGui.QLabel(self.formLayoutWidget)
        self.lbl_width.setObjectName(_fromUtf8("lbl_width"))
        self.formLayout.setWidget(1, QtGui.QFormLayout.LabelRole, self.lbl_width)
        self.le_width = QtGui.QLineEdit(self.formLayoutWidget)
        self.le_width.setObjectName(_fromUtf8("le_width"))
        self.formLayout.setWidget(1, QtGui.QFormLayout.FieldRole, self.le_width)
        self.lbl_height = QtGui.QLabel(self.formLayoutWidget)
        self.lbl_height.setObjectName(_fromUtf8("lbl_height"))
        self.formLayout.setWidget(2, QtGui.QFormLayout.LabelRole, self.lbl_height)
        self.le_height = QtGui.QLineEdit(self.formLayoutWidget)
        self.le_height.setObjectName(_fromUtf8("le_height"))
        self.formLayout.setWidget(2, QtGui.QFormLayout.FieldRole, self.le_height)

        self.retranslateUi(SpriteWidget)
        QtCore.QMetaObject.connectSlotsByName(SpriteWidget)

    def retranslateUi(self, SpriteWidget):
        SpriteWidget.setWindowTitle(_translate("SpriteWidget", "Form", None))
        self.btn_add_frame.setText(_translate("SpriteWidget", "Add a frame...", None))
        self.lbl_frames.setText(_translate("SpriteWidget", "Frame(s)", None))
        self.gp_preview.setTitle(_translate("SpriteWidget", "Preview", None))
        self.lbl_preview.setText(_translate("SpriteWidget", "P", None))
        self.gb_sprite.setTitle(_translate("SpriteWidget", "Sprite Information", None))
        self.lbl_name.setText(_translate("SpriteWidget", "Name :", None))
        self.lbl_width.setText(_translate("SpriteWidget", "Width :", None))
        self.le_width.setText(_translate("SpriteWidget", "0", None))
        self.lbl_height.setText(_translate("SpriteWidget", "Height :", None))
        self.le_height.setText(_translate("SpriteWidget", "0", None))

