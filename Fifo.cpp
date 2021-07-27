//
// Created by Rimmy Aulakh on 7/22/21.
//

#include "Fifo.h"
#include "iostream"
int j=-1;
int page=0, process=0;

Frame* Fifo::selectVictimFrame(){
    j++;
    if(j==fmanager_->maxFrames){
        j=0;
    }
    Frame *frame = new Frame();
//    std::cout<<" UNMAP "<<fmanager_->frameTable[j]->pID <<":"<< fmanager_->frameTable[j]->vpage<<std::endl;
    page = fmanager_->frameTable[j]->vpage;
    process=fmanager_->frameTable[j]->pID;
    fmanager_->frameTable[j]=frame;
    return fmanager_->frameTable[j];
}

int Fifo::pageToMapAgain(){
    return page;
}

int Fifo::processToMapAgain(){
    return process;
}