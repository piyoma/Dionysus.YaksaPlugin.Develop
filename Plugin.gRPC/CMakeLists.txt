cmake_minimum_required(VERSION 3.13)

#
#   Project Plugin-RPC 
#   @author 2023/07/18 piyoma
#

project(Plugin-RPC  VERSION 1.0.0 LANGUAGES CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

    # using Visual Studio C++

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

    # using GCC or G++
    add_definitions(-DOS_LINUX=0x02010800)
    
endif()

include(./CMakeModules/common.cmake)

set(FRAMEWORK_INC_DIR "${PROJECT_SOURCE_DIR}/../Metaphysic.Framework")
set(PLUGIN_INC_DIR "${PROJECT_SOURCE_DIR}/../Library.Component/lib_yaksa_plugin/plugin_export")
include_directories("${FRAMEWORK_INC_DIR}" "${PLUGIN_INC_DIR}" "./src" "./")

# Proto file
get_filename_component(rpc_message_proto "./proto3/rpc_message.proto" ABSOLUTE)
get_filename_component(rpc_message_proto_path "${rpc_message_proto}" PATH)

# Generated sources
set(rpc_message_proto_srcs "${PROJECT_SOURCE_DIR}/rpc_src/rpc_message.pb.cc")
set(rpc_message_proto_hdrs "${PROJECT_SOURCE_DIR}/rpc_src/rpc_message.pb.h")
set(rpc_message_grpc_srcs "${PROJECT_SOURCE_DIR}/rpc_src/rpc_message.grpc.pb.cc")
set(rpc_message_grpc_hdrs "${PROJECT_SOURCE_DIR}/rpc_src/rpc_message.grpc.pb.h")

add_custom_command(
      OUTPUT "${rpc_message_proto_srcs}" "${rpc_message_proto_hdrs}" "${rpc_message_grpc_srcs}" "${rpc_message_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${PROJECT_SOURCE_DIR}/rpc_src"
        --cpp_out "${PROJECT_SOURCE_DIR}/rpc_src"
        -I "${rpc_message_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${rpc_message_proto}"
      DEPENDS "${rpc_message_proto}")

set(FRAMEWORK_INC_DIR "${PROJECT_SOURCE_DIR}/../Metaphysic.Framework")
set(PLUGIN_INC_DIR "${PROJECT_SOURCE_DIR}/../Library.Component/lib_yaksa_plugin/plugin_export")
include_directories("${FRAMEWORK_INC_DIR}" "${PLUGIN_INC_DIR}" "./src" "./")


posix_setup_compile_environment()

add_library(Plugin.RPC SHARED)

set_target_properties(Plugin.RPC PROPERTIES output_name "Plugin.RPC")

target_compile_features(Plugin.RPC PUBLIC cxx_std_17)

target_sources(Plugin.RPC
PRIVATE
    plugin.export/export.cpp
    src/RPC.Plugin.Client.cpp
    src/gRPC.Message.Client.cpp
    rpc_src/rpc_message.pb.cc
    rpc_src/rpc_message.grpc.pb.cc
)


target_link_libraries(Plugin.RPC
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})