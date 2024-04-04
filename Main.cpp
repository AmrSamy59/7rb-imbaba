#include <iostream>
#include"Game.h"
#include"../7rb-imbaba/Units/EarthSoldier.h"
using namespace std;
int main()
{
  
   // EarthSoldier s1;
   //// Unit* p;
   // s1.PrintInfo();
    /////////////////////SCRIPT TESTING RANDGEN///////////////////////////
    Game* gPtr = new Game('a');
    gPtr->NextTimeStep();
    delete gPtr;
    cout << "Hello 7rb-imbaba engineers \n";
}
