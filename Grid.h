//
// Created by Asia on 3/6/2019.
//

#include "Ship.h"
#ifndef KEOMANIVONGHW4_GRID_H
#define KEOMANIVONGHW4_GRID_H


class Grid {
private:
    int myX;
    int myY;

public:
    Grid();
    Grid(int x, int y);
    char arr[10][10];
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void fill();
    void print();
    void place(Ship &s);
    bool shotHit(char a, int b);
    void checkHit(Ship &s);
};

#endif //KEOMANIVONGHW4_GRID_H
