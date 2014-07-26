__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import main_window
import sys

if __name__ == '__main__':

    app = QtGui.QApplication(sys.argv)
    _main_window = main_window.main_window()
    _main_window.show()
    app.exec_()