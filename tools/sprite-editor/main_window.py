__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import os
import sprite
import direction_sprite
import direction_sprite_widget
import sprite_widget
import var_file
import resource_file
import resource_file_widget

class main_window(QtGui.QMainWindow, gui.Ui_MainWindow):

    def __init__(self, parent=None):
        super(main_window, self).__init__(parent)
        self.setupUi(self)
        self.__assign_actions()
        self.tabs = []

        self.tw_sprites = QtGui.QTabWidget(self)
        self.setCentralWidget(self.tw_sprites)

    def __assign_actions(self):
        self.actionQuit.triggered.connect(self.close)
        self.actionSprite.triggered.connect(self.new_sprite)
        self.actionDirection_Sprite.triggered.connect(self.new_dsprite)
        self.actionResource_File.triggered.connect(self.new_res_file)
        self.actionOpen.triggered.connect(self.open_file)
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

    def new_dsprite(self):
        dspr = direction_sprite.direction_sprite()
        dspr.name = "Unnamed"
        self.add_tab_dsprite(dspr)

    def new_res_file(self):
        res_file = resource_file.resource_file()
        self.add_tab_resfile(res_file)

    def close_tab(self):
        cur = self.tw_sprites.currentIndex()
        tab = self.tw_sprites.widget(cur)
        if tab.closing():

            self.tw_sprites.removeTab(cur)
            self.tabs.remove(tab)

            self.refresh_file_menu()
        #todo save handling..

    def open_file(self):
        filepath = str(QtGui.QFileDialog.getOpenFileName(self, "Open a file", QtCore.QDir.homePath() ,"Sprite File (*.bspr);;Direction Sprite File (*.bdspr);;Resource File (*.res);;All Files (*.*)"))
        if os.path.exists(filepath):
            if filepath.endswith(sprite.sprite.FileExtension):
                spr = sprite.sprite(filepath)
                self.add_tab_sprite(spr)

            elif filepath.endswith(sprite.sprite.VarFileExtension):
                vf = var_file.var_file(filepath)
                spr = sprite.sprite()
                spr.from_var_file(vf)
                self.add_tab_sprite(spr)

            elif filepath.endswith(resource_file.resource_file.FileExtension):
                rf = resource_file.resource_file(filepath)
                self.add_tab_resfile(rf)

            elif filepath.endswith(direction_sprite.direction_sprite.FileExtension):
                dspr = direction_sprite.direction_sprite(filepath)
                self.add_tab_dsprite(dspr)
            else:
                print "File not supported"

    def name_changed(self, new_name):
        cur = self.tw_sprites.currentIndex()
        self.tw_sprites.setTabText(cur, new_name)

    def add_tab_resfile(self, res_file):
        tab = resource_file_widget.resource_file_widget(res_file)
        if res_file.path is not None:
            tab_name = os.path.basename(res_file.path)
        else:
            tab_name = 'Unnamed'

        self.tw_sprites.addTab(tab, tab_name)
        self.tabs.append(tab)

        self.refresh_file_menu()


    def add_tab_dsprite(self, dspr):
        tab = direction_sprite_widget.direction_sprite_widget(dspr)
        tab.name_changed = self.name_changed
        if dspr.path is None:
            self.tw_sprites.addTab(tab, "dSprite : %s *" % dspr.name)
            self.tabs.append(tab)
        else:
            self.tw_sprites.addTab(tab, "dSprite : %s" % dspr.name)
            self.tabs.append(tab)

        self.tw_sprites.setCurrentIndex(self.tw_sprites.indexOf(tab))
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

        self.tw_sprites.setCurrentIndex(self.tw_sprites.indexOf(tab))
        self.refresh_file_menu()


