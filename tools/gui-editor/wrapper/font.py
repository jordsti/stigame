__author__ = 'JordSti'
import object_wrap


class font(object_wrap.object_wrap):

    def __init__(self, obj=None, font_path=None, font_size=None):

        if obj is not None:
            object_wrap.object_wrap.__init__(self, obj)
        elif font_path is not None and font_size is not None:
            object_wrap.object_wrap.__init__(self)
            self.obj = self.lib.Font_new(font_path, font_size)

        self.__font_size = font_size
        self.__font_path = font_path

    def get_size(self):
        return self.__font_size

    def get_path(self):
        return self.__font_path

    def get_font_style(self):
        return self.lib.Font_getFontStyle(self.obj)

    def set_font_style(self, style):
        self.lib.Font_setFontStyle(self.obj, style)