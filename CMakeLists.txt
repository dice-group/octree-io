cmake_minimum_required(VERSION 3.17)
project(octree_io)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fomit-frame-pointer -momit-leaf-frame-pointer")
else ()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fomit-frame-pointer")
endif ()


file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/octree-io/*.cpp")

add_library(octree_io SHARED src/octree-io/structure/kn_tree.cpp src/octree-io/structure/kn_tree.h src/octree-io/io/writer.cpp src/octree-io/io/writer.h src/octree-io/io/reader.cpp src/octree-io/io/reader.h src/octree-io/io/byte_buffer.cpp src/octree-io/io/byte_buffer.h src/octree-io/structure/path.cpp src/octree-io/structure/path.h)