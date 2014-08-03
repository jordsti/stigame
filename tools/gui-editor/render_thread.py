__author__ = 'JordSti'
from PyQt4 import QtCore


class render_thread(QtCore.QThread):
    completed = QtCore.pyqtSignal(object)

    def __init__(self, viewport, delay=5000):
        QtCore.QThread.__init__(self)
        self.viewport = viewport
        self.delay = delay
        self.__run = True
        self.__force_draw = False
        self.tmp_file = "viewport.bmp"

        self.__pending_items = []

    def add_item(self, guiitem):
        self.__pending_items.append(guiitem)

    def ask_to_stop(self):
        self.__run = False

    def __draw(self):
        sur = self.viewport.render()
        sur.save_bmp(self.tmp_file)
        data = self.read_file()
        self.completed.emit(data)


    def read_file(self):

        fp = open(self.tmp_file, 'rb')

        chunk = fp.read(1024)
        data = chunk

        while len(chunk) == 1024:
            chunk = fp.read(1024)
            data += chunk

        fp.close()

        return data

    def run(self):
        while self.__run:
            for i in self.__pending_items:
                self.viewport.current.add(i)

            self.__pending_items = []

            if self.__force_draw:
                self.__force_draw = False

            self.__draw()

            delay = self.delay
            ac_time = 0

            while ac_time < delay:
                if self.__force_draw:
                    break
                self.msleep(5)
                ac_time += 5

    def force_draw(self):
        self.__force_draw = True
