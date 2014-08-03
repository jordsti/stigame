__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import sys
import vp_widget
import os


class main_window(QtGui.QMainWindow):

    def __init__(self):
        super(main_window, self).__init__()

        self.show()
        self.vp = vp_widget.vp_widget(self)

        self.setCentralWidget(self.vp)

if __name__ == '__main__':

    os.chdir('../../StiGame/bin/Debug')

    import wrapper

    vo = wrapper.value_object(8, "allo")

    print vo.get_id(), vo.get_text()


    app = QtGui.QApplication(sys.argv)
    main_win = main_window()
    sys.exit(app.exec_())
