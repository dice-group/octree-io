//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_KN_TREE_H
#define OCTREE_IO_KN_TREE_H

#include <cstddef>
#include <vector>

namespace octree_io {

    /**
    * Octree structure
    */
    class kn_tree{
    public:

        /**
         * Creates a kN-tree where each Point represented in the tree is of dimension n
         *
         * @param n the dimension of the points represented by the tree
         */
        kn_tree(size_t n);
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

        /**
         * Returns the amount of dimensions of a point represented by the tree.
         * @return dimension, kN
         */
        u_char getN();

    private:
        std::vector<std::vector<size_t>> points{};
        size_t dim;
    };
}

#endif //OCTREE_IO_KN_TREE_H
