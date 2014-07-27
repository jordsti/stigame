__author__ = 'JordSti'


class resource:

    def __init__(self, name, data):
        self.name = name
        self.data = data

    def length(self):
        return len(self.data)