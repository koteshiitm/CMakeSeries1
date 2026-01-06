cmake_minimum_required(VERSION 3.14) 

project(Dependencies) 

#These two lines for testing
enable_testing()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

#These two lines for set up C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(rooster main.cpp) 
target_link_libraries(rooster PRIVATE calculator)

add_subdirectory(test)