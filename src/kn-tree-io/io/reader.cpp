//
// Created by minimal on 12/21/20.
//

#include <cmath>

#include "reader.h"

void kn_tree_io::read(std::istream& istream, kn_tree_io::kn_tree &kn_tree, size_t len){
    if(len>0){
        kn_tree_io::byte_buffer buffer{&istream, len, len};
        buffered_read(buffer, kn_tree);
    }else{
        unbuffered_read(istream, kn_tree);
    }
}

void kn_tree_io::unbuffered_read(std::istream& istream, kn_tree_io::kn_tree &knTree) {
    kn_tree_io::byte_buffer buffer{&istream, 0, 1};
    buffered_read(buffer, knTree);
}

void kn_tree_io::read(kn_tree_io::byte_buffer &buffer, kn_tree_io::path& p, u_char h, u_char j, u_char k){
    size_t noOfBytes=pow(2, k-3);
    u_char b[noOfBytes];
    for (u_char i = j; i < h*noOfBytes; i += 1) {
        buffer.next(sizeof(u_char), b);
        p.add(i, b);
    }
}

void kn_tree_io::readShift(kn_tree_io::byte_buffer &buffer, kn_tree_io::path& p, u_char h, u_char j){
    u_char k = 0
    if (p.hasLast()) {
        k = p.addLast(j);
        j+=k;

    }
    u_char b[1];

    for (u_char i = j; i < h; i += k*2) {
        buffer.next(sizeof(u_char), b);
        p.add(i, &b[0]);
    }
}

void kn_tree_io::buffered_read(kn_tree_io::byte_buffer &buffer, kn_tree_io::kn_tree &kn_tree){
    u_char h[1];
    buffer.next(1, h);
    bool endOfTree=false;
    //path p{hSize};
    u_char j = 0;
    u_char k = kn_tree.getN();
    do {
        kn_tree_io::path p{h[0], k};
        if(k<=2){
            readShift(buffer, p, h[0], j);
        }
        else{
            read(buffer, p, h[0], j, k);
        }
        for(const std::vector<size_t> &point : p.calculatePoints()){
            kn_tree.add(point);
        }
        j = h[0]-1;
        for (;j>0;j--) {
            p.pop(j - 1);
            if (!p.isEmpty(j - 1)) {
                break;
            }
        }
        if(j<=0){
            endOfTree=true;
        }
    } while (!endOfTree);
}

void kn_tree_io::read(std::istream& istream, std::vector<kn_tree_io::kn_tree> &kn_trees, size_t len, size_t n, bool useBuffered){
    if(useBuffered){
        kn_tree_io::byte_buffer buffer{&istream, len, len};
        buffered_read(istream, kn_trees, buffer, n);
    }else{
        unbuffered_read(istream, kn_trees, len, n);
    }
}

void kn_tree_io::unbuffered_read(std::istream& istream, std::vector<kn_tree_io::kn_tree> &kn_trees, size_t len, size_t n) {
    size_t count=0;
    while(count<len){
        //TODO increase count on how many bytes were read/tree.
        kn_tree_io::kn_tree kn_tree{n};
        unbuffered_read(istream, kn_tree);
        kn_trees.push_back(kn_tree);
    }
}

void kn_tree_io::buffered_read(std::istream& istream, std::vector<kn_tree_io::kn_tree> &kn_trees, kn_tree_io::byte_buffer &buffer, size_t n){
    while(!buffer.eos()){
        kn_tree_io::kn_tree kn_tree{n};
        buffered_read(buffer, kn_tree);
        kn_trees.push_back(kn_tree);
    }
}