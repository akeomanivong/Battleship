//
// Created by Asia on 3/6/2019.
//

#ifndef KEOMANIVONGHW4_SHIP_H
#define KEOMANIVONGHW4_SHIP_H
#include <iostream>
using namespace std;

class Ship {
private:
    char loc1;
    int loc2;
    char orient;
    int size;
    bool hit;
    bool message;

public:
    Ship();
    Ship(char a, int x, char b, int s);
    char getLoc1() {return loc1;}
    int getLoc2() {return loc2;}
    char getOrient() {return orient;}
    bool getHit() {return hit;}
    //bool getMessage() {return message;}
    virtual int getSize() {return size;}
    virtual void randomize();
    void shipHit() {hit = true;}

};


#endif //KEOMANIVONGHW4_SHIP_H
