cmake_minimum_required(VERSION 4.0)
project(WinDurango.WinRT VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.1") # used for non-stable versions, otherwise blank

set(CMAKE_CXX_STANDARD 20)

set(FILES
    "include/WinDurango.WinRT/stub.h"
)

set(WINRT_USE_CROSS_PLATFORM OFF)

add_library(WinDurango.WinRT SHARED ${FILES})
target_include_directories(WinDurango.WinRT PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(WinDurango.WinRT PUBLIC WinDurango.Common)

set_target_properties(WinDurango.WinRT PROPERTIES
    VS_WINRT_COMPONENT TRUE
    VS_GLOBAL_ROOTNAMESPACE "WinDurango.WinRT"
    OUTPUT_NAME "WinDurango.WinRT"
)

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
set_target_properties(${PROJECT_NAME} PROPERTIES VS_WINDOWS_TARGET_PLATFORM_MIN_VERSION 10.0.18362.0)