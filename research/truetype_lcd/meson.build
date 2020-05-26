demo_subpixel_deps = [agg_deps, freetype_dep]
demo_subpixel_cppargs = []
if host_machine.system() == 'windows'
    demo_subpixel_deps += cc.find_library('shcore', required : true)
    # TODO: use instead NTDDI_WINBLUE for windows 8.1
    demo_subpixel_cppargs += '-DNTDDI_VERSION=100859904'
endif

if freetype_dep.found()
    executable('demo-freetype-lcd',
        ['freetype_lcd.cpp'],
        include_directories: [agg_includes, agg_freetype_includes],
        dependencies: demo_subpixel_deps,
        cpp_args: demo_subpixel_cppargs,
        link_with: [libagg, libaggfreetype, libaggplatform],
        gui_app: true,
        install: true
    )
endif
