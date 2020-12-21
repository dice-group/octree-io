//
// Created by minimal on 12/21/20.
//

#include "Reader.h"

void octree_io::read(std::istream& istream, octree_io::Octree &octree, size_t len){
    if(len>0){
        octree_io::ByteBuffer buffer{&istream, len, len};
        buffered_read(istream, octree, buffer);
    }else{
        unbuffered_read(istream, octree);
    }
}

void octree_io::unbuffered_read(std::istream& istream, octree_io::Octree &octree) {
    //TODO steal algorithm from k2
}

void octree_io::buffered_read(std::istream& istream, octree_io::Octree &octree, octree_io::ByteBuffer buffer){
    //TODO steal algorithm from k2
}

void octree_io::read(std::istream& istream, std::vector<octree_io::Octree> &octrees, size_t len){
    if(len>0){
        octree_io::ByteBuffer buffer{&istream, len, len};
        buffered_read(istream, octrees, buffer);
    }else{
        unbuffered_read(istream, octrees);
    }
}

void octree_io::unbuffered_read(std::istream& istream, std::vector<octree_io::Octree> &octrees) {
    //TODO steal algorithm from k2
}

void octree_io::buffered_read(std::istream& istream, std::vector<octree_io::Octree> &octrees, octree_io::ByteBuffer buffer){
    //TODO steal algorithm from k2
}