cmake_minimum_required(VERSION 4.0)
project(WinDurango)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(projects/WinDurango.Common)
add_subdirectory(projects/WinDurango.Implementation.WinRT)
add_subdirectory(projects/WinDurango.WinRT)
add_subdirectory("etwplus")
add_subdirectory("kernelx")

add_custom_target(WinDurango ALL DEPENDS
    WinDurango.Common
    WinDurango.Implementation.WinRT
    WinDurango.WinRT
    etwplus
    kernelx
)

add_subdirectory("d3d11.x")
