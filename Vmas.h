//
// Created by Rimmy Aulakh on 7/19/21.
//

#ifndef VMM_VMAS_H
#define VMM_VMAS_H


class Vmas {
public:
    int startVpage, endVpage, writeProtected, fileMapped;
};


#endif //VMM_VMAS_H
