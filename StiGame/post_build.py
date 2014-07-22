import os
import sys
import shutil


exclude_dirs = ['include', 'lib', 'bin', 'StiGame', 'assets']

if __name__ == '__main__':
    mode = 'Debug'

    nb = len(sys.argv)

    i = 0

    while i < nb:
        arg = sys.argv[i]

        if arg == '-m' or arg == '--mode':
            i += 1
            if i < nb:
                mode = sys.argv[i]

        i += 1

    projects = []

    print "StiGame Post Build Script"
    print "Mode : %s" % mode
    print "This is script is copying StiGame.dll into the other projects"

    print "Listing other projects..."

    parent_path = os.path.abspath('..')
    
    files = os.listdir(parent_path)

    for f in files:
        fpath = os.path.join(parent_path, f)

        if os.path.isdir(fpath) and not f in exclude_dirs and not f.startswith('.'):
            projects.append(f)

    for p in projects:
        print "Copying StiGame.dll to [%s]" % p
        project_path = os.path.join(parent_path, p, "bin", mode)

        if not os.path.exists(project_path):
            os.makedirs(project_path)
        
        src_path = os.path.join(os.getcwd(), 'bin', mode, 'StiGame.dll')
        dst_path = os.path.join(project_path, 'StiGame.dll')
        shutil.copyfile(src_path, dst_path)
            
