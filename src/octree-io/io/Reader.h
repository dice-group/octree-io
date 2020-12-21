//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_READER_H
#define OCTREE_IO_READER_H

#include <istream>

#include "../structure/Octree.h"
#include "ByteBuffer.h"

namespace octree_io{

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
    void read(std::istream& istream, octree_io::Octree &octree, size_t len=0);

    /**
     * Reads an octree from an input stream and save the tree into octree using a byte buffer
     *
     * @param istream The input stream to read from
     * @param octree The structure to save the octree into
     * @param len size of bytes the octree represents
     */
    void buffered_read(std::istream& istream, octree_io::Octree &octree, octree_io::ByteBuffer buffer);

    /**
     * Reads an octree from an input stream and save the tree into octree without buffering.
     *
     * @param istream The input stream to read from
     * @param octree The structure to save the octree into
     */
    void unbuffered_read(std::istream& istream, octree_io::Octree &octree);

    /**
     * Read multiple octress from input stream.
     *
     * If the size of bytes are know, set it, it makes it much faster.
     * The Buffer will then read all bytes in memory and works from these, instead of reading the next x bytes.
     *
     * @param istream The input stream to read from
     * @param octrees The vector to save the octrees into
     * @param len size of bytes the octree represents
     */
    void read(std::istream& istream, std::vector<octree_io::Octree> &octrees, size_t len=0);

    /**
     * Read multiple octress from input stream using a byte buffer.
     *
     * @param istream The input stream to read from
     * @param octrees The vector to save the octrees into
     * @param len size of bytes the octree represents
     */
    void buffered_read(std::istream& istream, std::vector<octree_io::Octree> &octrees, octree_io::ByteBuffer buffer);

    /**
     * Read multiple octress from input stream without buffering.
     *
     *
     * @param istream The input stream to read from
     * @param octrees The vector to save the octrees into
     */
    void unbuffered_read(std::istream& istream, std::vector<octree_io::Octree> &octrees);
}

#endif //OCTREE_IO_READER_H
