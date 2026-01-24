cmake_minimum_required(VERSION 4.0)
project(WinDurango.Common VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.1") # used for non-stable versions, otherwise blank

set(CMAKE_CXX_STANDARD 17)

set(FILES
        include/WinDurango.Common/WinDurango.h
        src/WinDurango.cpp
        include/WinDurango.Common/Config.h
)

add_library(WinDurango.Common SHARED ${FILES})
target_include_directories(WinDurango.Common PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_definitions(WinDurango.Common PUBLIC
        WINDURANGO_COMMON_COMPILER_NAME="${CMAKE_CXX_COMPILER_ID}"
        WINDURANGO_COMMON_PLATFORM_NAME="${CMAKE_SYSTEM_NAME}"
        WINDURANGO_COMMON_PLATFORM_ARCH="${CMAKE_SYSTEM_PROCESSOR}"
        WINDURANGO_COMMON_VERSION="${PROJECT_VERSION}${VERSION_SUFFIX}"
        WINDURANGO_COMMON_RC_VERSION=${PROJECT_VERSION_MAJOR},${PROJECT_VERSION_MINOR},${PROJECT_VERSION_PATCH}
)

set_target_properties(WinDurango.Common PROPERTIES LINKER_LANGUAGE CXX)