function(POSIX_SETUP_COMPILE_ENVIRONMENT)

    #
    #   CMake Modules setup include directoried and link libraris path
    #   @author 2023/07/17 piyoma
    #

    add_definitions(-DOS_LINUX=0x02010800)
    add_definitions(-DGLOG_CUSTOM_PREFIX_SUPPORT=0)
    
    set(PROJECT_LINK_DIR "${PROJECT_SOURCE_DIR}/../Library.Component/libbase/build")
    set(PROJECT_LINK_DIR_LIB "${PROJECT_SOURCE_DIR}/../Library.Component/libs")
    set(PROJECT_INC_DIR "${PROJECT_SOURCE_DIR}/../Library.Component/libbase")
    set(FRAMEWORK_INC_DIR "${PROJECT_SOURCE_DIR}/../Metaphysic.Framework")
    set(PLUGIN_INC_DIR "${PROJECT_SOURCE_DIR}/../Library.Component/lib_yaksa_plugin/plugin_export")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -no-pie")

    link_directories("${PROJECT_LINK_DIR}/src")
    link_directories("${PROJECT_LINK_DIR}/third_party/glog/")
    link_directories("${PROJECT_LINK_DIR_LIB}")
    include_directories("${PROJECT_INC_DIR}/src" "./" 
    "${PROJECT_INC_DIR}/build/third_party/glog/" 
    "${PROJECT_INC_DIR}/third_party/glog/src"
    "${FRAMEWORK_INC_DIR}" "${PLUGIN_INC_DIR}"
    )
  
    set(cxx_strict_flags "-Wextra -Wno-unused-parameter -Wno-missing-field-initializers")
    add_cxx_compiler_flag(-Wno-unused-parameter)

    message(STATUS "")
    message(STATUS "******** Summary ********")
    message(STATUS "General:")
    message(STATUS "  CMake version         : ${CMAKE_VERSION}")
    message(STATUS "  CMake command         : ${CMAKE_COMMAND}")
    message(STATUS "  System                : ${CMAKE_SYSTEM_NAME}")
    message(STATUS "  C++ compiler          : ${CMAKE_CXX_COMPILER}")
    message(STATUS "  C++ compiler id       : ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "  C++ compiler version  : ${CMAKE_CXX_COMPILER_VERSION}")
    message(STATUS "  BLAS                  : ${BLAS}")
    message(STATUS "  CXX flags             : ${CMAKE_CXX_FLAGS}")
    message(STATUS "  Build type            : ${CMAKE_BUILD_TYPE}")
    get_directory_property(tmp DIRECTORY ${PROJECT_SOURCE_DIR} COMPILE_DEFINITIONS)
    message(STATUS "  Compile definitions   : ${tmp}")
    message(STATUS "  CMAKE_PREFIX_PATH     : ${CMAKE_PREFIX_PATH}")
    message(STATUS "  CMAKE_INSTALL_PREFIX  : ${CMAKE_INSTALL_PREFIX}")
    message(STATUS "")

endfunction()