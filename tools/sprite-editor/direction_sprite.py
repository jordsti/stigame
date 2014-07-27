__author__ = 'JordSti'
import ctypes
import os
import sprite

class direction_sprite_header(ctypes.Structure):
    _fields_ = [('sprite_name', ctypes.c_char * 64),
                ('nb_frames', ctypes.c_int32 * 5),
                ('width', ctypes.c_int32),
                ('height', ctypes.c_int32)
                ]

class marker(ctypes.Structure):
    _fields_ = [('direction', ctypes.c_int32),
                ('length', ctypes.c_int32)
                ]

class sprite_frame:
    def __init__(self, direction, img_data):
        self.direction = direction
        self.img_data = img_data

    def length(self):
        return len(self.img_data)

class direction_sprite:
    (FileExtension) = '.bdspr'
    (Up, Down, Left, Right, Idle) = (1, 2, 4, 8, 16)

    def __init__(self, path=None):
        self.path = path
        self.name = ""
        self.width = 0
        self.height = 0
        self.frames = {}
        self.__init_frames()

        if path is not None:
            self.__load_file()

    def __init_frames(self):
        self.frames[self.Up] = []
        self.frames[self.Down] = []
        self.frames[self.Left] = []
        self.frames[self.Right] = []
        self.frames[self.Idle] = []

    def __load_file(self):

        if os.path.exists(self.path):
            fp = open(self.path, 'rb')

            header = direction_sprite_header()
            fp.readinto(header)

            self.name = header.sprite_name
            self.width = header.width
            self.height = header.height

            _marker = marker()
            rs = fp.readinto(_marker)
            while rs > 0:
                direction = _marker.direction
                length = _marker.length
                data = fp.read(length)
                frame = sprite_frame(direction, data)
                self.frames[direction].append(frame)
                rs = fp.readinto(_marker)


            fp.close()

def get_direction_string(direction):
    if direction == direction_sprite.Up:
        return 'Up'
    elif direction == direction_sprite.Down:
        return 'Down'
    elif direction == direction_sprite.Left:
        return 'Left'
    elif direction == direction_sprite.Right:
        return 'Right'
    elif direction == direction_sprite.Idle:
        return 'Idle'

def get_direction(text):
    if text == 'Up':
        return direction_sprite.Up
    elif text == 'Down':
        return direction_sprite.Down
    elif text == 'Left':
        return direction_sprite.Left
    elif text == 'Right':
        return direction_sprite.Right
    elif text == 'Idle':
        return direction_sprite.Idle