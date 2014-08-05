# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'gui_state_widget.ui'
#
# Created: Tue Aug 05 19:42:38 2014
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

class Ui_gui_state_widget(object):
    def setupUi(self, gui_state_widget):
        gui_state_widget.setObjectName(_fromUtf8("gui_state_widget"))
        gui_state_widget.resize(547, 425)
        self.horizontalLayoutWidget = QtGui.QWidget(gui_state_widget)
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

        self.retranslateUi(gui_state_widget)
        QtCore.QMetaObject.connectSlotsByName(gui_state_widget)

    def retranslateUi(self, gui_state_widget):
        gui_state_widget.setWindowTitle(_translate("gui_state_widget", "Form", None))

