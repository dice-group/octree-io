//
// Created by minimal on 12/21/20.
//

#include "kn_tree.h"


octree_io::kn_tree::kn_tree(size_t n, size_t noOfPoints) {
    this->dim=n;
    if(noOfPoints!=0) {
        this->points.reserve(noOfPoints);
    }
}

std::vector<std::vector<size_t>> * octree_io::kn_tree::getPoints() {
    return &this->points;
}

std::vector<size_t> *octree_io::kn_tree::get(std::vector<size_t> vec){
    for(std::vector<size_t> &p : points){
        bool is=true;
        for(size_t i=0;i<vec.size();i++) {
            if (p[i]!=vec[i]) {
               is =false;
               break;
            }
        }
        if(is){
            return &p;
        }
    }
    return nullptr;
}

std::vector<size_t> *octree_io::kn_tree::get(size_t i){
    return &points[i];
}

void octree_io::kn_tree::add(std::vector<size_t> vec) {
    points.push_back(vec);
}

u_char octree_io::kn_tree::getN() {
    return dim;
}
