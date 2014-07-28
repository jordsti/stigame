__author__ = 'JordSti'
import os


class var_file:

    def __init__(self, path=None):
        self.path = path
        self.__vars_order = []
        self.__vars = {}

        if self.path is not None:
            self.read()

    def read(self):
        if self.path is not None and os.path.exists(self.path):
            fp = open(self.path, 'r')

            lines = fp.readlines()

            fp.close()

            for l in lines:
                self.__parse_line(l)

    def write(self):
        if self.path is not None:
            fp = open(self.path, 'w')

            for n in self.__vars_order:
                line = "%s=%s;\n" % (n, self.__vars[n])
                fp.write(line)

            fp.close()

    def __parse_line(self, line):
        data = line.rstrip('\n')
        data = data.rstrip('\r')
        data = data.rstrip(';')
        data = data.split('=')

        if len(data) == 2:
            self.__vars_order.append(data[0])
            self.__vars[data[0]] = data[1]


    def get_var(self, key):
        return self.__vars[key]

    def get_vars_name(self):
        return self.__vars_order


if __name__ == '__main__':
    vf = var_file('C:\\Users\\JordSti\\git\\stiuniverse-transit\\assets\\sprites\\a0.spr')
    vf.path = "test.txt"
    vf.write()
    for k in vf.get_vars_name():
        print "%s = %s" % (k, vf.get_var(k))
