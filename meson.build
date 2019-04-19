project('agg', 'c', 'cpp', version: '2.4-franko1', default_options : ['cpp_std=c++03'])

agg_deps = []
if host_machine.system() == 'linux'
    agg_deps += dependency('x11')
endif

cc = meson.get_compiler('cpp')
libm = cc.find_library('m', required : false)
agg_deps += libm

agg_includes = include_directories('include')

install_subdir('include', install_dir : 'include/agg2', strip_directory : true)

subdir('src')
subdir('examples')
