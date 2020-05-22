
demo_subpixel_deps = [agg_deps, freetype_dep]
demo_subpixel_cppargs = []
if host_machine.system() == 'windows'
    demo_subpixel_deps += cc.find_library('shcore', required : true)
    # TODO: use instead NTDDI_WINBLUE for windows 8.1
    demo_subpixel_cppargs += '-DNTDDI_VERSION=100859904'
endif

sdl_dep = dependency('sdl2', method: 'config-tool', required: false)

if freetype_dep.found()
    executable('font-render-test',
        ['font-render-test.cpp'],
        include_directories: [agg_includes, agg_freetype_includes],
        dependencies: demo_subpixel_deps,
        cpp_args: demo_subpixel_cppargs,
        link_with: [libagg, libaggfreetype],
    )

    executable('demo-freetype-lcd',
        ['freetype_lcd.cpp'],
        include_directories: [agg_includes, agg_freetype_includes],
        dependencies: demo_subpixel_deps,
        cpp_args: demo_subpixel_cppargs,
        link_with: [libagg, libaggfreetype, libplatform],
        gui_app: true,
        install: true
    )
endif

if sdl_dep.found()
    executable('sdl-demo-freetype-lcd',
        ['freetype_lcd_sdl.cpp'],
        dependencies: [sdl_dep],
    )
endif
