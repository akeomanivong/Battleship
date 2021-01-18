//
// Created by Asia on 3/6/2019.
//

#include "Ship.h"
#ifndef KEOMANIVONGHW4_CRUISER_H
#define KEOMANIVONGHW4_CRUISER_H


class Cruiser : public Ship
{
private:
    const int CRU = 3;

public:
    Cruiser():Ship(){}
    Cruiser(char a, int x, char b):Ship(a, x, b, CRU){}
    int getSize(){return CRU;}
};


#endif //KEOMANIVONGHW4_CRUISER_H
