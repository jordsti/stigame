__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import os
import sprite
import sprite_widget

class main_window(QtGui.QMainWindow, gui.Ui_MainWindow):

    def __init__(self, parent=None):
        super(main_window, self).__init__(parent)
        self.setupUi(self)
        self.__assign_actions()
        self.tabs = []

    def __assign_actions(self):
        self.actionQuit.triggered.connect(self.close)
        self.actionOpen.triggered.connect(self.open_sprite)

    def open_sprite(self):
        filepath = str(QtGui.QFileDialog.getOpenFileName(self, "Open a sprite"))

        if os.path.exists(filepath):
            spr = sprite.sprite(filepath)
            self.add_tab_sprite(spr)

    def add_tab_sprite(self, spr):
        tab = sprite_widget.sprite_widget(spr)
        self.tw_sprites.addTab(tab, "Sprite : %s" % spr.name)



