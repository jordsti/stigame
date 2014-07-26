__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import frame_widget
import sprite
import gui
import os


class sprite_widget(QtGui.QWidget, gui.Ui_SpriteWidget):

    def __init__(self, sprite, parent=None):
        super(sprite_widget, self).__init__(parent)
        self.setupUi(self)
        self.sprite = sprite
        self.frames_widget = []
        self.layout_frames = QtGui.QVBoxLayout()
        self.container = QtGui.QWidget()
        self.preview_timer = QtCore.QTimer()
        self.preview_fps = 15
        self._tick = 0
        self.name_changed = None
        self.__init_widget()

    def save(self):
        if self.sprite.path is None:
            self.save_as()
        else:
            self.sprite.write_file()

    def save_as(self):
        filepath = QtGui.QFileDialog.getSaveFileName(self, "Save as...", QtCore.QString(), "*%s" % sprite.sprite.FileExtension)
        self.sprite.path = filepath
        self.sprite.write_file()


    def move_up_frame(self, fwidget):
        if fwidget.frame_id > 0:
            f_id = fwidget.frame_id
            tmp = self.frames_widget[f_id-1]

            fwidget.frame_id = f_id - 1
            tmp.frame_id = f_id

            self.frames_widget[f_id] = tmp
            self.frames_widget[f_id-1] = fwidget

            tmp_frame = self.sprite.frames[f_id]

            self.sprite.frames[f_id] =  self.sprite.frames[f_id-1]
            self.sprite.frames[f_id-1] = tmp_frame
            #todo refresh frames info

            tmp.refresh_labels()
            fwidget.refresh_labels()

            self.refill_frames()

    def add_frame(self):

        filepath = str(QtGui.QFileDialog.getOpenFileName(self, "Open a sprite"))

        if os.path.exists(filepath):
            fp = open(filepath, 'rb')
            data = fp.read(1024)

            while len(data) == 1024:
                data += fp.read(1024)

            fp.close()

            frame = sprite.sprite_frame(data)

            self.sprite.add_frame(frame)
            fw = frame_widget.frame_widget(len(self.sprite.frames) - 1, data)

            self.frames_widget.append(fw)
            self.layout_frames.addWidget(fw)


    def move_down_frame(self, fwidget):

        if fwidget.frame_id < len(self.frames_widget) - 1:

            f_id = fwidget.frame_id

            tmp = self.frames_widget[f_id+1]

            self.frames_widget[f_id+1] = fwidget
            self.frames_widget[f_id] = tmp

            tmp_frame = self.sprite.frames[f_id]

            self.sprite.frames[f_id] =  self.sprite.frames[f_id+1]
            self.sprite.frames[f_id+1] = tmp_frame

            tmp.frame_id = f_id
            fwidget.frame_id = f_id + 1

            tmp.refresh_labels()
            fwidget.refresh_labels()

            self.refill_frames()

    def refill_frames(self):

        for fw in self.frames_widget:
            self.layout_frames.removeWidget(fw)

        for fw in self.frames_widget:
            self.layout_frames.addWidget(fw)

    def preview_tick(self):

        if len(self.frames_widget) > 0:
            frame = self.frames_widget[self._tick % len(self.frames_widget)]
            self.lbl_preview.setPixmap(frame.pixmap)
            if not self.lbl_preview.width() == frame.pixmap.width() and self.lbl_preview.height() == frame.pixmap.height():
                self.lbl_preview.setFixedSize(frame.pixmap.width(), frame.pixmap.height())

        self._tick += 1

    def __name_changed(self):
        new_name = "Sprite : %s" % self.le_name.text()
        self.sprite.name = new_name

        if self.name_changed is not None:
            self.name_changed(new_name)

    def __init_widget(self):
        self.preview_timer.setInterval(1000 / self.preview_fps)
        self.preview_timer.timeout.connect(self.preview_tick)
        self.le_name.setText(self.sprite.name)
        self.container.setLayout(self.layout_frames)
        self.sa_frames.setWidget(self.container)
        self.sa_frames.setWidgetResizable(True)
        self.le_name.textChanged.connect(self.__name_changed)
        self.le_width.setText(str(self.sprite.width))
        self.le_height.setText(str(self.sprite.height))
        i = 0

        for f in self.sprite.frames:

            fw = frame_widget.frame_widget(i, f.img_data)
            self.frames_widget.append(fw)
            fw.move_up = self.move_up_frame
            fw.move_down = self.move_down_frame

            #self.sa_frames.addWidget(fw)
            self.layout_frames.addWidget(fw)
            i += 1
        #self.container.setGeometry(0, 0, self.sa_frames.width(), fw.height() * i)
        self.preview_timer.start()

        self.sp_fps.valueChanged.connect(self.change_fps)
        self.btn_add_frame.clicked.connect(self.add_frame)

    def change_fps(self, value):
        self.preview_fps = int(str(value))
        self.preview_timer.setInterval(1000 / self.preview_fps)