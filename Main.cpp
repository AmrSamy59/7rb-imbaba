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

        gPtr->PlayGame(game_mode);

        delete gPtr;
        cin >> game_mode;  //For Testing 
    }

}
