__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import sys
from wrapper import *


class vp_widget(QtGui.QLabel):

    def __init__(self, parent=None):
        super(vp_widget, self).__init__(parent)

        self.__pixmap = QtGui.QPixmap()

        self.viewport = py_viewport(self.width(), self.height())
        self.state = gui_state()
        self.viewport.push(self.state)


    def viewport_render(self):

        surface = self.viewport.render()

        img = QtGui.QImage(surface.get_pixels(), surface.get_width(), surface.get_height(), QtGui.QImage.Format_RGB888)
        surface.save_bmp("test.bmp")
        self.__pixmap.fromImage(img)

        self.setPixmap(self.__pixmap)

    def resizeEvent(self, args):
        self.viewport.set_dimension(args.size().width(), args.size().height())

        self.viewport_render()


class main_window(QtGui.QMainWindow):

    def __init__(self):
        super(main_window, self).__init__()

        self.show()
        self.vp = vp_widget(self)

        self.setCentralWidget(self.vp)


if __name__ == '__main__':

    app = QtGui.QApplication(sys.argv)
    main_win = main_window()
    sys.exit(app.exec_())