cmake_minimum_required(VERSION 3.17)
project(octree_io)

set(CMAKE_CXX_STANDARD 20)

add_library(octree_io SHARED src/octree-io/structure/kn_tree.cpp src/octree-io/structure/kn_tree.h src/octree-io/io/writer.cpp src/octree-io/io/writer.h src/octree-io/io/reader.cpp src/octree-io/io/reader.h src/octree-io/io/byte_buffer.cpp src/octree-io/io/byte_buffer.h src/octree-io/structure/path.cpp src/octree-io/structure/path.h)