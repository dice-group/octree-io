//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_READER_H
#define OCTREE_IO_READER_H

#include <istream>

#include "../structure/path.h"
#include "../structure/kn_tree.h"
#include "byte_buffer.h"

namespace kn_tree_io{

    /**
     * Reads an octree from an input stream and save the tree into octree.
     *
     * If the size of bytes are know, set it, it makes it much faster.
     * The Buffer will then read all bytes in memory and works from these, instead of reading the next x bytes.
     *
     * @param istream The input stream to read from
     * @param octree The structure to save the octree into
     * @param len size of bytes the octree represents
     */
    void read(std::istream& istream, kn_tree_io::kn_tree &kn_tree, size_t len=0);

    /**
     * Reads an octree from an input stream and save the tree into octree using a byte buffer
     *
     * @param istream The input stream to read from
     * @param octree The structure to save the octree into
     * @param len size of bytes the octree represents
     */
    void buffered_read(kn_tree_io::byte_buffer &buffer, kn_tree_io::kn_tree &kn_tree);

    /**
     * Reads an octree from an input stream and save the tree into octree without buffering.
     *
     * @param istream The input stream to read from
     * @param octree The structure to save the octree into
     */
    void unbuffered_read(std::istream& istream, kn_tree_io::kn_tree &kn_tree);

    /**
     * Read multiple octress from input stream.
     *
     * If the size of bytes are know, set it, it makes it much faster.
     * The Buffer will then read all bytes in memory and works from these, instead of reading the next x bytes.
     *
     * @param istream The input stream to read from
     * @param octrees The vector to save the octrees into
     * @param len size of bytes the octree represents
     * @param n the N of kN. dimensions of a point represented by a kN tree.
     * @param useBuffered if a buffered way should be used.
     */
    void read(std::istream& istream, std::vector<kn_tree_io::kn_tree> &kn_trees, size_t len, size_t n, bool useBuffered);

    /**
     * Read multiple octress from input stream using a byte buffer.
     *
     * @param istream The input stream to read from
     * @param octrees The vector to save the octrees into
     * @param len size of bytes the octree represents
     * @param n the N of kN. dimensions of a point represented by a kN tree.
     */
    void buffered_read(std::istream& istream, std::vector<kn_tree_io::kn_tree> &kn_trees, kn_tree_io::byte_buffer &buffer, size_t n);

    /**
     * Read multiple octress from input stream without buffering.
     *
     *
     * @param istream The input stream to read from
     * @param octrees The vector to save the octrees into
     * @param len length of bytes of stream to read (usual end of stream)
     * @param n the N of kN. dimensions of a point represented by a kN tree.
     */
    void unbuffered_read(std::istream& istream, std::vector<kn_tree_io::kn_tree> &kn_trees, size_t len, size_t n);




    void read(kn_tree_io::byte_buffer &buffer, kn_tree_io::path& p, u_char h, u_char j, u_char k);
    void readShift(kn_tree_io::byte_buffer &buffer, kn_tree_io::path& p, u_char h, u_char j);

}

#endif //OCTREE_IO_READER_H
