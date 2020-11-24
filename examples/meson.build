example_apps = {
    'conv_stroke': { 'sources': ['conv_stroke.cpp'], },
    'gouraud': { 'sources': ['gouraud.cpp'], },
    'gouraud_mesh': { 'sources': ['gouraud_mesh.cpp'], },
    'lion': { 'sources': ['lion.cpp', 'parse_lion.cpp'], },
    'mol_view': { 'sources': ['mol_view.cpp'], },
    'pattern_fill': { 'sources': ['pattern_fill.cpp'], },
    'rasterizers': { 'sources': ['rasterizers.cpp'], },
    'rasterizers2': { 'sources': ['rasterizers2.cpp'], },
}

foreach name, args : example_apps
    executable(name, args['sources'],
           include_directories: agg_includes, dependencies: agg_deps,
           link_with: [libagg, libaggplatform],
           gui_app: true, install: true)
endforeach

