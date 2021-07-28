//
// Created by Rimmy Aulakh on 7/23/21.
//

#include "Random.h"

int ofs1=0;
int page1=0, process1=0;

int Random::myrandom(std::vector<int>rfile_, int burst) {
    if (ofs1 == rfile_.size()) {
        ofs1 = 0;
    }
    int value = rfile_.at(ofs1) % burst;
    ofs1++;
    return value;
}

Frame* Random::selectVictimFrame(){
    int rand = myrandom(rfile_,fmanager_->frameTable.size());
    Frame *frame = new Frame();
    page1 = fmanager_->frameTable[rand]->vpage;
    process1=fmanager_->frameTable[rand]->pID;
    fmanager_->frameTable[rand]=frame;
    return fmanager_->frameTable[rand];
}

int Random::pageToMapAgain(){
    return page1;
}

int Random::processToMapAgain(){
    return  process1;
}