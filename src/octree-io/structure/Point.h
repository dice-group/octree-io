//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_POINT_H
#define OCTREE_IO_POINT_H

#include <cstddef>

namespace octree_io {

    /**
     * 3dim Point
     */
    class Point {
    public:
        /**
         * Constructor using 3 dim values
         * @param x
         * @param y
         * @param z
         */
        Point(size_t x, size_t y, size_t z);

        /**
         * Get the first value (x)
         * @return
         */
        size_t getX();

        /**
         * Get the second value (y)
         * @return
         */
        size_t getY();

        /**
         * Get the third value (z)
         * @return
         */
        size_t getZ();

        /**
         * Checks if this point has the exact values x,y,z
         * @param x
         * @param y
         * @param z
         * @return true if x=x, y=y, z=z, false otherwise
         */
        bool is(size_t x, size_t y, size_t z);
    private:
        size_t x;
        size_t y;
        size_t z;
    };
}

#endif //OCTREE_IO_POINT_H
