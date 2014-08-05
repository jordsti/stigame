__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
import sys
import vp_widget
import os
import gui_editor_window


if __name__ == '__main__':

    os.chdir('../../StiGame/bin/Debug')

    import wrapper

    vo = wrapper.value_object(8, "allo")

    print vo.get_id(), vo.get_text()


    app = QtGui.QApplication(sys.argv)
    main_win = gui_editor_window.gui_editor_window()
    sys.exit(app.exec_())
