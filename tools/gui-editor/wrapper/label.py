__author__ = 'JordSti'
import item
import c_library

class label(item.item):

    def __init__(self):
        item.item.__init__(self)
        self.obj = self.lib.Label_new()

    def set_caption(self, text):
        self.lib.Label_setCaption(self.obj, text)

    def get_caption(self):
        return c_library.to_str(self.lib.Label_getCaption(self.obj))