__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import frame_widget
import gui


class sprite_widget(QtGui.QWidget, gui.Ui_SpriteWidget):

    def __init__(self, sprite, parent=None):
        super(sprite_widget, self).__init__(parent)
        self.setupUi(self)
        self.sprite = sprite
        self.frames_widget = []
        self.__init_widget()

    def __init_widget(self):
        self.le_name.setText(self.sprite.name)

        i = 0
        for f in self.sprite.frames:

            fw = frame_widget.frame_widget(i, f.img_data, self.sprite.width, self.sprite.height)
            self.frames_widget.append(fw)
            #self.sa_frames.addWidget(fw)

            i += 1
