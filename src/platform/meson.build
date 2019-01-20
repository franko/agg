if host_machine.system() == 'linux'
    platform_support_src = ['X11/agg_platform_support.cpp']
else
    platform_support_src = ['win32/agg_platform_support.cpp', 'win32/agg_win32_bmp.cpp']
endif

libplatform = static_library('platform', platform_support_src,
    dependencies: agg_deps,
    include_directories: agg_includes,
    link_with: libagg,
    install: true
)
