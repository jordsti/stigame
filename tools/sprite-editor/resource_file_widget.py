__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import resource_widget
import resource_file
import os


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

        self.btn_add_resource.clicked.connect(self.new_resource)

        self.__fill_resources()

    def new_resource(self):

        filepath = str(QtGui.QFileDialog.getOpenFileName(self, "New resource", QtCore.QDir.homePath(), "Image (*.png);;All files (*.*)"))

        if os.path.exists(filepath):

            rname = os.path.basename(filepath).split('.')[0]

            fp = open(filepath, 'rb')

            chunk = fp.read(1024)

            data = chunk

            while len(chunk) == 1024:
                chunk = fp.read(1024)
                data += chunk

            fp.close()

            res = resource_file.resource(rname, data)

            self.res_file.resources.append(res)

            self.__fill_resources()



    def __fill_resources(self):
        for rw in self.resources_widget:
            rw.deleteLater()
            #self.scroll_layout.removeWidget(rw)

        self.resources_widget = []

        for r in self.res_file.resources:
            rw = resource_widget.resource_widget(r)
            self.scroll_layout.addWidget(rw)
            self.resources_widget.append(rw)

    #method todo
    #base class for pane
    def save(self):

        if self.res_file.path is not None:
            self.res_file.write_file()
        else:
            self.save_as()

    def save_as(self):
        filepath = str(QtGui.QFileDialog.getSaveFileName(self, "Save as", QtCore.QDir.homePath(), "Resource File (*.res)"))
        if len(filepath) > 0:
            self.res_file.path = filepath
            self.res_file.write_file()

    def closing(self):
        return True