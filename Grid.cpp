//
// Created by Asia on 3/6/2019.
//

#include <cstdlib>
#include "Grid.h"
#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;

Grid::Grid()
{
    myX = 10;
    myY = 10;
}

Grid::Grid(int x, int y)
{
    myX = x;
    myY = y;
}

void Grid::setX(int x){myX = x;}
void Grid::setY(int y){myY = y;}
int Grid::getX(){return myX;}
int Grid::getY(){return myY;}

void Grid:: fill()
{
    for(int i = 0; i < myX; i++)
    {
        for(int j = 0; j < myY; j++)
        {
            arr[i][j] = '-';
        }
    }
}

void Grid::place(Ship &s)
{
    bool valid = true;
    int j;
    do
    {
        valid = true;
        j = convertChar(s.getLoc1());

        if(s.getOrient() == 'V')
        {
                for (int i = s.getLoc2() - 1; i < s.getLoc2() + s.getSize() - 1; i++)
                {
                    if (arr[i][j] == 'O')
                    {
                        valid = false;
                    }
                }
                if(!valid)
                {
                    s.randomize();
                }
        }
        else
        {
            for(int i = j; i < j + s.getSize(); i++)
            {
                if(arr[s.getLoc2() - 1][i] == 'O')
                {
                    valid = false;
                }
            }
            if(!valid)
            {
                s.randomize();
            }
        }
    }while(!valid);

    if(s.getOrient() == 'V')
    {
        for (int i = s.getLoc2() - 1; i < s.getLoc2() + s.getSize() - 1; i++)
        {
            arr[i][j] = 'O';
        }
    }
    else
    {
        for(int i = j; i < j + s.getSize(); i++)
        {
            arr[s.getLoc2() - 1][i] = 'O';
        }
    }
}

bool Grid::shotHit(char a, int b)
{
    int j;
    j = convertChar(a);

    int i = b - 1;

    if(arr[i][j] == 'O' || arr[i][j] == 'X')
    {
        arr[i][j] = 'X';
        return true;
    }
    else
    {
        return false;
    }
}

void Grid::checkHit(Ship &s)
{
    int j;
    j = convertChar(s.getLoc1());

    if(s.getOrient() == 'V')
    {
        for (int i = s.getLoc2() - 1; i < s.getLoc2() + s.getSize() - 1; i++)
        {
            if (arr[i][j] == 'X')
            {
                s.shipHit();
            }
        }
    }
    else
    {
        for(int i = j; i < j + s.getSize(); i++)
        {
            if(arr[s.getLoc2() - 1][i] == 'X')
            {
                s.shipHit();
            }
        }
    }
    if(s.getHit())
    {
        if(s.getOrient() == 'V')
        {
            for (int i = s.getLoc2() - 1; i < s.getLoc2() + s.getSize() - 1; i++)
            {
                arr[i][j] = 'X';
            }
        }
        else
        {
            for(int i = j; i < j + s.getSize(); i++)
            {
                arr[s.getLoc2() - 1][i] = 'X';
            }
        }
        cout << "Ship sunk!" << endl;
    }
}

void Grid::print()
{
    cout << "   A B C D E F G H I J" << endl;
    for(int i = 0; i < myX; i++)
    {
        if(i+1 != 10)
        {
            cout << i + 1 << "  ";
        }
        else
        {
            cout << i +1 << " ";
        }
        for(int j = 0; j < myY; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}