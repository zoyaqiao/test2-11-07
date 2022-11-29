cmake_minimum_required(VRESION 3.5 FATAL_ERROR)
project(demo1 LANGUAGES CXX)

message("C++ compllier flags: " ${CMAKE_CXX_FLAGS})

# set(sgi_path  /home/chenqiao/data1/11/test2-11-07/SGI-STL/SGI-STL V3.3/*)
# add_library(sgi_static STATIC sgi_path)

# add_executable(demo1 demo1.cpp sgi_static)