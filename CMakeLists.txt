cmake_minimum_required(VERSION 3.11)
project(fp_conv LANGUAGES C CXX)

set(LIB_SRC src/fpc.c)

add_library(fpc ${LIB_SRC})
target_include_directories(fpc PUBLIC ./include)

add_executable(app_main app/main.c)
target_link_libraries(app_main fpc)

enable_testing()
include(GoogleTest)
add_subdirectory(extern/googletest)

add_executable(fpc_sp_test tests/sp_test.cc)
target_link_libraries(fpc_sp_test PUBLIC
    gtest 
    gtest_main 
    fpc
)
gtest_discover_tests(fpc_sp_test)

add_executable(fpc_dp_test tests/dp_test.cc)
target_link_libraries(fpc_dp_test PUBLIC
    gtest 
    gtest_main 
    fpc
)
gtest_discover_tests(fpc_dp_test)
