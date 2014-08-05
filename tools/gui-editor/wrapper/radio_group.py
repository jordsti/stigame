__author__ = 'JordSti'
import object_wrap


class radio_group(object_wrap.object_wrap):

    def __init__(self, obj=None):
        object_wrap.object_wrap.__init__(self)
        if obj is not None:
            self.obj = obj
        else:
            self.obj = self.lib.RadioGroup_new()

    def add_item(self, item):
        self.lib.RadioGroup_addItem(self.obj, item)

