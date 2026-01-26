cmake_minimum_required(VERSION 4.0)
project(WinDurango.KernelX VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.1") # used for non-stable versions, otherwise blank
set(CMAKE_CXX_STANDARD 20)

set(FILES
    src/kernelx.cpp
    include/WinDurango.KernelX/kernelx.h
    include/WinDurango.KernelX/Logan.h
)

add_library(WinDurango.KernelX SHARED ${FILES})

target_link_libraries(WinDurango.KernelX PRIVATE WinDurango.Common)

target_include_directories(WinDurango.KernelX PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/WinDurango.KernelX/
    ../WinDurango.Common/include/
)

set_target_properties(WinDurango.KernelX PROPERTIES
    OUTPUT_NAME "kernelx"
)