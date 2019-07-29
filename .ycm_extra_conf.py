SOURCE_EXTENSIONS = [ '.cpp', '.cxx', '.cc', '.c', '.m', '.mm' ]
HEADER_EXTENSIONS = [ '.h', '.hxx', '.hpp', '.hh' ]

def Settings( **kwargs ):
  return {
    'flags': [ '-std=c++17', '-xc++', '-isystem', '/usr/bin/../lib/gcc/x86_64-linux-gnu/8/include', '-isystem', '/usr/include/c++/8/', '-I/home/cgunter/.conan/data/sfml/2.5.1/bincrafters/stable/package/16e1603a0e5c05917e5759652681b08781624e9f/include', '-I/home/cgunter/Documents/play/shmup/src/', '-Wno-pragma-once-outside-header'],
  }
