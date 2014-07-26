__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui


class frame_widget(QtGui.QWidget, gui.Ui_frame_widget):

    def __init__(self, frame_id, img_data, width, height, parent=None):
        super(frame_widget, self).__init__(parent)
        self.setupUi(self)
        self.frame_id = frame_id
        self.img_data = img_data
        self.pixmap = None
        self.__init_widget()
        self.width = width
        self.height = height

    def __init_widget(self):

        img = QtGui.QImage()
        img.fromData(self.img_data)

        self.pixmap = QtGui.QPixmap()
        self.pixmap.fromImage(img)
        self.lbl_frame_img.setPixmap(self.pixmap)
        self.lbl_id.setText("Id : %d" % self.frame_id)
        self.lbl_width.setText("Width : %d" % self.pixmap.width())
        self.lbl_height.setText("Height : %d" % self.pixmap.height())

