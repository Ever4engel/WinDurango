cmake_minimum_required(VERSION 3.30)
project(WinDurango.WinRT VERSION 1.0.0)

set(VERSION_SUFFIX "-dev.1") # used for non-stable versions, otherwise blank

set(CMAKE_CXX_STANDARD 17)

# Partially derived from dazombiekiller's CMake script that we were given permission to use

make_directory(${CMAKE_BINARY_DIR}/WinMetadata)
file(GLOB IDL_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/idl/*.idl")
cmake_path(CONVERT "${IDL_FILES}" TO_NATIVE_PATH_LIST IDL_FILES)

foreach(IDL_FILE ${IDL_FILES})
    execute_process(
        COMMAND midl
            /winrt /h nul /nomidl /x64
            /I "${CMAKE_SOURCE_DIR}/idl"
            /metadata_dir "$ENV{WindowsSdkDir}References\\$ENV{WindowsSdkVersion}Windows.Foundation.FoundationContract\\4.0.0.0"
            /reference "$ENV{WindowsSdkDir}References\\$ENV{WindowsSdkVersion}Windows.Foundation.FoundationContract\\4.0.0.0\\Windows.Foundation.FoundationContract.winmd"
            /reference "$ENV{WindowsSdkDir}References\\$ENV{WindowsSdkVersion}Windows.Foundation.UniversalApiContract\\19.0.0.0\\Windows.Foundation.UniversalApiContract.winmd"
            /out "${CMAKE_BINARY_DIR}\\WinMetadata"
            ${IDL_FILE}
        RESULT_VARIABLE MIDL_RESULT
        ERROR_VARIABLE MIDL_ERROR)
    
    if(NOT MIDL_RESULT EQUAL 0)
        message(FATAL_ERROR "${MIDL_ERROR}")
    endif()
endforeach()

execute_process(
    COMMAND cppwinrt
        -prefix
        -pch .
        -input "${CMAKE_BINARY_DIR}\\WinMetadata"
        -reference sdk
        -component "${CMAKE_CURRENT_SOURCE_DIR}\\Generated Files\\sources"
        -out "${CMAKE_CURRENT_SOURCE_DIR}\\Generated Files")

set(FILES
    "include/WinDurango.WinRT/stub.h"
)

file(GLOB WINRT_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Generated Files/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/Generated Files/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/Generated Files/winrt/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/Generated Files/winrt/*.h")

set(WINRT_USE_CROSS_PLATFORM OFF)

add_library(WinDurango.WinRT SHARED ${FILES} ${WINRT_FILES} WinDurango.WinRT.def)
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
    target_link_libraries(WinDurango.WinRT PUBLIC WinDurango.Implementation.Native)
    target_compile_definitions(WinDurango.WinRT PUBLIC
    WINRT_CROSS_PLATFORM)
else()
    target_link_libraries(WinDurango.WinRT PUBLIC WinDurango.Implementation.WinRT)

    # todo is this still needed?
    find_program(NUGET_EXE NAMES nuget)
    if(NOT NUGET_EXE)
	    message("NUGET.EXE not found.")
	    message(FATAL_ERROR "Please install this executable, and run CMake again.")
    endif()

    execute_process(COMMAND ${NUGET_EXE}
    install "Microsoft.Windows.CppWinRT" -Version 2.0.250303.1 -ExcludeVersion -OutputDirectory ${CMAKE_BINARY_DIR}/packages)
endif()
unset(WINRT_USE_CROSS_PLATFORM CACHE)

set_target_properties(WinDurango.WinRT PROPERTIES LINKER_LANGUAGE CXX)
# todo needed?
#set_target_properties(WinDurango.WinRT PROPERTIES LIBRARY_OUTPUT_NAME "winrt")
#set_target_properties(${PROJECT_NAME} PROPERTIES VS_CPPWINRT true)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_WINDOWS_TARGET_PLATFORM_MIN_VERSION 10.0.18362.0)
target_compile_definitions(WinDurango.WinRT PRIVATE _WINRT_DLL WIN32_LEAN_AND_MEAN WINRT_LEAN_AND_MEAN)
set_target_properties(WinDurango.WinRT PROPERTIES
    OUTPUT_NAME "winrt_x"
)