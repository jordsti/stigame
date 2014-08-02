__author__ = 'JordSti'
import surface


class py_viewport:

    def __init__(self, width, height):
        self.__width = width
        self.__height = height

        self.current = None

    def push(self, state):
        self.current = state
        state.on_resize(self.__width, self.__height)

    def set_dimension(self, width, height):
        self.__width = width
        self.__height = height

        if self.current is not None:
            self.current.on_resize(self.__width, self.__height)

    def render(self):
        bf = self.current.render()
        return surface.surface(bf)


    def get_dimension(self):
        return self.__width, self.__height