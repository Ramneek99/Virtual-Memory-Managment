//
// Created by Rimmy Aulakh on 7/24/21.
//

#ifndef VMM_AGING_H
#define VMM_AGING_H
#include "Pager.h"

class Aging: public Pager{
public:
    explicit Aging(FrameManager* fmanager, int maxFrames){
        fmanager_ = fmanager;
        maxFrames_=maxFrames;
    }
    int maxFrames_;
//    int page5=0, process5=0, temp5=-1;
    FrameManager* fmanager_;
    Frame* selectVictimFrame();
    int pageToMapAgain();
    int processToMapAgain();
};


#endif //VMM_AGING_H
