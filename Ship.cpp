//
// Created by Asia on 3/6/2019.
//

#include "Ship.h"
//#include <stdio.h>      /* printf, scanf, puts, NULL */
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

Ship::Ship()
{
    loc1 = '\0';
    loc2 = -1;
    orient = '\0';
    size = -1;
    hit = false;
    message = false;
}

Ship::Ship(char a, int x, char b, int s)
{
    loc1 = a;
    loc2 = x;
    orient = b;
    size = s;
    hit = false;
    message = false;
}

void Ship::randomize()
{
    //srand(time(NULL));
    bool valid = false;
    int i = rand() % 2;
    if(i == 1)
    {
        orient = 'V';
    }
    else
    {
        orient = 'H';
    }

    int j = rand() % 10;

    loc2 = rand() % 10 + 1;

    if(orient == 'V')
    {
        while(!valid)
        {
            if (loc2 + getSize() - 1 <= 9)
            {
                valid = true;
            }
            else
            {
                loc2 = rand() % 10 + 1;
            }
        }
    }
    else
    {
        while(!valid)
        {
            if(j + getSize() <= 9)
            {
                valid = true;
            }
            else
            {
                j = rand() % 10;
            }
        }
    }

    if(j == 0)
    {
        loc1 = 'A';
    }
    if(j == 1)
    {
        loc1 = 'B';
    }
    if(j == 2)
    {
        loc1 = 'C';
    }
    if(j == 3)
    {
        loc1 = 'D';
    }
    if(j == 4)
    {
        loc1 = 'E';
    }
    if(j == 5)
    {
        loc1 = 'F';
    }
    if(j == 6)
    {
        loc1 = 'G';
    }
    if(j == 7)
    {
        loc1 = 'H';
    }
    if(j == 8)
    {
        loc1 = 'I';
    }
    if(j == 9)
    {
        loc1 = 'J';
    }
    cout << getLoc1() << getLoc2() << " " << getOrient() << " " <<  getSize() << endl;
}
