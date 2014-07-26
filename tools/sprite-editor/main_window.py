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
        self.actionNew_Sprite.triggered.connect(self.new_sprite)
        self.actionOpen.triggered.connect(self.open_sprite)
        self.actionSave_as.triggered.connect(self.save_as)
        self.actionSave.triggered.connect(self.save)


    def save_as(self):
        cur = self.tw_sprites.currentWidget()
        cur.save_as()

    def save(self):
        cur = self.tw_sprites.currentWidget()
        cur.save()

    def refresh_file_menu(self):
        val = len(self.tabs) > 0
        self.actionSave.setEnabled(val)
        self.actionSave_as.setEnabled(val)
        self.actionExport.setEnabled(val)

    def new_sprite(self):
        spr = sprite.sprite()
        spr.name = "Unnamed"
        self.add_tab_sprite(spr)

    def open_sprite(self):
        filepath = str(QtGui.QFileDialog.getOpenFileName(self, "Open a sprite"))
        if os.path.exists(filepath):
            if filepath.endswith(sprite.sprite.FileExtension):
                spr = sprite.sprite(filepath)
                self.add_tab_sprite(spr)
            else:
                print "File not supported"

    def name_changed(self, new_name):
        cur = self.tw_sprites.currentIndex()
        self.tw_sprites.setTabText(cur, new_name)

    def add_tab_sprite(self, spr):
        tab = sprite_widget.sprite_widget(spr)
        tab.name_changed = self.name_changed
        if spr.path is None:
            self.tw_sprites.addTab(tab, "Sprite : %s *" % spr.name)
            self.tabs.append(tab)
        else:
            self.tw_sprites.addTab(tab, "Sprite : %s" % spr.name)
            self.tabs.append(tab)

        self.refresh_file_menu()


