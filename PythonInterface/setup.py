import os
import sys
from distutils.core import setup, Extension

IDX = 2
if "build" in sys.argv[1]:
	IDX = 3
	
basedir = (sys.argv[IDX]).strip()
sys.argv.remove(sys.argv[IDX])
print("Attempting install from directory " + basedir + ":")

Bsources = []
Bsources.append('pasLib.cc')

icuda = '/usr/local/cuda/include'
lcuda = '/usr/local/cuda/lib64'

include_pas = os.path.join(basedir, 'pasLib/include')
link_pas = os.path.join(basedir, 'pasLib/lib')

module1 = Extension('pasLib',
					include_dirs = [include_pas, icuda],
                    libraries = ['pas', 'cudadevrt', 'cudart', 'glut', 'GL', 'GLU', 'GLEW'],
                    library_dirs = [link_pas, lcuda],
                    sources = Bsources)

setup (name = 'pasLib',
       version = '1.0',
       description = 'backend library for pas application',
       author = 'Will van Noordt',
       author_email = 'william.vannoordt@eng.ox.ac.uk',
       ext_modules = [module1])
