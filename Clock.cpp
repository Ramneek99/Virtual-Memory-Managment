//
// Created by Rimmy Aulakh on 7/23/21.
//

#include "Clock.h"
#include "Process.h"

int page2=0, process2=0, temp=-1;

Frame* Clock::selectVictimFrame(){
    temp++;
    if(temp==maxFrames){
        temp=0;
    }
    Frame *frame;
    if(fmanager_->frameTable[temp]==NULL) {
        frame = new Frame();
        page2 = fmanager_->frameTable[temp]->vpage;
        process2=fmanager_->frameTable[temp]->pID;
        fmanager_->frameTable[temp]=frame;
        return fmanager_->frameTable[temp];
    } else{
        page2 = fmanager_->frameTable[temp]->vpage;
        process2=fmanager_->frameTable[temp]->pID;
        frame = fmanager_->frameTable[temp];
        return frame;
    }
//    std::cout<<" UNMAP "<<fmanager_->frameTable[j]->pID <<":"<< fmanager_->frameTable[j]->vpage<<std::endl;
//    page2 = fmanager_->frameTable[temp]->vpage;
//    process2=fmanager_->frameTable[temp]->pID;
//    fmanager_->frameTable[temp]=frame;
//    return fmanager_->frameTable[temp];
}

int Clock::pageToMapAgain(){
    return page2;
}

int Clock::processToMapAgain(){
    return process2;
}