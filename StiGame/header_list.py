#!/usr/bin/python
import os

def inner_dir(parent, dirname):
	if parent is not None:
		full = os.path.join(parent, dirname)
	else:
		full = dirname

	for f in os.listdir(full):
		fp = os.path.join(full, f)
		if os.path.isfile(fp):
			if f.endswith('.h'):
				print fp
		else:
			inner_dir(full, f)


if __name__ == '__main__':
	print "StiGame Header List, for Doxygen Doc Review"
	print "-------------------------------------------"
	inner_dir(None, "./")
