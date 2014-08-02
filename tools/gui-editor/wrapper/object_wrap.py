__author__ = 'JordSti'
import c_library


class object_wrap(object):

    def __init__(self, obj=None):
        self.obj = obj
        self.lib = c_library.get_lib()