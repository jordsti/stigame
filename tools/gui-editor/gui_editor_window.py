__author__ = 'JordSti'
import gui
from PyQt4 import QtGui, QtCore
import gui_state_widget


class gui_editor_window(QtGui.QMainWindow, gui.Ui_gui_editor_window):

    def __init__(self):
        super(gui_editor_window, self).__init__()
        self.setupUi(self)
        self.__init_components()

    def __init_components(self):
        self.actionNew.triggered.connect(self.new_state)

    def new_state(self):
        widget = gui_state_widget.gui_state_widget()
        self.tw_states.addTab(widget, "Unknown")

    def closeEvent(self, *args, **kwargs):
        nb = self.tw_states.count()

        for i in range(nb):
            tab = self.tw_states.widget(i)
            tab.viewport.renderer.ask_to_stop()

