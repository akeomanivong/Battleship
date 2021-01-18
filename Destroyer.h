//
// Created by Asia on 3/6/2019.
//

#include "Ship.h"
#ifndef KEOMANIVONGHW4_DESTROYER_H
#define KEOMANIVONGHW4_DESTROYER_H


class Destroyer : public Ship
{
private:
    const int DEST = 2;

public:
    Destroyer():Ship(){}
    Destroyer(char a, int x, char b):Ship(a, x, b, DEST){}
    int getSize(){return DEST;}
};


#endif //KEOMANIVONGHW4_DESTROYER_H
