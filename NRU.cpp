//
// Created by Rimmy Aulakh on 7/24/21.
//

#include "NRU.h"
#include "Process.h"

//int page4=0, process4=0, temp4=-1;

Frame* NRU::selectVictimFrame(){
    if(temp5 >= fmanager_->maxFrames){
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

int NRU::pageToMapAgain(){
    return page5;
}

int NRU::processToMapAgain(){
    return process5;
}
