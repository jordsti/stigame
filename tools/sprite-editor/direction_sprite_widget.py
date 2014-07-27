__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import direction_sprite
import frame_widget


class direction_sprite_widget(QtGui.QWidget, gui.Ui_direction_sprite_widget):

    def __init__(self, sprite, parent=None):
        super(direction_sprite_widget, self).__init__(parent)
        self.setupUi(self)
        self.sprite = sprite
        self.frame_widget = []
        self.__init__widget()


    def __init__widget(self):
        self.le_width.setText(str(self.sprite.width))
        self.le_height.setText(str(self.sprite.width))
        self.le_name.setText(self.sprite.name)

        #direction init

        self.cb_direction.addItem(direction_sprite.get_direction_string(direction_sprite.direction_sprite.Up))
        self.cb_direction.addItem(direction_sprite.get_direction_string(direction_sprite.direction_sprite.Down))
        self.cb_direction.addItem(direction_sprite.get_direction_string(direction_sprite.direction_sprite.Left))
        self.cb_direction.addItem(direction_sprite.get_direction_string(direction_sprite.direction_sprite.Right))
        self.cb_direction.addItem(direction_sprite.get_direction_string(direction_sprite.direction_sprite.Idle))
        self.cb_direction.setCurrentIndex(0)

        self.layout_frames = QtGui.QVBoxLayout()

        self.container = QtGui.QWidget()
        self.container.setLayout(self.layout_frames)

        self.sa_frames.setWidget(self.container)

        self.__fill_frames()

        self.cb_direction.currentIndexChanged.connect(self.__fill_frames)

    def __fill_frames(self):

        for fw in self.frame_widget:
            self.layout_frames.removeWidget(fw)

        self.frame_widget = []

        direction = direction_sprite.get_direction(str(self.cb_direction.currentText()))
        frames = self.sprite.frames[direction]
        i = 0
        for f in frames:
            fw = frame_widget.frame_widget(i, f.img_data)
            self.frame_widget.append(fw)
            self.layout_frames.addWidget(fw)
            i += 1

