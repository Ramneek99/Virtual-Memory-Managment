//
// Created by Rimmy Aulakh on 7/24/21.
//

#ifndef VMM_NRU_H
#define VMM_NRU_H
#include "Pager.h"

class NRU: public Pager{
public:
    explicit NRU(FrameManager* fmanager, int maxFrames){
        fmanager_ = fmanager;
        maxFrames_=maxFrames;
    }
    int maxFrames_;
    FrameManager* fmanager_;
    Frame* selectVictimFrame();
    int pageToMapAgain();
    int processToMapAgain();
};


#endif //VMM_NRU_H
