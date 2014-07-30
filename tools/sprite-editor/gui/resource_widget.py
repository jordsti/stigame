# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'resource_widget.ui'
#
# Created: Wed Jul 30 19:28:49 2014
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

class Ui_resource_widget(object):
    def setupUi(self, resource_widget):
        resource_widget.setObjectName(_fromUtf8("resource_widget"))
        resource_widget.resize(509, 101)
        self.horizontalLayoutWidget = QtGui.QWidget(resource_widget)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(10, 10, 491, 80))
        self.horizontalLayoutWidget.setObjectName(_fromUtf8("horizontalLayoutWidget"))
        self.layout_main = QtGui.QHBoxLayout(self.horizontalLayoutWidget)
        self.layout_main.setMargin(5)
        self.layout_main.setObjectName(_fromUtf8("layout_main"))
        self.lbl_image = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_image.setMinimumSize(QtCore.QSize(50, 50))
        self.lbl_image.setObjectName(_fromUtf8("lbl_image"))
        self.layout_main.addWidget(self.lbl_image)
        self.lbl_spacer = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_spacer.setMinimumSize(QtCore.QSize(60, 70))
        self.lbl_spacer.setText(_fromUtf8(""))
        self.lbl_spacer.setObjectName(_fromUtf8("lbl_spacer"))
        self.layout_main.addWidget(self.lbl_spacer)
        self.layout_res_info = QtGui.QFormLayout()
        self.layout_res_info.setSizeConstraint(QtGui.QLayout.SetDefaultConstraint)
        self.layout_res_info.setObjectName(_fromUtf8("layout_res_info"))
        self.lbl_name = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_name.setObjectName(_fromUtf8("lbl_name"))
        self.layout_res_info.setWidget(0, QtGui.QFormLayout.LabelRole, self.lbl_name)
        self.le_name = QtGui.QLineEdit(self.horizontalLayoutWidget)
        self.le_name.setMaximumSize(QtCore.QSize(160, 20))
        self.le_name.setObjectName(_fromUtf8("le_name"))
        self.layout_res_info.setWidget(0, QtGui.QFormLayout.FieldRole, self.le_name)
        self.lbl_width = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_width.setObjectName(_fromUtf8("lbl_width"))
        self.layout_res_info.setWidget(1, QtGui.QFormLayout.LabelRole, self.lbl_width)
        self.lbl_width_value = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_width_value.setObjectName(_fromUtf8("lbl_width_value"))
        self.layout_res_info.setWidget(1, QtGui.QFormLayout.FieldRole, self.lbl_width_value)
        self.lbl_height = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_height.setObjectName(_fromUtf8("lbl_height"))
        self.layout_res_info.setWidget(2, QtGui.QFormLayout.LabelRole, self.lbl_height)
        self.lbl_height_value = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_height_value.setObjectName(_fromUtf8("lbl_height_value"))
        self.layout_res_info.setWidget(2, QtGui.QFormLayout.FieldRole, self.lbl_height_value)
        self.layout_main.addLayout(self.layout_res_info)

        self.retranslateUi(resource_widget)
        QtCore.QMetaObject.connectSlotsByName(resource_widget)

    def retranslateUi(self, resource_widget):
        resource_widget.setWindowTitle(_translate("resource_widget", "Form", None))
        self.lbl_image.setText(_translate("resource_widget", "N/A", None))
        self.lbl_name.setText(_translate("resource_widget", "Name :", None))
        self.lbl_width.setText(_translate("resource_widget", "Width :", None))
        self.lbl_width_value.setText(_translate("resource_widget", "0 px", None))
        self.lbl_height.setText(_translate("resource_widget", "Height :", None))
        self.lbl_height_value.setText(_translate("resource_widget", "0 px", None))

