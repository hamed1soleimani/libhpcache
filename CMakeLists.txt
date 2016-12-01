cmake_minimum_required(VERSION 3.5)
project(libhpcache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Cacheable.cpp)

add_library(hpcache-static STATIC ${SOURCE_FILES})
add_library(hpcache SHARED ${SOURCE_FILES})
target_link_libraries(hpcache-static rt)
target_link_libraries(hpcache rt)

add_subdirectory(example)
