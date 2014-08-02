__author__ = 'JordSti'
import ctypes

lib_stigame = ctypes.cdll.LoadLibrary('./StiGame.dll')

#todo better file finding
lib_init = False



def get_lib():
    global lib_stigame
    global lib_init

    if not lib_init:
        lib_init = True
        lib_stigame.init_sdl()
        lib_stigame.init_ttf()

    return lib_stigame

def to_str(const_chars):
    return ctypes.cast(const_chars, ctypes.c_char_p).value

def to_uchar_array(const_uchars):
    return ctypes.cast(const_uchars, ctypes.c_char_p).value