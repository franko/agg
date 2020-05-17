freetype_dep = dependency('freetype2', required: false)

if freetype_dep.found()
    libaggfreetype = static_library('aggfreetype',
        ['agg_font_freetype.cpp'],
        dependencies: [agg_deps, freetype_dep],
        include_directories: agg_includes,
        install: true
    )

    agg_freetype_includes = include_directories('.')

    install_headers('agg_font_freetype.h', install_dir : 'include/agg2')
endif
