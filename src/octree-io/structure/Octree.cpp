//
// Created by minimal on 12/21/20.
//

#include "Octree.h"

std::vector<octree_io::Point> * octree_io::Octree::getPoints() {
    return &this->points;
}

octree_io::Point *octree_io::Octree::get(size_t x, size_t y, size_t z){
    for(Point &p : points){
        if(p.is(x,y,z)){
            return &p;
        }
    }
    return nullptr;
}

octree_io::Point *octree_io::Octree::get(size_t i){
    return &points[i];
}

void octree_io::Octree::add(size_t x, size_t y, size_t z) {
    points.push_back(Point{x,y,z});
}
