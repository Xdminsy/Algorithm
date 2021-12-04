cmake_minimum_required(VERSION 3.21)
project(Algorithm VERSION 0.0.1)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

list(APPEND libs compiler_flags)

file(GLOB files CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
    target_link_libraries(${name} ${libs})
    message(STATUS "Target executable: ${name}")
endforeach()