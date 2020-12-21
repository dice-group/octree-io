cmake_minimum_required(VERSION 3.17)
project(octree_io)

set(CMAKE_CXX_STANDARD 20)

add_library(octree_io SHARED src/kn-tree-io/structure/kn_tree.cpp src/kn-tree-io/structure/kn_tree.h src/kn-tree-io/io/writer.cpp src/kn-tree-io/io/writer.h src/kn-tree-io/io/reader.cpp src/kn-tree-io/io/reader.h src/kn-tree-io/io/byte_buffer.cpp src/kn-tree-io/io/byte_buffer.h src/kn-tree-io/structure/path.cpp src/kn-tree-io/structure/path.h)