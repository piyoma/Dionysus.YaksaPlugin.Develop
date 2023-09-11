cmake_minimum_required(VERSION 3.13)

#
#   Project Plugin-Example 
#   @author 2023/07/18 piyoma
#

project(Plugin-Example  VERSION 1.0.0 LANGUAGES CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

    # using Visual Studio C++

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

    # using GCC or G++
    add_definitions(-DOS_LINUX=0x02010800)

endif()

set(FRAMEWORK_INC_DIR "${PROJECT_SOURCE_DIR}/../Metaphysic.Framework")
set(PLUGIN_INC_DIR "${PROJECT_SOURCE_DIR}/../Library.Component/lib_yaksa_plugin/plugin_export")
include_directories("${FRAMEWORK_INC_DIR}" "${PLUGIN_INC_DIR}" "./src" "./")

posix_setup_compile_environment()

add_library(Plugin.Example SHARED)

set_target_properties(Plugin.Example PROPERTIES output_name "Plugin.Example")

target_compile_features(Plugin.Example PUBLIC cxx_std_17)

target_sources(Plugin.Example
PRIVATE
    plugin.export/export.cpp
    src/Example.Plugin.Client.cpp
)