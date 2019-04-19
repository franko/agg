pkg = import('pkgconfig')

agg_src = [
'agg_arc.cpp',
'agg_arrowhead.cpp',
'agg_bezier_arc.cpp',
'agg_bspline.cpp',
'agg_curves.cpp',
'agg_vcgen_contour.cpp',
'agg_vcgen_dash.cpp',
'agg_vcgen_markers_term.cpp',
'agg_vcgen_smooth_poly1.cpp',
'agg_vcgen_stroke.cpp',
'agg_vcgen_bspline.cpp',
'agg_gsv_text.cpp',
'agg_image_filters.cpp',
'agg_line_aa_basics.cpp',
'agg_line_profile_aa.cpp',
'agg_rounded_rect.cpp',
'agg_sqrt_tables.cpp',
'agg_embedded_raster_fonts.cpp',
'agg_trans_affine.cpp',
'agg_trans_warp_magnifier.cpp',
'agg_trans_single_path.cpp',
'agg_trans_double_path.cpp',
'agg_vpgen_clip_polygon.cpp',
'agg_vpgen_clip_polyline.cpp',
'agg_vpgen_segmentator.cpp',
'ctrl/agg_cbox_ctrl.cpp',
'ctrl/agg_gamma_ctrl.cpp',
'ctrl/agg_gamma_spline.cpp',
'ctrl/agg_rbox_ctrl.cpp',
'ctrl/agg_slider_ctrl.cpp',
'ctrl/agg_spline_ctrl.cpp',
'ctrl/agg_scale_ctrl.cpp',
'ctrl/agg_polygon_ctrl.cpp',
'ctrl/agg_bezier_ctrl.cpp',
'../gpc/gpc.c'
]

libagg = static_library('agg', agg_src, dependencies: agg_deps, include_directories: agg_includes, install: true)

pkg.generate(libagg,
    filebase : 'libagg',
    name : 'libagg',
    description : 'Anti-grain library',
)

subdir('platform')
