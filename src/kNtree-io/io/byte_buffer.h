//
// Created by minimal on 12/21/20.
//

#ifndef OCTREE_IO_BYTE_BUFFER_H
#define OCTREE_IO_BYTE_BUFFER_H

#include <istream>
#include <cstddef>
#include <vector>

namespace kn_tree_io {

    /**
     * byte_buffer to make read a bit faster.
     */
    class byte_buffer {
    public:
        /**
         * Constructor
         *
         * @param istream input stream to read from
         * @param len amount of bytes to read from stream in total
         * @param initalSize buffer size
         */
        explicit byte_buffer(std::istream *istream, size_t len, size_t initalSize = 1024);

        /**
         * gets the next length bytes and save them in putIn
         *
         * @param length
         * @param putIn
         */
        void next(size_t length, u_char *putIn);

        /**
         * End of Stream.
         * Be aware that this does not necc. mean that the stream has ended, but merely that the amount of bytes to read are absolved.
         *
         * If len was set to 0 always returns false.
         *
         * @return true if amount of bytes were read and consumed using next, false otherwise.
         */
        bool eos();

    private:
        size_t pointer = 0;
        std::istream *istream;
        size_t len;
        size_t bufferSize;
        size_t count=0;
        std::vector<u_char> buffer;

        void fillBuffer();
    };

}

#endif //OCTREE_IO_BYTE_BUFFER_H
