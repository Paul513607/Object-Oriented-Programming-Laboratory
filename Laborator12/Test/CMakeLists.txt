cmake_minimum_required(VERSION 3.16)

project(Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(sort_test sort_test.cpp)

target_link_libraries(
    sort_test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(sort_test)