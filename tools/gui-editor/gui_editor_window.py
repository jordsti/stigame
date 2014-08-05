__author__ = 'JordSti'
import gui
from PyQt4 import QtGui, QtCore


class gui_editor_window(QtGui.QMainWindow, gui.Ui_gui_editor_window):

    def __init__(self):
        super(gui_editor_window, self).__init__()
        self.setupUi(self)
        self.__init_components()
        self.show()

    def __init_components(self):
        self.actionNew.triggered.connect(self.new_state)

    def new_state(self):
        pass
