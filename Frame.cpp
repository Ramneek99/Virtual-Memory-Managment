//
// Created by Rimmy Aulakh on 7/20/21.
//

#include "Frame.h"

Frame* FrameManager::allocateFrameFromFreeList(){
    int arrSize = frameTable.size();
    for (int i = 0; i < arrSize+1; i++) {
        if(frameTable[i]== nullptr){
            Frame *frame = new Frame();
            frame->pID=1;
            frame->vpage=1;
            frameTable[i] = frame;
            return frameTable[i];
        }
    }
    return nullptr;
}

Frame* FrameManager::getFrame(){
    Frame *frame;
    if(sequencePages.empty()) {
        frame = FrameManager::allocateFrameFromFreeList();
    } else{
        Frame *tempFrame = new Frame();
        frameTable[sequencePages.front()]= tempFrame;
        frame = frameTable[sequencePages.front()];
        sequencePages.pop_front();
    }
    return frame;
}

int FrameManager::framePosition(Frame *frame){
    int arrSize =frameTable.size();
    for (int i = 0; i < arrSize; i++) {
        if(frameTable[i]== frame){
            return i;
        }
    }
    return -1;
}