cmake_minimum_required(VERSION 4.0)
project(WinDurango.WinRT VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.0") # used for non-stable versions, otherwise blank

set(CMAKE_CXX_STANDARD 17)

set(FILES
        "include/WinDurango.WinRT/Storage/AbstractStorage.h"
)

set(WINRT_USE_CROSS_PLATFORM OFF)

add_library(WinDurango.WinRT SHARED ${FILES})
target_include_directories(WinDurango.WinRT PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(WinDurango.WinRT PUBLIC WinDurango.Common)

target_compile_definitions(WinDurango.WinRT PUBLIC
        WINDURANGO_WINRT_COMPILER_NAME="${CMAKE_CXX_COMPILER_ID}"
        WINDURANGO_WINRT_PLATFORM_NAME="${CMAKE_SYSTEM_NAME}"
        WINDURANGO_WINRT_PLATFORM_ARCH="${CMAKE_SYSTEM_PROCESSOR}"
        WINDURANGO_WINRT_VERSION="${PROJECT_VERSION}${VERSION_SUFFIX}"
        WINDURANGO_WINRT_RC_VERSION=${PROJECT_VERSION_MAJOR},${PROJECT_VERSION_MINOR},${PROJECT_VERSION_PATCH}
)

if (WINRT_USE_CROSS_PLATFORM STREQUAL ON)
    target_compile_definitions(WinDurango.WinRT PUBLIC
    WINRT_CROSS_PLATFORM)
endif()
unset(WINRT_USE_CROSS_PLATFORM CACHE)

set_target_properties(WinDurango.WinRT PROPERTIES LINKER_LANGUAGE CXX)
# todo needed?
#set_target_properties(WinDurango.WinRT PROPERTIES LIBRARY_OUTPUT_NAME "winrt")