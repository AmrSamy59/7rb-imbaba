#include <iostream>
#include"Game.h"
#include<string>


using namespace std;
int main()
{
  
    
    cout << endl;
    cout << "\t\t\033[1;31m  ________      __          \033[0m\033[1;36m______              __                __                  \033[0m" << endl;
    cout << "\t\t\033[1;31m /\\_____  \\    /\\ \\       \033[0m\033[1;36m /\\__  _\\            /\\ \\              /\\ \\                 \033[0m" << endl;
    cout << "\t\t\033[1;31m \\/___//'/'_ __\\ \\ \\____  \033[0m\033[1;36m \\/_/\\ \\/     ___ ___\\ \\ \\____     __  \\ \\ \\____     __     \033[0m" << endl;
    cout << "\t\t\033[1;31m     /' /'/\\`'__\\ \\ '__`\\   \033[0m\033[1;36m  \\ \\ \\   /' __` __`\\ \\ '__`\\  /'__`\\ \\ \\ '__`\\  /'__`\\   \033[0m" << endl;
    cout << "\t\t\033[1;31m   /' /'  \\ \\ \\/ \\ \\ \\L\\ \\ \033[0m\033[1;36m    \\_\\ \\__/\\ \\/\\ \\/\\ \\ \\ \\L\\ \\/\\ \\L\\.\\_\\ \\ \\L\\ \\/\\ \\L\\.\\_ \033[0m" << endl;
    cout << "\t\t\033[1;31m  /\\_/     \\ \\_\\  \\ \\_,__/  \033[0m\033[1;36m   /\\_____\\ \\_\\ \\_\\ \\_\\ \\_,__/\\ \\__/.\\_\\\\ \\_,__/\\ \\__/.\\_\\\033[0m" << endl;
    cout << "\t\t\033[1;31m  \\//       \\/_/   \\/___/     \033[0m\033[1;36m \\/_____/\\/_/\\/_/\\/_/\\/___/  \\/__/\\/_/ \\/___/  \\/__/\\/_/\033[0m" << endl << endl << endl;
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
