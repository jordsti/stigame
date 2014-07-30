__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import resource_widget


class resource_file_widget(QtGui.QWidget, gui.Ui_resource_file_widget):

    def __init__(self, res_file, parent=None):
        super(resource_file_widget, self).__init__(parent)
        self.res_file = res_file
        self.setupUi(self)
        self.resources_widget = []
        self.__init__widget()

    def __init__widget(self):
        self.container = QtGui.QWidget()
        self.setLayout(self.layout_main)
        self.scroll_layout = QtGui.QVBoxLayout()
        self.sa_resources.setWidget(self.container)
        self.container.setLayout(self.scroll_layout)
        self.__fill_resources()


    def __fill_resources(self):
        for rw in self.resources_widget:
            self.scroll_layout.removeWidget(rw)
            rw.deleteLater()

        for r in self.res_file.resources:
            rw = resource_widget.resource_widget(r)
            self.scroll_layout.addWidget(rw)
            self.resources_widget.append(rw)

    #method todo
    #base class for pane
    def save(self):
        pass

    def save_as(self):
        pass

    def closing(self):
        return True