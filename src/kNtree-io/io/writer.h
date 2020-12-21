//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_WRITER_H
#define OCTREE_IO_WRITER_H

#include <ostream>

#include "../structure/kn_tree.h"

namespace kn_tree_io {
    /**
     * Writes an compressed Octree to an output stream.
     *
     * @param ostream output stream to write the octree to.
     * @param octree the octree to compress and write.
     */
    void write(std::ostream &ostream, kn_tree_io::kn_tree octree);
}
#endif //OCTREE_IO_WRITER_H
