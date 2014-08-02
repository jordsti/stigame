__author__ = 'JordSti'
import object_wrap
import c_library

class surface(object_wrap.object_wrap):
    def __init__(self, surface=None):
        object_wrap.object_wrap.__init__(self, None)
        if surface is not None:
            self.obj = surface
        else:
            self.obj = self.lib.Surface_new()

    def save_bmp(self, dest):
        self.lib.Surface_saveBmp(self.obj, dest, len(dest))

    def get_pixels(self):

        pixels = self.lib.Surface_getPixels(self.obj)
        return c_library.to_uchar_array(pixels)

    def get_width(self):
        return self.lib.Surface_getWidth(self.obj)

    def get_height(self):
        return self.lib.Surface_getHeight(self.obj)