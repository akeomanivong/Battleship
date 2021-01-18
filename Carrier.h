//
// Created by Asia on 3/6/2019.
//

#include "Ship.h"
#ifndef KEOMANIVONGHW4_CARRIER_H
#define KEOMANIVONGHW4_CARRIER_H


class Carrier : public Ship
{
private:
    const int CAR = 5;

public:
    Carrier():Ship(){}
    Carrier(char a, int x, char b):Ship(a, x, b, CAR){}
    int getSize(){return CAR;}
    //void sunk(){cout << "Carrier sunk!" << endl;}

};


#endif //KEOMANIVONGHW4_CARRIER_H
