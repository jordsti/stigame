__author__ = 'JordSti'
import object_wrap


class color(object_wrap.object_wrap):

    def __init__(self, ptr=None):
        object_wrap.object_wrap(self)
        if ptr is None:
            self.obj = self.lib.Color_new()
        else:
            self.obj = ptr

    def get_rgba(self):
        rgba = [self.lib.Color_getRed(self.obj), self.lib.Color_getGreen(self.obj), self.lib.Color_getBlue(self.obj), self.lib.Color_getAlpha(self.obj)]
        return rgba

    def set_rgba(self, r, g, b, a):
        self.lib.Color_setRGBA(self.obj, r, g, b, a)