#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Ship.h"
#include "Grid.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Cruiser.h"
#include "Carrier.h"
#include "functions.h"
using namespace std;

int main() {
    srand(time(NULL));
    string name;
    char loc1;
    int loc2;
    char comma;
    char pos;
    Carrier carrierPlayer;
    Battleship battleshipPlayer;
    Cruiser cruiserPlayer;
    Submarine submarinePlayer;
    Destroyer destroyerPlayer;
    Grid playerGrid;
    playerGrid.fill();
    ifstream infile("ship_placement2_good.csv");
    if(!infile)
    {
        cout << "unable to open the file";
    }
    else
    {
        while(!infile.eof())
        {
            getline(infile, name,',');

            infile >> loc1;

            infile >> loc2;

            infile >> comma;

            infile >> pos;

            infile.ignore();

            if(name == "Carrier")
            {
                Carrier carrierPlayer(loc1, loc2, pos);
                playerGrid.place(carrierPlayer);
                //cout << "Carrier created" << endl;
            }

            if(name == "Battleship")
            {
                Battleship battleshipPlayer(loc1, loc2, pos);
                playerGrid.place(battleshipPlayer);
                //cout << "Battleship created" << endl;
            }

            if(name == "Cruiser")
            {
                Cruiser cruiserPlayer(loc1, loc2, pos);
                playerGrid.place(cruiserPlayer);
                //cout << "Cruiser created" << endl;
            }

            if(name == "Submarine")
            {
                Submarine submarinePlayer(loc1, loc2, pos);
                playerGrid.place(submarinePlayer);
                //cout << "Submarine created" << endl;
            }

            if(name == "Destroyer")
            {
                Destroyer destroyerPlayer(loc1, loc2, pos);
                playerGrid.place(destroyerPlayer);
                //cout << " Destroyer Created" << endl;
            }
        }
    }

    Grid computerGrid;
    computerGrid.fill();

    Carrier carrierCPU;
    carrierCPU.randomize();

    Cruiser cruiserCPU;
    cruiserCPU.randomize();

    Battleship battleshipCPU;
    battleshipCPU.randomize();

    Submarine submarineCPU;
    submarineCPU.randomize();

    Destroyer destroyerCPU;
    destroyerCPU.randomize();

    computerGrid.place(carrierCPU);
    computerGrid.place(cruiserCPU);
    computerGrid.place(battleshipCPU);
    computerGrid.place(submarineCPU);
    computerGrid.place(destroyerCPU);

    cout << endl << endl;
    playerGrid.print();
   // computerGrid.print();
    bool play = true;
    bool playerWin = false;
    bool computerWin = false;
    Grid playerTracker;
    playerTracker.fill();
    while(play)
    {
        cout << "Player Grid" << endl;
        playerGrid.print();
        cout << "Player tracker" << endl;
        playerTracker.print();
        //cout << "Computer grid" << endl;
        //computerGrid.print();
        cout << "Enter character coordinate or press q to quit: " << endl;
        char choice;
        cin >> choice;
        if(choice == 'q' || choice == 'Q')
        {
            play = false;
        }
        else
        {
            int choice2;
            cout << "Enter integer coordinate: " << endl;
            cin >> choice2;
            int j = convertChar(choice);
            if(computerGrid.shotHit(choice, choice2))
            {
                playerTracker.arr[choice2 - 1][j] = 'X';
                computerGrid.checkHit(carrierCPU);
                computerGrid.checkHit(battleshipCPU);
                computerGrid.checkHit(cruiserCPU);
                computerGrid.checkHit(submarineCPU);
                computerGrid.checkHit(destroyerCPU);
            }
            else
            {
                playerTracker.arr[choice2 - 1][j] = 'O';
                cout << "Miss!" << endl;
            }
        }
        if(carrierCPU.getHit() && battleshipCPU.getHit() && cruiserCPU.getHit() && submarineCPU.getHit() && destroyerCPU.getHit())
        {
            playerWin = true;
            play = false;
        }
    }

    cout << "Player Grid" << endl;
    playerGrid.print();
    cout << "Player tracker" << endl;
    playerTracker.print();
    cout << "Computer grid" << endl;
    computerGrid.print();
    cout << "Game over" << endl;

    if(playerWin)
    {
        cout << "Congratulations, you win!" << endl;
    }

    //computerGrid.print();

    return 0;
}