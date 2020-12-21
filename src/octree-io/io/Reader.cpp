//
// Created by minimal on 12/21/20.
//

#include "Reader.h"

void kn_tree_io::read(std::istream& istream, kn_tree_io::kN_tree &octree, size_t len){
    if(len>0){
        kn_tree_io::ByteBuffer buffer{&istream, len, len};
        buffered_read(istream, octree, buffer);
    }else{
        unbuffered_read(istream, octree);
    }
}

void kn_tree_io::unbuffered_read(std::istream& istream, kn_tree_io::kN_tree &octree) {
    //TODO steal algorithm from k2
}

void kn_tree_io::buffered_read(std::istream& istream, kn_tree_io::kN_tree &octree, kn_tree_io::ByteBuffer buffer){
    //TODO steal algorithm from k2
}

void kn_tree_io::read(std::istream& istream, std::vector<kn_tree_io::kN_tree> &octrees, size_t len){
    if(len>0){
        kn_tree_io::ByteBuffer buffer{&istream, len, len};
        buffered_read(istream, octrees, buffer);
    }else{
        unbuffered_read(istream, octrees);
    }
}

void kn_tree_io::unbuffered_read(std::istream& istream, std::vector<kn_tree_io::kN_tree> &octrees) {
    //TODO steal algorithm from k2
}

void kn_tree_io::buffered_read(std::istream& istream, std::vector<kn_tree_io::kN_tree> &octrees, kn_tree_io::ByteBuffer buffer){
    //TODO steal algorithm from k2
}