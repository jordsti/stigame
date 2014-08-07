__author__ = 'JordSti'
import item


class layout(item.item):

    (LHA_Left, LHA_Center, LHA_Right) = (0, 1, 2)
    (LVA_Top, LVA_Middle, LVA_Bottom) = (0, 1, 2)

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

    def set_vertical_align(self, align):
        self.lib.Layout_setVerticalAlign(self.obj, align)

    def set_horizontal_align(self, align):
        self.lib.Layout_setHorizontalAlign(self.obj, align)

    def get_vertical_align(self):
        return self.lib.Layout_getVerticalAlign(self.obj)

    def get_horizontal_align(self):
        return self.lib.Layout_getHorizontalAlign(self.obj)