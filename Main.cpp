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
    // //  //\\   ||\\  || \\  //   sound over 
   //-//  //__\\  || \\ ||  \\//    string v = "War-strated.wav ";
  // //  //    \\ ||  \\||   ||     PlaySoundA(v.c_str(), NULL, SND_FILENAME);
 
    /////////////////////SCRIPT TESTING RANDGEN///////////////////////////
    
  

    char game_mode;
    cout << "Enter Game Mode (i for interactive, s for silent): ";
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

        while (gPtr->GetCurrentTimeStep() < 40 || gPtr->checkGameStatus() == 0) {
            gPtr->NextTimeStep();
            if (game_mode == 'i') {
                cout << "Press Enter to continue..." << endl;
                string s;
                getline(cin, s);
            }
        }

        int game_status = gPtr->checkGameStatus();

        //In Silent Don't print this
        if (game_status == 1) {
            cout << endl << "Earth Army Won" << endl;
        }
        else if (game_status == -1) {
            cout << endl << "Aliens Army Won" << endl;
        }
        else if (game_status == 2) {
            cout << endl << "TIE" << endl;
        }

        if (game_mode == 's')
            cout << "Simulation ends, Output file is created" << endl;

        delete gPtr;
        cin >> game_mode;  //For Testing 
    }

}
