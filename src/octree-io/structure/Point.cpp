//
// Created by minimal on 12/21/20.
//

#include "Point.h"

octree_io::Point::Point(size_t x, size_t y, size_t z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

size_t octree_io::Point::getX(){
    return this->x;
}

size_t octree_io::Point::getY(){
    return this->y;
}

size_t octree_io::Point::getZ(){
    return this->z;
}

bool octree_io::Point::is(size_t x, size_t y, size_t z){
    if(this->x==x && this->y==y && this->z==z){
        return true;
    }
    return false;
}
