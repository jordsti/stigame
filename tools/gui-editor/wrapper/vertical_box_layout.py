__author__ = 'JordSti'
import layout


class vertical_box_layout(layout.layout):

    def __init__(self):
        layout.layout.__init__(self)
        self.obj = self.lib.VerticalBoxLayout_new()
