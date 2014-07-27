__author__ = 'JordSti'
import ctypes
import os
import resource


class resource_maker(ctypes.Structure):
    _fields_ = [('name', ctypes.c_char * 32),
                ('length', ctypes.c_int32)]

class resource_file:

    def __init__(self, path=None):
        self.path = path
        self.resources = []
        if self.path is not None and os.path.exists(self.path):
            self.__load_file()

    def __load_file(self):
        fp = open(self.path, 'rb')

        marker = resource_maker()

        rs = fp.readinto(marker)

        while rs > 0:
            data = fp.read(marker.length)
            res = resource.resource(rs.name, data)
            self.resources.append(res)
            rs = fp.readinto(marker)

        fp.close()

    def save_file(self):

        fp = open(self.path, 'wb')

        for r in self.resources:
            marker = resource_maker()
            marker.length = r.length()
            marker.name = r.name
            fp.write(marker)
            fp.write(r.data)

        fp.close()
