__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import os
import sprite
import direction_sprite
import direction_sprite_widget
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
        self.actionClose.triggered.connect(self.close_tab)


    def closeEvent(self, event):

        if len(self.tabs) == 0:
            event.accept()
        else:
            btn = QtGui.QMessageBox.question(self, "Are you sure ?", "Do you want to quit with %d tab(s) opened" % len(self.tabs), "Yes", "No")

            if btn == 0:
                event.accept()
            else:
                event.ignore()


    def resizeEvent(self, resizeEvent):
        self.tw_sprites.setGeometry(0, 0, self.width()- 6, self.height() - 20)


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
        self.actionClose.setEnabled(val)

    def new_sprite(self):
        spr = sprite.sprite()
        spr.name = "Unnamed"
        self.add_tab_sprite(spr)

    def close_tab(self):
        cur = self.tw_sprites.currentIndex()
        tab = self.tw_sprites.widget(cur)
        if tab.closing():
            self.tabs.remove(self.tw_sprites.pop(cur))

            self.refresh_file_menu()
        #todo save handling..

    def open_sprite(self):
        filepath = str(QtGui.QFileDialog.getOpenFileName(self, "Open a sprite"))
        if os.path.exists(filepath):
            if filepath.endswith(sprite.sprite.FileExtension):
                spr = sprite.sprite(filepath)
                self.add_tab_sprite(spr)
            elif filepath.endswith(direction_sprite.direction_sprite.FileExtension):
                dspr = direction_sprite.direction_sprite(filepath)
                self.add_tab_dsprite(dspr)
            else:
                print "File not supported"

    def name_changed(self, new_name):
        cur = self.tw_sprites.currentIndex()
        self.tw_sprites.setTabText(cur, new_name)


    def add_tab_dsprite(self, dspr):
        tab = direction_sprite_widget.direction_sprite_widget(dspr)
        tab.name_changed = self.name_changed
        if dspr.path is None:
            self.tw_sprites.addTab(tab, "dSprite : %s *" % dspr.name)
            self.tabs.append(tab)
        else:
            self.tw_sprites.addTab(tab, "dSprite : %s" % dspr.name)
            self.tabs.append(tab)

        self.refresh_file_menu()

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


