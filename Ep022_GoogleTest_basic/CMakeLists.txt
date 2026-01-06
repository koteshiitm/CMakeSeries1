cmake_minimum_required(VERSION 3.14) 
project(Dependencies)

#These two lines for set up C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(src)
add_library(calculator STATIC src/calculator.cpp)

# creating rooster executable
add_executable(rooster src/main.cpp) 
target_link_libraries(rooster PUBLIC calculator)


#=================================================
# test setup
#=================================================
#download googletest 
#add_subdirectory(test)
include(test/AddGoogleTest.cmake)

#These two lines for testing ?? without this i am able to do
# 1. Enable the testing infrastructure
enable_testing()  #Low-level command. Just turns on the testing feature.
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# 2. Add an executable for your test
# create unit_tests.exe
add_executable(unit_tests test/test_calc.cpp)
target_include_directories(unit_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(unit_tests PRIVATE calculator GTest::gtest_main)

#High-level module. It calls enable_testing() automatically and adds a BUILD_TESTING option that allows users to turn tests on/off via the command line.
include(GoogleTest)
#gtest_discover_tests() is a high-level command used to integrate GoogleTest with CTest.
#When you use the standard add_test() command, CTest sees your entire test executable as one single test. If one assertion fails, the whole "test" fails.
#gtest_discover_tests() changes this:
#It waits until your test executable is built.
#It runs the executable with a special flag (--gtest_list_tests).
#It parses that output to find every single test case you wrote.
#It registers each one as a separate test in CTest.
gtest_discover_tests(unit_tests)

#Comparison Table for add_test vs gtest_discover_tests()
#Feature             add_test()                          gtest_discover_tests()
#GranularityRuns     the whole file as 1 test            Each TEST() is a separate entry
#Discovery Method    Manual entry in CMake               Automatic by querying the binary
#Speed               Faster (no extra execution step)    Slightly slower (runs binary once)
#Complexity          Simple, works for any language      Specific to GoogleTest
