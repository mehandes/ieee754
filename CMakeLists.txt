cmake_minimum_required(VERSION 3.11)
project(fp_conv LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

include(GoogleTest)

add_subdirectory(extern/googletest)
add_subdirectory(src)
