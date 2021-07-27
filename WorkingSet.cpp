//
// Created by Rimmy Aulakh on 7/26/21.
//

#include "WorkingSet.h"
Frame* WorkingSet::selectVictimFrame(){
    if(temp5 >= maxFrames){
        temp5=0;
    }
    Frame *frame;
    if(fmanager_->frameTable[temp5] == NULL) {
        frame = new Frame();
        page5 = fmanager_->frameTable[temp5]->vpage;
        process5=fmanager_->frameTable[temp5]->pID;
        fmanager_->frameTable[temp5]=frame;
        temp5++;
        return fmanager_->frameTable[temp5];
    } else{
        page5 = fmanager_->frameTable[temp5]->vpage;
        process5=fmanager_->frameTable[temp5]->pID;
        frame = fmanager_->frameTable[temp5];
        temp5++;
        return frame;
    }
}

int WorkingSet::pageToMapAgain(){
    return page5;
}

int WorkingSet::processToMapAgain(){
    return process5;
}