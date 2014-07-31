# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'resource_file_widget.ui'
#
# Created: Wed Jul 30 19:41:44 2014
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

class Ui_resource_file_widget(object):
    def setupUi(self, resource_file_widget):
        resource_file_widget.setObjectName(_fromUtf8("resource_file_widget"))
        resource_file_widget.resize(564, 407)
        self.verticalLayoutWidget = QtGui.QWidget(resource_file_widget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(30, 20, 491, 351))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.layout_main = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.layout_main.setMargin(5)
        self.layout_main.setObjectName(_fromUtf8("layout_main"))
        self.btn_add_resource = QtGui.QPushButton(self.verticalLayoutWidget)
        self.btn_add_resource.setMinimumSize(QtCore.QSize(80, 20))
        self.btn_add_resource.setMaximumSize(QtCore.QSize(160, 25))
        self.btn_add_resource.setObjectName(_fromUtf8("btn_add_resource"))
        self.layout_main.addWidget(self.btn_add_resource)
        self.sa_resources = QtGui.QScrollArea(self.verticalLayoutWidget)
        self.sa_resources.setWidgetResizable(True)
        self.sa_resources.setObjectName(_fromUtf8("sa_resources"))
        self.scrollAreaWidgetContents = QtGui.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 479, 310))
        self.scrollAreaWidgetContents.setObjectName(_fromUtf8("scrollAreaWidgetContents"))
        self.sa_resources.setWidget(self.scrollAreaWidgetContents)
        self.layout_main.addWidget(self.sa_resources)

        self.retranslateUi(resource_file_widget)
        QtCore.QMetaObject.connectSlotsByName(resource_file_widget)

    def retranslateUi(self, resource_file_widget):
        resource_file_widget.setWindowTitle(_translate("resource_file_widget", "Form", None))
        self.btn_add_resource.setText(_translate("resource_file_widget", "New resource...", None))

