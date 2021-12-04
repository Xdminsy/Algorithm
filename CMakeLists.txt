cmake_minimum_required(VERSION 3.21)
project(Algorithm VERSION 0.0.1)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

list(APPEND libs compiler_flags)

# find all source files
file(GLOB_RECURSE files
        CONFIGURE_DEPENDS
        RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "*.cpp" "*.c" "*.cxx")

foreach(file ${files})
    if (NOT ${file} MATCHES "^\\.\\.") # Select only files in src folder.
        string(REGEX REPLACE "/" "." name ${file})
        add_executable(${name} "src/${file}")
        target_link_libraries(${name} ${libs})
        message(STATUS "TARGET: ${name} SOURCE: ${file}")
    endif ()
endforeach()