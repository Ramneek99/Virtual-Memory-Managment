//
// Created by Rimmy Aulakh on 7/19/21.
//

#ifndef VMM_PAGETABLE_H
#define VMM_PAGETABLE_H

#include <cstdint>

struct pageTable{
    //uint32_t
    unsigned int valid:1;
    unsigned int refrenced:1;
    unsigned int modified:1;
    unsigned int writeProtect:1;
    unsigned int pageDout:1;
    unsigned int noOfFrames:7;
    unsigned int extraBits:20;
};


#endif //VMM_PAGETABLE_H
