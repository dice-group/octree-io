//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_OCTREE_H
#define OCTREE_IO_OCTREE_H

#include <cstddef>
#include <vector>
#include "Point.h"

namespace octree_io {

    /**
    * Octree structure
    */
    class Octree{
    public:
        /**
         * Adds one 3-dim point to the octree.
         * @param x
         * @param y
         * @param z
         */
        void add(size_t x, size_t y, size_t z);

        /**
         * Get 3dim point at position i
         * @param i position in internal vector
         * @return Point at pos i
         */
        octree_io::Point *get(size_t i);

        /**
         * Gets a 3dim point with values x,y,z if existing,
         * oterhwise a nullptr
         * @param x
         * @param y
         * @param z
         * @return Point(x,y,z) if Octree contains it, nullptr otherwise
         */
        octree_io::Point *get(size_t x, size_t y, size_t z);

        /**
         * Get all Points from the octree
         * @return all points in octree
         */
        std::vector<octree_io::Point> * getPoints();
    private:
        std::vector<octree_io::Point> points{};
    };
}

#endif //OCTREE_IO_OCTREE_H
