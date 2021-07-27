//
// Created by Rimmy Aulakh on 7/20/21.
//

#ifndef VMM_FRAME_H
#define VMM_FRAME_H
#include "list"
#include "vector"

struct Frame{
    int pID;
    int vpage;
    unsigned int ageCounter:32;
    unsigned long tStamp = 0;
};

class FrameManager {
public:
    int maxFrames=16;
    std::list<int> sequencePages;
    Frame* allocateFrameFromFreeList();
    Frame* getFrame();
//    int maxFrames;
//    Frame* frameTable[];
    std::vector<Frame*> frameTable = *new std::vector<Frame*>(maxFrames);
    int framePosition(Frame* frame);
};


#endif //VMM_FRAME_H
