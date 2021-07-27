//
// Created by Rimmy Aulakh on 7/20/21.
//

#ifndef VMM_FRAME_H
#define VMM_FRAME_H
#include "list"
#include "vector"


static int maxFrames;

struct Frame{
    int pID;
    int vpage;
    unsigned int ageCounter:32;
    unsigned long tStamp = 0;
};

class FrameManager {
public:
    std::list<int> sequencePages;
    Frame* allocateFrameFromFreeList();
    Frame* getFrame();
    std::vector<Frame*> frameTable = *new std::vector<Frame*>(maxFrames);
    int framePosition(Frame* frame);
};


#endif //VMM_FRAME_H
