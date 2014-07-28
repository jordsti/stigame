__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import gui
import direction_sprite
import frame_widget


class direction_sprite_widget(QtGui.QWidget, gui.Ui_direction_sprite_widget):

    def __init__(self, sprite, parent=None):
        super(direction_sprite_widget, self).__init__(parent)
        self.setupUi(self)
        self._tick = 0
        self.sprite = sprite
        self.name_changed = None
        self.frames_widget = []
        self.__init__widget()

    def __name_changed(self):
        if self.name_changed is not None:
            self.name_changed("dSprite : %s" % self.sprite.name)


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

        self.timer = QtCore.QTimer()

        self.timer.setInterval(1000 / 15)
        self.timer.timeout.connect(self.preview_tick)

        self.sp_fps.valueChanged.connect(self.change_fps)

        self.timer.start()

        self.btn_add_frame.clicked.connect(self.add_frame)
        self.le_name.textChanged.connect(self.sprite_name_changed)

    def sprite_name_changed(self):

        name = str(self.le_name.text())

        self.sprite.name = name

        self.__name_changed()

    def add_frame(self):
        imgpath = QtGui.QFileDialog.getOpenFileName(self, "Add a frame")
        direction = direction_sprite.get_direction(self.cb_direction.currentText())

        fp = open(imgpath, 'rb')
        img_data = fp.read(1024)
        chunk = img_data

        while len(chunk) == 1024:
            chunk = fp.read(1024)
            img_data += chunk

        fp.close()
        frame = direction_sprite.sprite_frame(direction, img_data)
        self.sprite.frames[direction].append(frame)
        self.__fill_frames()

    def save(self):
        if self.sprite.path is None:
            self.save_as()
        else:
            self.sprite.write_file()

    def save_as(self):
        filepath = QtGui.QFileDialog.getSaveFileName(self, "Save As..")
        self.sprite.path = filepath
        self.sprite.write_file()

    def closing(self):
        return True

    def change_fps(self):
        fps = int(str(self.sp_fps.text()))
        self.timer.setInterval(100 / fps)


    def preview_tick(self):
        if len(self.frames_widget) > 0:
            frame = self.frames_widget[self._tick % len(self.frames_widget)]
            self.lbl_preview.setPixmap(frame.pixmap)
            if not self.lbl_preview.width() == frame.pixmap.width() and not self.lbl_preview.height() == frame.pixmap.height():
                self.lbl_preview.setFixedSize(frame.pixmap.width(), frame.pixmap.height())

        self._tick += 1

    def closing(self):
        btn = QtGui.QMessageBox.question(self, "Are you sure", "Do you want to close this sprite ?", "Yes", "No")
        return btn == 0

    def __fill_frames(self):

        for fw in self.frames_widget:
            self.layout_frames.removeWidget(fw)

        self.frames_widget = []

        direction = direction_sprite.get_direction(str(self.cb_direction.currentText()))
        frames = self.sprite.frames[direction]
        i = 0
        for f in frames:
            fw = frame_widget.frame_widget(i, f.img_data)
            self.frames_widget.append(fw)
            self.layout_frames.addWidget(fw)
            i += 1

