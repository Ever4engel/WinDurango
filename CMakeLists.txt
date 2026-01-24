cmake_minimum_required(VERSION 4.0)
project(WinDurango)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(projects/WinDurango.Common)
add_subdirectory(projects/WinDurango.Kernel)

add_custom_target(WinDurango ALL DEPENDS
    WinDurango.Common
    WinDurango.Kernel
)
