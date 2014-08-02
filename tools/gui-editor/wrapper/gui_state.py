__author__ = 'JordSti'
import object_wrap


class gui_state(object_wrap.object_wrap):

    def __init__(self):
        object_wrap.object_wrap.__init__(self)
        self.obj = self.lib.GuiState_new()

    def add(self, item):
        self.lib.GuiState_add(self.obj, item.obj)

    def on_resize(self, width, height):
        self.lib.GuiState_onResize(self.obj, width, height)

    def render(self):
        return self.lib.GuiState_render(self.obj)