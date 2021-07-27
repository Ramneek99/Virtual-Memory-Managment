//
// Created by Rimmy Aulakh on 7/23/21.
//

#ifndef VMM_CLOCK_H
#define VMM_CLOCK_H
#include "Pager.h"

class Clock: public Pager {
public:
    explicit Clock(FrameManager* fmanager, int maxFrames){
        fmanager_ = fmanager;
        maxFrames_=maxFrames;
    }
    int maxFrames_;
    FrameManager* fmanager_;
    Frame* selectVictimFrame();
    int pageToMapAgain();
    int processToMapAgain();
};


#endif //VMM_CLOCK_H
