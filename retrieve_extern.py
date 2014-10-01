#script to download library and dll needed for stiuniverse
#the purpose is to remove binary from git repository

import zipfile
import os
import urllib2
#hard coded url
url = 'http://sticode.com/~jordsti/stigame_extern_x86.zip'

def download(url , output):

    req = urllib2.Request(url)

    resp = urllib2.urlopen(req)

    fp = open(output, 'wb')

    buf_size = 16384
    
    length = resp.info().getheaders('Content-Length')[0]
    length = int(length)
    current = 0
    print "Starting download"
    chunk = resp.read(buf_size)
    last_prc = None
    i = 0
    while len(chunk) == buf_size:
        current = current + len(chunk)
        prc = (current*100) / length

        if not prc == last_prc:
            prefix = ""
            nb = i / 5
            for x in range(nb):
                prefix = prefix + "="
            i = i + 1
            
            print prefix + "> " + str(prc) + "%"
            last_prc = prc

        fp.write(chunk)

        chunk = resp.read(buf_size)

    fp.write(chunk)
    
    fp.close()
    
    print "Download complete !"

def extract(zipname, dst = None):

    zp = zipfile.ZipFile(zipname, 'r')

    names = zp.namelist()

    for n in names:
        if not n.endswith('/'):
            cdir = os.path.dirname(n)
            if not dst == None:
                cdir = os.path.join(dst, cdir)            
            if not os.path.exists(cdir):
                os.makedirs(cdir)
            print "Extracting : " + n
            if dst == None:
                zp.extract(n)
            else:
                zp.extract(n, dst)

    zp.close()

if __name__ == '__main__':
    download(url, 'stigame_extern_x86.zip')
    extract('stigame_extern_x86.zip')


