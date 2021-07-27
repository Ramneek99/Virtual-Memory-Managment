//
// Created by Rimmy Aulakh on 7/26/21.
//

#ifndef VMM_WORKINGSET_H
#define VMM_WORKINGSET_H
#include "Pager.h"

class WorkingSet: public Pager{
public:
    explicit WorkingSet(FrameManager* fmanager, int maxFrames){
        fmanager_ = fmanager;
        maxFrames_=maxFrames;
    }
    int maxFrames_;
    FrameManager* fmanager_;
    Frame* selectVictimFrame();
    int pageToMapAgain();
    int processToMapAgain();
};


#endif //VMM_WORKINGSET_H
