#include <iostream>
#include"Game.h"
#include<string>
#include<windows.h>
#include<mmsystem.h>
#include<string>
#pragma comment (lib,"winmm.lib")
using namespace std;
int main()
{
  // sound over 
  //  string v = "War-strated.wav ";
  // PlaySoundA(v.c_str(), NULL, SND_FILENAME);
 
    /////////////////////SCRIPT TESTING RANDGEN///////////////////////////
    
  
  
    char game_mode;
    cout << "Enter Game Mode (i for interactive, s for silent): ";
    cin >> game_mode;
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
    
    while (gPtr->GetCurrentTimeStep() <= 40 || gPtr->checkGameStatus() == 0) {
        gPtr->NextTimeStep();
        if (game_mode == 'i') {
            cout << "Press Enter to continue..." << endl;
            string s;
            getline(cin, s);
        }
    }

    int game_status = gPtr->checkGameStatus();

    if (game_mode == 'i') {
        if (game_status == 1) {
            cout << endl << "Earth Army Won";
        }
        else if (game_status == -1) {
            cout << endl << "Aliens Army Won";
        }
        else if (game_status == 2) {
            cout << endl << "TIE";
        }
    }
    
    if (game_mode == 's')
        cout << "Simulation ends, Output file is created";

    delete gPtr;

    
}
