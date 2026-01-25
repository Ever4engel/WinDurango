add_library(d3d11_x SHARED "d3d11.x.cpp" "d3d11.x.h" "unknown.g.h" "IGraphicsUnknown.h" "IGraphicsUnknown.cpp" "IIDExports.h" "IIDExports.cpp" "Exports.def")

target_link_options(d3d11_x
    PUBLIC 
    $<$<CXX_COMPILER_ID:MSVC>:/FORCE:MULTIPLE>
)
