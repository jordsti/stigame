__author__ = 'JordSti'
import object_wrap
import c_library


class value_object(object_wrap.object_wrap):

    def __init__(self, v_id, text):
        object_wrap.object_wrap.__init__(self)
        self.obj = self.lib.ValueObject_new(v_id, text)

    def get_id(self):
        return self.lib.ValueObject_getId(self.obj)

    def get_text(self):
        return c_library.to_str(self.lib.ValueObject_getText(self.obj))
