example_apps = {
    'rasterizers': { 'sources': ['rasterizers.cpp'], },
    'rasterizers2': { 'sources': ['rasterizers2.cpp'], },
    'lion': { 'sources': ['lion.cpp', 'parse_lion.cpp'], },
    'conv_stroke': { 'sources': ['conv_stroke.cpp'], },
    'mol_view': { 'sources': ['mol_view.cpp'], },
}

foreach name, args : example_apps
    executable(name, args['sources'],
           include_directories: agg_includes, dependencies: agg_deps,
           link_with: [libagg, libplatform],
           gui_app: true, install: true)
endforeach
