__author__ = 'JordSti'
from PyQt4 import QtGui, QtCore
from wrapper import *
from render_thread import *

class vp_widget(QtGui.QLabel):

    def __init__(self, parent=None):
        super(vp_widget, self).__init__(parent)
        self.setMinimumSize(400, 400)
        self.__pixmap = QtGui.QPixmap()

        self.viewport = py_viewport(self.width(), self.height())
        self.state = gui_state()

        self.viewport.push(self.state)

        self.renderer = render_thread(self.viewport)

        self.renderer.completed.connect(self.render_completed)
        self.renderer.start()

    def render_completed(self, data):
        self.__pixmap.loadFromData(data)
        self.setPixmap(self.__pixmap)

    def resizeEvent(self, args):
        self.viewport.set_dimension(args.size().width(), args.size().height())
        self.renderer.force_draw()

    def mousePressEvent(self, evt):
        lab = label()
        lab.set_caption("allo")
        lab.set_point(0, 0)
        lab.set_dimension(100, 20)

        btn = button()
        btn.set_caption("button 1")
        btn.set_point(100, 50)
        self.renderer.add_item(lab)
        self.renderer.add_item(btn)

        cb = combo_box()
        cb.add(value_object(1, "Combo Box"))

        cb.set_point(100, 80)

        self.renderer.add_item(cb)

        gl = gui_list()
        gl.set_point(200, 20)
        gl.set_dimension(120, 60)
        gl.add(value_object(1, "Option 1"))
        gl.add(value_object(2, "Option 2"))

        self.renderer.add_item(gl)

        self.renderer.force_draw()
