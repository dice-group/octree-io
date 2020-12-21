//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_WRITER_H
#define OCTREE_IO_WRITER_H

#include <ostream>

#include "../structure/Octree.h"

namespace octree_io {
    /**
     * Writes an compressed Octree to an output stream.
     *
     * @param ostream output stream to write the octree to.
     * @param octree the octree to compress and write.
     */
    void write(std::ostream &ostream, octree_io::Octree octree);
}
#endif //OCTREE_IO_WRITER_H
