//
// Created by Asia on 3/6/2019.
//
#include "Ship.h"
#ifndef KEOMANIVONGHW4_SUBMARINE_H
#define KEOMANIVONGHW4_SUBMARINE_H


class Submarine : public Ship
{
private:
    const int SUB = 3;

public:
    Submarine():Ship(){}
    Submarine(char a, int x, char b):Ship(a, x, b, SUB){}
    int getSize(){return SUB;}
};


#endif //KEOMANIVONGHW4_SUBMARINE_H
