__author__ = 'JordSti'
import item


class text_box(item.item):
    def __init__(self):
        item.item.__init__(self)
        self.obj = self.lib.TextBox_new()

    def set_text(self, text):
        self.lib.TextBox_setText(self.obj, text)