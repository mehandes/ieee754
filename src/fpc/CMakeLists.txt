add_library(fpc src/fpc.c)
target_include_directories(fpc PUBLIC src)

# TESTS

add_executable(dp_tests tests/dp_tests.cc)
target_link_libraries(dp_tests fpc gtest_main)
gtest_discover_tests(dp_tests)
add_test(dp_tests dp_tests)

add_executable(sp_tests tests/sp_tests.cc)
target_link_libraries(sp_tests fpc gtest_main)
gtest_discover_tests(sp_tests)
add_test(sp_tests sp_tests)
