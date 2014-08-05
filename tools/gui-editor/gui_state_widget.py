__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import vp_widget


class gui_state_widget(QtGui.QWidget, gui.Ui_gui_state_widget):

    def __init__(self, parent=None):
        super(gui_state_widget, self).__init__(parent)
        self.setupUi(self)
        self.__init__components()

    def __init__components(self):
        self.setLayout(self.layout_main)
        self.viewport = vp_widget.vp_widget(self)
        self.layout_main.addWidget(self.viewport)

