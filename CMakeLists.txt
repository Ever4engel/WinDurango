cmake_minimum_required(VERSION 3.30)
project(WinDurango)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(projects/WinDurango.Common)
add_subdirectory(projects/WinDurango.Implementation.WinRT)
add_subdirectory(projects/WinDurango.Implementation.Native)
add_subdirectory(projects/WinDurango.WinRT)
add_subdirectory("etwplus")
add_subdirectory("d3d11.x")
add_subdirectory(projects/WinDurango.Kernel)

add_custom_target(WinDurango ALL DEPENDS
    WinDurango.Common
    WinDurango.Implementation.WinRT
    WinDurango.Implementation.Native
    WinDurango.WinRT
    etwplus
    WinDurango.Kernel
    d3d11_x
)

