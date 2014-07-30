__author__ = 'JordSti'
from PyQt4 import QtCore, QtGui
import gui


class resource_widget(QtGui.QWidget, gui.Ui_resource_widget):

    def __init__(self, resource, parent=None):
        super(resource_widget, self).__init__(parent)
        self.resource = resource
        self.setupUi(self)
        self.setLayout(self.layout_main)
        self.pixmap = None
        self.__init__widget()

    def __init__widget(self):
        #pixmap init
        #self.setMinimumSize(300, 200)

        self.pixmap = QtGui.QPixmap()
        self.pixmap.loadFromData(self.resource.data)

        self.lbl_width_value.setText("%d px" % self.pixmap.width())
        self.lbl_height_value.setText("%d px" % self.pixmap.height())
        self.le_name.setText(self.resource.name)

        #fix lbl image

        self.lbl_image.setPixmap(self.pixmap)
        self.lbl_image.setFixedSize(self.pixmap.width(), self.pixmap.height())