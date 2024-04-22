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
    
  
  
    Game* gPtr = new Game('a');
    
    for (int i = 0; i < 50; i++)
    {
        
        cout << "\nCurrent Timestep " << i+1 << endl;
        gPtr->NextTimeStepTest();
        cout << "Press Enter to continue..." << endl;
        string s;
        getline(cin, s);
        
    }
    delete gPtr;

    
}
