__author__ = 'JordSti'
import item
import c_library


class button(item.item):
    def __init__(self):
        item.item.__init__(self)
        self.obj = self.lib.Button_new()

    def set_caption(self, text):
        self.lib.Button_setCaption(self.obj, text)

    def get_caption(self):
        return c_library.to_str(self.lib.Button_getCaption(self.obj))