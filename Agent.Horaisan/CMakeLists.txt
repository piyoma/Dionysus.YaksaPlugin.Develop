
cmake_minimum_required(VERSION 3.13)

#
#   Project Horaisn-Lakshmi 
#   @author 2023/07/17 piyoma
#

project(Agent.Horaisan-Lakshmi VERSION 1.0.0 LANGUAGES CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

    # using Visual Studio C++
    list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

    # using GCC or G++
    list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")
    
    include(PosixSetupComplileEnvironment)
    include(AddCXXCompilerFlag)
    include(SetupCompileFlags)

endif()

posix_setup_compile_environment()

add_executable(Lakshmi "")
target_compile_features(Lakshmi PUBLIC cxx_std_17)
target_compile_options(Lakshmi PRIVATE ${LIBBASE_COMPILE_FLAGS})

if( CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

    message(STATUS "Configuration:Debug")

    link_directories("${PROJECT_SOURCE_DIR}/../build/Library.Component/lib_yaksa_plugin")

    target_link_libraries(Lakshmi PRIVATE Library.Yaksa.Plugin)
    target_link_libraries(Lakshmi PRIVATE jsoncpp)
else()

    message(STATUS "Configuration:Release")
    target_link_libraries(Lakshmi PRIVATE Library.Yaksa.Plugin)

endif()

target_sources(Lakshmi
PRIVATE
    src/main.cpp
    src/agent/agent.cxx
    src/agent/waitable_event.cc
)

