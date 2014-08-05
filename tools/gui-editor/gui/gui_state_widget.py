# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'gui_state_widget.ui'
#
# Created: Tue Aug 05 19:12:33 2014
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
        Form.resize(547, 425)
        self.horizontalLayoutWidget = QtGui.QWidget(Form)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(9, 1, 531, 421))
        self.horizontalLayoutWidget.setObjectName(_fromUtf8("horizontalLayoutWidget"))
        self.layout_main = QtGui.QHBoxLayout(self.horizontalLayoutWidget)
        self.layout_main.setMargin(0)
        self.layout_main.setObjectName(_fromUtf8("layout_main"))
        self.lw_items = QtGui.QListWidget(self.horizontalLayoutWidget)
        self.lw_items.setMinimumSize(QtCore.QSize(100, 200))
        self.lw_items.setMaximumSize(QtCore.QSize(200, 16777215))
        self.lw_items.setObjectName(_fromUtf8("lw_items"))
        self.layout_main.addWidget(self.lw_items)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        Form.setWindowTitle(_translate("Form", "Form", None))

