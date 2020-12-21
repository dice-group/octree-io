//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_PATH_H
#define OCTREE_IO_PATH_H

#include <vector>
#include <cstddef>

namespace kn_tree_io {
    class path {
    public:
        path(u_int32_t h, size_t n);

        bool isEmpty(u_int32_t i) const;

        void pop(u_int32_t i);

        std::vector<std::vector<size_t>> &calculatePoints() const;

        std::vector<size_t> & calculatePoint();

        bool hasLast() const;

        void add(u_int32_t i, u_char *newpath);

        size_t addLast(u_int32_t i);

    private:
        std::vector<std::vector<u_char>> paths;
        u_char last = '\00';
        u_int32_t h;
        size_t n=3;
    };
}

#endif //OCTREE_IO_PATH_H
