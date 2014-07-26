__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui


class frame_widget(QtGui.QWidget, gui.Ui_frame_widget):

    def __init__(self, frame_id, img_data, parent=None):
        super(frame_widget, self).__init__(parent)
        self.setupUi(self)
        self.frame_id = frame_id
        self.img_data = img_data
        self.pixmap = None
        self.__init_widget()

        self.move_up = None
        self.move_down = None
        self.delete_frame = None

    def refresh_labels(self):
        self.lbl_id.setText("Id : %d" % self.frame_id)
        self.lbl_width.setText("Width : %d" % self.pixmap.width())
        self.lbl_height.setText("Height : %d" % self.pixmap.height())

    def __init_widget(self):
        self.pixmap = QtGui.QPixmap()
        self.pixmap.loadFromData(self.img_data)
        self.lbl_frame_img.setPixmap(self.pixmap)
        self.lbl_frame_img.setFixedSize(self.pixmap.width() + 1, self.pixmap.height() + 1)
        self.setMinimumSize(300, 100)

        self.btn_move_up.clicked.connect(self.move_up_action)
        self.btn_move_down.clicked.connect(self.move_down_action)
        self.btn_delete_frame.clicked.connect(self.delete_frame_action)

        self.refresh_labels()

    def delete_frame_action(self):

        if self.delete_frame is not None:
            self.delete_frame(self)

    def move_up_action(self):

        if self.move_up is not None:
            self.move_up(self)

    def move_down_action(self):

        if self.move_down is not None:
            self.move_down(self)