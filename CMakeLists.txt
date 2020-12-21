cmake_minimum_required(VERSION 3.17)
project(octree_io)

set(CMAKE_CXX_STANDARD 20)

add_library(octree_io SHARED src/kNtree-io/structure/kn_tree.cpp src/kNtree-io/structure/kn_tree.h src/kNtree-io/io/writer.cpp src/kNtree-io/io/writer.h src/kNtree-io/io/reader.cpp src/kNtree-io/io/reader.h src/kNtree-io/io/byte_buffer.cpp src/kNtree-io/io/byte_buffer.h src/kNtree-io/structure/path.cpp src/kNtree-io/structure/path.h)