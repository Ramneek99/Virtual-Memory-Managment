//
// Created by Rimmy Aulakh on 7/23/21.
//

#ifndef VMM_RANDOM_H
#define VMM_RANDOM_H
#include "Pager.h"
#include "vector"

class Random: public Pager{
public:
    explicit Random(FrameManager* fmanager, std::vector<int>rfile, int maxFramess){
        fmanager_ = fmanager;
        rfile_=rfile;
        maxFrames_=maxFramess;
    }
    std::vector<int>rfile_;
    FrameManager* fmanager_;
    int maxFrames_;
    int myrandom(std::vector<int>rfile_, int burst);
    Frame* selectVictimFrame();
    int pageToMapAgain();
    int processToMapAgain();
};


#endif //VMM_RANDOM_H
