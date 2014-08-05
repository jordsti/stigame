__author__ = 'JordSti'
import item


class layout(item.item):

    def __init__(self, obj=None):
        item.item.__init__(self, obj)

    def add_child(self, gitem):
        self.lib.Layout_addChild(self.obj, gitem)

    def remove_child(self, gitem):
        self.lib.Layout_removeChild(self.obj, gitem)

    def get_child_at(self, index):
        return self.lib.Layout_getChildAt(self.obj, index)

    def childs_count(self):
        return self.lib.Layout_childsCount(self.obj)