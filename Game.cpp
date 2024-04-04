#include "Game.h"

Game::Game(char _mode)
{
	earthArmy = new EarthArmy();
	alienArmy = new AlienArmy();
	randGenerator = new randGen("", earthArmy, alienArmy);
	mode = _mode;
	timeStep = 0;
}

void Game::NextTimeStep()
{
	timeStep++;
	randGenerator->generateUnits();
	earthArmy->Attack();
	alienArmy->Attack();
}
