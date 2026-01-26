cmake_minimum_required(VERSION 3.30)
project(WinDurango.Implementation.WinRT VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.1") # used for non-stable versions, otherwise blank
set(CMAKE_CXX_STANDARD 20)

set(FILES
    include/WinDurango.Implementation.WinRT/Interfaces/Storage/Directory.h
    include/WinDurango.Implementation.WinRT/Interfaces/Storage/File.h
    src/interfaces/Storage/Directory.cpp
    src/interfaces/Storage/File.cpp
)

add_compile_definitions(WDIMPL_API_EXPORTS)

add_library(WinDurango.Implementation.WinRT SHARED ${FILES})
target_include_directories(WinDurango.Implementation.WinRT PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
)

target_link_libraries(WinDurango.Implementation.WinRT PRIVATE WinDurango.Common)

target_compile_definitions(WinDurango.Implementation.WinRT PUBLIC
        WINDURANGO_IMPLEMENTATION_WINRT_COMPILER_NAME="${CMAKE_CXX_COMPILER_ID}"
        WINDURANGO_IMPLEMENTATION_WINRT_PLATFORM_NAME="${CMAKE_SYSTEM_NAME}"
        WINDURANGO_IMPLEMENTATION_WINRT_PLATFORM_ARCH="${CMAKE_SYSTEM_PROCESSOR}"
        WINDURANGO_IMPLEMENTATION_WINRT_VERSION="${PROJECT_VERSION}${VERSION_SUFFIX}"
        WINDURANGO_IMPLEMENTATION_WINRT_RC_VERSION=${PROJECT_VERSION_MAJOR},${PROJECT_VERSION_MINOR},${PROJECT_VERSION_PATCH}
)

set_target_properties(WinDurango.Implementation.WinRT PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(${PROJECT_NAME} PROPERTIES VS_WINDOWS_TARGET_PLATFORM_MIN_VERSION 10.0.18362.0)
target_compile_definitions(WinDurango.Implementation.WinRT PRIVATE _WINRT_DLL WIN32_LEAN_AND_MEAN WINRT_LEAN_AND_MEAN)