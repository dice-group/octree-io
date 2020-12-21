//
// Created by minimal on 12/21/20.
//

#include "ByteBuffer.h"

octree_io::ByteBuffer::ByteBuffer(std::istream *stream, size_t length, size_t initalSize){
    this->pointer=0;
    this->bufferSize = initalSize;
    this->buffer = std::vector<u_char>(initalSize);
    this->len=length;
    this->istream=stream;
    fillBuffer();
}

void octree_io::ByteBuffer::fillBuffer() {
    size_t remaining = len-count;
    if(this->bufferSize>remaining){
        this->istream->read((char *)&buffer[0], remaining);
    }else{
        //this->buffer[this->bufferSize];
        this->istream->read((char *)&buffer[0], this->bufferSize);
    }
}


void octree_io::ByteBuffer::next(size_t length, u_char *putIn){
    for(size_t i=0; i<length;i++){
        if(this->pointer>=this->bufferSize){
            fillBuffer();
            this->pointer=0;
        }
        putIn[i]= this->buffer[this->pointer++];
        this->count++;
    }
}

bool octree_io::ByteBuffer::eos(){
    return this->len<=this->count;
}
