__author__ = 'JordSti'
import ctypes
import os


class sprite_header(ctypes.Structure):
    _fields_ = [('sprite_name', ctypes.c_char * 64),
        ('nb_frames', ctypes.c_int32),
        ('width', ctypes.c_int32),
        ('height', ctypes.c_int32)]

class sprite_image_marker(ctypes.Structure):
    _fields_ = [('length', ctypes.c_int32)]

class sprite_frame:

    def __init__(self, img_data=None):
        self.img_data = img_data

    def length(self):
        return len(self.img_data)

class sprite:
    (FileExtension) = '.bspr'
    (VarFileExtension) = '.spr'

    def __init__(self, sprite_path=None):
        self.path = sprite_path
        self.name = ""
        self.nb_frames = 0
        self.width = 0
        self.height = 0
        self.frames = []

        if self.path is not None:
            self.__read_file()

    def from_var_file(self, var_file):

        prefix = "sprite"
        i = 0
        names = var_file.get_vars_name()

        while True:
            vname = "%s%d" % (prefix, i)

            if vname in names:
                #loading image
                #todo fix assets path
                fpath = os.path.join(os.path.dirname(var_file.path), "..",var_file.get_var(vname))
                fp = open(fpath, 'rb')
                chunk = fp.read(1024)

                img_data = chunk
                while len(chunk) == 1024:
                    chunk = fp.read(1024)
                    img_data += chunk

                fp.close()

                frame = sprite_frame(img_data)
                self.frames.append(frame)
                self.nb_frames += 1

            else:
                break

            i += 1




    def add_frame(self, frame):
        self.frames.append(frame)
        self.nb_frames += 1

    def __read_file(self):
        fp = open(self.path, 'rb')

        header = sprite_header()

        fp.readinto(header)

        self.name = header.sprite_name
        self.nb_frames = header.nb_frames
        self.width = header.width
        self.height = header.height

        for i in range(self.nb_frames):
            marker = sprite_image_marker()
            fp.readinto(marker)
            frame_length = marker.length
            img_data = fp.read(frame_length)
            frame = sprite_frame(img_data)
            self.frames.append(frame)

        fp.close()

    def write_file(self):
        fp = open(self.path, 'wb')

        header = sprite_header()
        header.sprite_name = self.name
        header.width = self.width
        header.height = self.height
        header.nb_frames = self.nb_frames

        fp.write(header)

        for f in self.frames:
            marker = sprite_image_marker()
            marker.length = f.length()

            fp.write(marker)
            fp.write(f.img_data)


        fp.close()



