if host_machine.system() == 'windows'
    platform_support_src = ['win32/agg_platform_support.cpp', 'win32/agg_win32_bmp.cpp']
else
    platform_support_src = ['X11/agg_platform_support.cpp']
endif

libaggplatform = static_library('aggplatform', platform_support_src,
    dependencies: agg_deps,
    include_directories: agg_includes,
    link_with: libagg,
    install: true
)

# The 'subdirs' below is needed because the headers are installed inside the 'agg2'
# subdirectory.
pkg.generate(libaggplatform,
    filebase : 'libaggplatform',
    name : 'libaggplatform',
    libraries: libagg,
    subdirs: 'agg2',
    description : 'Anti-grain library platform support',
)
