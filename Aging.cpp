//
// Created by Rimmy Aulakh on 7/24/21.
//

#include "Aging.h"
#include "Process.h"

//int page5=0, process5=0, temp5=-1;

Frame *Aging::selectVictimFrame() {
    if (temp5 >= fmanager_->frameTable.size()) {
        temp5 = 0;
    }
    Frame *frame;
    page5 = fmanager_->frameTable[temp5]->vpage;
    process5 = fmanager_->frameTable[temp5]->pID;
    frame = fmanager_->frameTable[temp5];
    temp5++;
    return frame;

}

int Aging::pageToMapAgain() {
    return page5;
}

int Aging::processToMapAgain() {
    return process5;
}