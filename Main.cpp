#include <iostream>
#include"Game.h"
#include"../7rb-imbaba/Units/EarthSoldier.h"
#include<string>
#include<windows.h>
#include<mmsystem.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
int main()
{
  // sound over 
   // string v = "War-strated.wav ";
   //PlaySoundA(v.c_str(), NULL, SND_FILENAME);
   //////////////////////////////////////////
    // EarthSoldier s1;
   //// Unit* p;
   // s1.PrintInfo();
    /////////////////////SCRIPT TESTING RANDGEN///////////////////////////
    
  
  
    Game* gPtr = new Game('a');
   
    for(int i = 0;i<50;i++)
        gPtr->NextTimeStep();

    delete gPtr;

    cout << "\n\nHello 7rb-imbaba engineers \n";
}
