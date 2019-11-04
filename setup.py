from distutils.core import setup, Extension
setup(name = 'moku', version = '1.0',  \
   ext_modules = [Extension('moku', ['arr.c'])])
