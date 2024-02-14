project('krby', 'cpp')


# create the library
lib_inc = include_directories('include')

lib_src = files(
    'src/encoders/hex.cpp',
    'src/encoders/timestamped_hex.cpp',
    'src/decoders/raw.cpp',
    'src/link.cpp',
    'src/sinks/stdout.cpp',
    'src/sources/tcp_client.cpp',
)

lib = library('krby', lib_src, include_directories: lib_inc)

krby_dep = declare_dependency(include_directories: lib_inc, link_with: lib)

# create an executable
exe_src = files(
    'main.cpp'
)

exe = executable('krby', exe_src, dependencies: [krby_dep])
