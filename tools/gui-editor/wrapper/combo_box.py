__author__ = 'JordSti'
import item


class combo_box(item.item):
    def __init__(self):
        item.item.__init__(self)
        self.obj = self.lib.ComboBox_new()

    def add(self, vo):
        self.lib.ComboBox_add(self.obj, vo.obj)