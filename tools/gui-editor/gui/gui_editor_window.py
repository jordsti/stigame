# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'gui_editor_window.ui'
#
# Created: Tue Aug 05 19:01:08 2014
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

class Ui_gui_editor_window(object):
    def setupUi(self, gui_editor_window):
        gui_editor_window.setObjectName(_fromUtf8("gui_editor_window"))
        gui_editor_window.resize(503, 383)
        self.centralwidget = QtGui.QWidget(gui_editor_window)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.tw_states = QtGui.QTabWidget(self.centralwidget)
        self.tw_states.setGeometry(QtCore.QRect(6, 9, 491, 341))
        self.tw_states.setObjectName(_fromUtf8("tw_states"))
        gui_editor_window.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(gui_editor_window)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 503, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        self.menuFile = QtGui.QMenu(self.menubar)
        self.menuFile.setObjectName(_fromUtf8("menuFile"))
        gui_editor_window.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(gui_editor_window)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        gui_editor_window.setStatusBar(self.statusbar)
        self.actionNew = QtGui.QAction(gui_editor_window)
        self.actionNew.setObjectName(_fromUtf8("actionNew"))
        self.menuFile.addAction(self.actionNew)
        self.menubar.addAction(self.menuFile.menuAction())

        self.retranslateUi(gui_editor_window)
        self.tw_states.setCurrentIndex(-1)
        QtCore.QMetaObject.connectSlotsByName(gui_editor_window)

    def retranslateUi(self, gui_editor_window):
        gui_editor_window.setWindowTitle(_translate("gui_editor_window", "MainWindow", None))
        self.menuFile.setTitle(_translate("gui_editor_window", "File", None))
        self.actionNew.setText(_translate("gui_editor_window", "New", None))

