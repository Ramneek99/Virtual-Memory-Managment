//
// Created by Rimmy Aulakh on 7/18/21.
//

#ifndef VMM_PROCESS_H
#define VMM_PROCESS_H

#include <list>
#include <iostream>
#include "vector"
#include "Vmas.h"
#include "PageTable.h"

class Process {
public:
    int processId, unmaps,maps,ins,outs,fins,fouts,zeros,segvs,segprouts;
    std::list<Vmas*> vmas;
    pageTable pte[64];
};


#endif //VMM_PROCESS_H
