__author__ = 'jordsti'
import item
import c_library


class decorated_button(item.item):
    def __init__(self):
        item.item.__init__(self)
        self.obj = self.lib.DecoratedButton_new()

    def set_caption(self, text):
        self.lib.DecoratedButton_setCaption(self.obj, text)

    def get_caption(self):
        return c_library.to_str(self.lib.DecoratedButton_getCaption(self.obj))