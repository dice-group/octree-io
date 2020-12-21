cmake_minimum_required(VERSION 3.17)
project(octree_io)

set(CMAKE_CXX_STANDARD 20)

add_library(octree_io SHARED src/octree-io/structure/kNTree.cpp src/octree-io/structure/kNTree.h src/octree-io/structure/Point.cpp src/octree-io/structure/Point.h src/octree-io/io/Writer.cpp src/octree-io/io/Writer.h src/octree-io/io/Reader.cpp src/octree-io/io/Reader.h src/octree-io/io/ByteBuffer.cpp src/octree-io/io/ByteBuffer.h)