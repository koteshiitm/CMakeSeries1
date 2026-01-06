cmake_minimum_required(VERSION 3.14) 
project(Dependencies)

#These two lines for set up C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(src)
add_library(calculator STATIC src/calculator.cpp)

# creating rooster executable
add_executable(rooster src/main.cpp) 
target_link_libraries(rooster PRIVATE calculator)


#=================================================
# test setup
#=================================================
#download googletest 
#add_subdirectory(test)
include(test/AddCatch2.cmake)

#These two lines for testing ?? without this i am able to do
# 1. Enable the testing infrastructure
enable_testing()  #Low-level command. Just turns on the testing feature.
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# 2. Add an executable for your test
# create unit_tests.exe
add_executable(unit_tests test/test_calc.cpp)
target_include_directories(unit_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(unit_tests PRIVATE calculator Catch2::Catch2WithMain)

#High-level module. It calls enable_testing() automatically and adds a BUILD_TESTING option that allows users to turn tests on/off via the command line.
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
