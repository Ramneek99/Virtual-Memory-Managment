//
// Created by Rimmy Aulakh on 7/21/21.
//

#ifndef VMM_PAGER_H
#define VMM_PAGER_H
#include "Frame.h"

class Pager {
public:
    int page5=0, process5=0, temp5=0;
    virtual Frame* selectVictimFrame()=0;
    virtual int pageToMapAgain()=0;
    virtual int processToMapAgain()=0;
};


#endif //VMM_PAGER_H
