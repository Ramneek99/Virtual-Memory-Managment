//
// Created by Rimmy Aulakh on 7/21/21.
//

#include "Pager.h"
//#include "iostream"
//int j=-1;
//int page=0, process=0;
//
//Frame* Pager::selectVictimFrame(){
//    j++;
//    if(j==maxFrames){
//        j=0;
//    }
//    Frame *frame = new Frame();
//    std::cout<<" UNMAP "<<fmanager_->frameTable[j]->pID <<":"<< fmanager_->frameTable[j]->vpage<<std::endl;
//    frame->pID=1;
//    frame->vpage=1;
//    page = fmanager_->frameTable[j]->vpage;
//    process=fmanager_->frameTable[j]->pID;
//    fmanager_->frameTable[j]=frame;
//    return fmanager_->frameTable[j];
//}
//
//int Pager::pageToMapAgain(){
//    return page;
//}
//
//int Pager::processToMapAgain(){
//    return process;
//}