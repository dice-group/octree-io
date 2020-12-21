//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_KNTREE_H
#define OCTREE_IO_KNTREE_H

#include <cstddef>
#include <vector>
#include "Point.h"

namespace kn_tree_io {

    /**
    * Octree structure
    */
    class kN_tree{
    public:
        /**
         * Adds one n-dim point to the octree.
         * @param point
         */
        void add(std::vector<size_t> point);

        /**
         * Get ndim point at position i
         * @param i position in internal vector
         * @return Point at pos i
         */
        std::vector<size_t> *get(size_t i);

        /**
         * Gets a ndim point with values x,y,z if existing,
         * oterhwise a nullptr
         * @param x
         * @param y
         * @param z
         * @return Actual Point in kN-tree contains it, nullptr otherwise
         */
        std::vector<size_t> *get(std::vector<size_t> values);

        /**
         * Get all Points from the octree
         * @return all points in octree
         */
        std::vector<std::vector<size_t>> * getPoints();
    private:
        std::vector<std::vector<size_t>> points{};
    };
}

#endif //OCTREE_IO_KNTREE_H
