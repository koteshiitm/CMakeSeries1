cmake_minimum_required(VERSION 3.50)
project(helloWorld
        VERSION 0.0.1
        DESCRIPTION "Hello world app"
        LANGUAGES CXX)
add_executable(helloWorldBinary main.cpp)
target_compile_features(helloWorldBinary PRIVATE cxx_std_20)