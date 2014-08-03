__author__ = 'JordSti'
import item


class gui_list(item.item):

    def __init__(self):
        item.item.__init__(self)
        self.obj = self.lib.List_new()

    def add(self, vo):
        self.lib.List_add(self.obj, vo.obj)