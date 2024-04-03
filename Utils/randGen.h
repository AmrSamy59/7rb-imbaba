#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class randGen
{
private:

public:
	randGen(string input_file = "input_data.txt");
	int randInt(); // generate random int from 0 to 100
};

