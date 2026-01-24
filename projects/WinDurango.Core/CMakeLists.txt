cmake_minimum_required(VERSION 4.0)
project(WinDurango.Core VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.0") # used for non-stable versions, otherwise blank

set(CMAKE_CXX_STANDARD 17)

set(FILES
    include/WinDurango.Core/Core.h
)

add_library(WinDurango.Core SHARED ${FILES})
target_include_directories(WinDurango.Core PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(WinDurango.Core PUBLIC WinDurango.Common WinDurango.Kernel)

target_compile_definitions(WinDurango.Core PUBLIC
        WINDURANGO_CORE_COMPILER_NAME="${CMAKE_CXX_COMPILER_ID}"
        WINDURANGO_CORE_PLATFORM_NAME="${CMAKE_SYSTEM_NAME}"
        WINDURANGO_CORE_PLATFORM_ARCH="${CMAKE_SYSTEM_PROCESSOR}"
        WINDURANGO_CORE_VERSION="${PROJECT_VERSION}${VERSION_SUFFIX}"
        WINDURANGO_CORE_RC_VERSION=${PROJECT_VERSION_MAJOR},${PROJECT_VERSION_MINOR},${PROJECT_VERSION_PATCH}
)

set_target_properties(WinDurango.Core PROPERTIES LINKER_LANGUAGE CXX)