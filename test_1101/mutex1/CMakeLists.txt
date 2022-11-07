CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)
PROJECT(demo1 LANGUAGES CXX)

# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11 -pthread")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11 -pthread")


find_package(Threads)
add_executable(demo1 demo1.cpp)
target_link_libraries(demo1 ${CMAKE_THREAD_LIBS_INIT})