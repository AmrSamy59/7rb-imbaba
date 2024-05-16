#include <iostream>
#include"Game.h"
#include<string>


using namespace std;
int main()
{
  
    
  

    char game_mode;
    cout << "Enter Game Mode (i for interactive, s for silent, q to quit): ";
    cin >> game_mode;
    while (game_mode != 'q') {
        cout << endl;
        while (game_mode != 'i' && game_mode != 's') {
            cout << "Please Enter i or s to proceed (i for interactive, s for silent): ";
            cin >> game_mode;
            cout << endl;
        }

        if (game_mode == 's') {
            cout << "Silent Mode" << endl;
            cout << "Simulation Starts..." << endl;
        }
        Game* gPtr = new Game(game_mode);

        gPtr->PlayGame();

        delete gPtr;
        cout << "Enter Game Mode (i for interactive, s for silent, q to quit): ";
        cin >> game_mode;  
    }

}
