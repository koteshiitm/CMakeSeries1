cmake_minimum_required(VERSION 3.15) 

project(Rooster) 

#================
#The math library
#================ 
#add_library(libmath STATIC src/math/supermath.cpp) 
#target_include_directories(libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/math/include)
#include(src/math/math.cmake)
add_subdirectory(src/math)

#==================
#The stats library 
#==================
#add_library(libstats STATIC src/stats/stats.cpp)
#target_include_directories(libstats PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/stats/include)
#target_link_libraries(libstats PUBLIC libmath)
#include(src/stats/stats.cmake)
add_subdirectory(src/stats)
#=====================
#The executable target
#====================== 
add_executable(rooster src/main.cpp) 
target_link_libraries(rooster PUBLIC libstats) 