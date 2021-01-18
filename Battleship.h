//
// Created by Asia on 3/6/2019.
//
#include "Ship.h"
#ifndef KEOMANIVONGHW4_BATTLESHIP_H
#define KEOMANIVONGHW4_BATTLESHIP_H


class Battleship : public Ship
{
private:
    const int BSHIP = 4;

public:
    Battleship():Ship(){}
    Battleship(char a, int x, char b):Ship(a, x, b, BSHIP){}
    int getSize(){return BSHIP;}
};


#endif //KEOMANIVONGHW4_BATTLESHIP_H
