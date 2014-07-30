__author__ = 'JordSti'
import ctypes
import os


class marker(ctypes.Structure):
    _fields_ = [('res_name', ctypes.c_char * 64),
                  ('length', ctypes.c_int32)
                  ]

class resource:
    def __init__(self, name="", data=""):
        self.name = name
        self.data = data

    def length(self):
        return len(self.data)


class resource_file:
    (FileExtension) = ".res"

    def __init__(self, path=None):
        self.path = path
        self.resources = []

        if path is not None:
            self.__load_file()

    def __load_file(self):
        if os.path.exists(self.path):
            fp = open(self.path, 'rb')

            _marker = marker()

            rs = fp.readinto(_marker)

            while rs > 0:

                data = fp.read(_marker.length)
                res = resource(_marker.res_name, data)

                self.resources.append(res)

                rs = fp.readinto(_marker)

            fp.close()

    def write_file(self):
        if self.path is not None:
            fp = open(self.path, 'wb')

            for f in self.resources:
                _marker = marker()
                _marker.res_name = f.name
                _marker.length = f.length()

                fp.write(_marker)
                fp.write(f.data)

            fp.close()
