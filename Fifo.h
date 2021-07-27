//
// Created by Rimmy Aulakh on 7/22/21.
//

#ifndef VMM_FIFO_H
#define VMM_FIFO_H
#include "Pager.h"

class Fifo: public Pager{
public:
    explicit Fifo(FrameManager* fmanager){
        fmanager_ = fmanager;
    }
    FrameManager* fmanager_;
    Frame* selectVictimFrame();
    int pageToMapAgain();
    int processToMapAgain();
};


#endif //VMM_FIFO_H
