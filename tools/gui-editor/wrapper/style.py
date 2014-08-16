__author__ = 'JordSti'
import object_wrap
import surface
import color
import font

#todo decorated button method

class style(object_wrap.object_wrap):
    def __init__(self, ptr=None):
        object_wrap.object_wrap(self)
        if ptr is None:
            self.obj = self.lib.Style_new()
        else:
            self.obj = ptr

    def get_foreground(self):
        return color.color(self.lib.Style_getForeground(self.obj))

    def get_background(self):
        return color.color(self.lib.Style_getBackground(self.obj))

    def get_highlight_foreground(self):
        return color.color(self.lib.Style_getHighlightForeground(self.obj))

    def get_highlight_background(self):
        return color.color(self.lib.Style_getHighlightBackground(self.obj))

    def get_droplist_arrow(self):
        return surface.surface(self.lib.Style_getDropListArrow(self.obj))

    def get_up_arrow(self):
        return surface.surface(self.lib.Style_getUpArrow(self.obj))

    def get_down_arrow(self):
        return surface.surface(self.lib.Style_getDownArrow(self.obj))

    def get_checkbox(self):
        return surface.surface(self.lib.Style_getCheckbox(self.obj))

    def get_checkbox_checked(self):
        return surface.surface(self.lib.Style_getCheckboxChecked(self.obj))

    def get_radio(self):
        return surface.surface(self.lib.Style_getRadio(self.obj))

    def get_radio_checked(self):
        return surface.surface(self.lib.Style_getRadioChecked(self.obj))

    def get_normal_font(self):
        return font.font(self.lib.Style_getNormalFont(self.obj))