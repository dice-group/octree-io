//
// Created by minimal on 12/21/20.
//

#include "kn_tree.h"


kn_tree_io::kn_tree::kn_tree(size_t n) {
    this->dim=n;
}

std::vector<std::vector<size_t>> * kn_tree_io::kn_tree::getPoints() {
    return &this->points;
}

std::vector<size_t> *kn_tree_io::kn_tree::get(std::vector<size_t> vec){
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

std::vector<size_t> *kn_tree_io::kn_tree::get(size_t i){
    return &points[i];
}

void kn_tree_io::kn_tree::add(std::vector<size_t> vec) {
    points.push_back(vec);
}

u_char kn_tree_io::kn_tree::getN() {
    return dim;
}
