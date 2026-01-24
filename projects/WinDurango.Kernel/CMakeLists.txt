cmake_minimum_required(VERSION 4.0)
project(WinDurango.Kernel VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.0") # used for non-stable versions, otherwise blank

set(CMAKE_CXX_STANDARD 17)

set(FILES
    include/WinDurango.Kernel/Kernel.h
)

add_library(WinDurango.Kernel SHARED ${FILES})
target_include_directories(WinDurango.Kernel PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(WinDurango.Kernel PUBLIC WinDurango.Common)

target_compile_definitions(WinDurango.Kernel PUBLIC
        WINDURANGO_KERNEL_COMPILER_NAME="${CMAKE_CXX_COMPILER_ID}"
        WINDURANGO_KERNEL_PLATFORM_NAME="${CMAKE_SYSTEM_NAME}"
        WINDURANGO_KERNEL_PLATFORM_ARCH="${CMAKE_SYSTEM_PROCESSOR}"
        WINDURANGO_KERNEL_VERSION="${PROJECT_VERSION}${VERSION_SUFFIX}"
        WINDURANGO_KERNEL_RC_VERSION=${PROJECT_VERSION_MAJOR},${PROJECT_VERSION_MINOR},${PROJECT_VERSION_PATCH}
)

set_target_properties(WinDurango.Kernel PROPERTIES LINKER_LANGUAGE CXX)