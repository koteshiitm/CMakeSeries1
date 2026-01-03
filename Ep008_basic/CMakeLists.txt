cmake_minimum_required(VERSION 3.15) 

project(Rooster) 

#================
#The math library
#================ 
add_library(libmath STATIC src/supermath.cpp) 
#target_include_directories(libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
#add_library(libmath STATIC src/maths/supermath.cpp) 
#target_include_directories(libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/maths/include)

#==================
#The stats library 
#==================
add_library(libstats STATIC src/stats.cpp)
#target_include_directories(libstats PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
target_link_libraries(libstats PUBLIC libmath)
#add_library(libstats STATIC src/stats/stats.cpp)
#target_include_directories(libstats PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/stats/include)
#target_link_libraries(libstats PUBLIC libmath)
 
#=====================
#The executable target
#====================== 
add_executable(rooster src/main.cpp) 
target_link_libraries(rooster PUBLIC libstats) 