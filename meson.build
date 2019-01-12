project('agg', 'c', 'cpp', version: '2.4', default_options : ['cpp_std=c++03'])

agg_deps = []
if host_machine.system() == 'linux'
    agg_deps += dependency('x11')
endif

agg_includes = include_directories('include')

install_subdir('include', install_dir : 'include/agg2', strip_directory : true)

subdir('src')
subdir('examples')
