cmake_minimum_required(VERSION 3.5)
project(hpcache-example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXAMPLE_SOURCES CacheableFile.cpp Example.cpp)

link_directories(..)
include_directories(..)

add_executable(hpcache-example ${EXAMPLE_SOURCES})
target_link_libraries(hpcache-example hpcache-static)
