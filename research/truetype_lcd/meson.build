if freetype_dep.found()
    executable('demo-freetype-lcd',
        ['freetype_lcd.cpp'],
        include_directories: [agg_includes, agg_freetype_includes],
        dependencies: [agg_deps, freetype_dep],
        link_with: [libagg, libaggfreetype, libplatform],
        gui_app: true,
        install: true
    )
endif
