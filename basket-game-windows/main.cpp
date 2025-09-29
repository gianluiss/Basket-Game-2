#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
   COORD coord;
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
   std::srand(std::time(nullptr));

   Game game;
   game.initializeSky();
   
   const int gameHeight = game.getSkySize()+2; //+2 here includes the Falling money line and score line

   char input = 0;
   while(game.isRunning())
   {
      if(_kbhit())
	 input = getch();

      game.handleInput(input);
      game.update();

      gotoxy(0,0);
      game.render();
      gotoxy(0,gameHeight);
      //system("cls"); //works but screen flickers

      std::cout << "Your Score: " << game.getScore() << "   ";
      Sleep(100);
   }

   gotoxy(0, gameHeight);
   std::cout << "Your Score: " << game.getScore() << '\n';

   if(game.getScore() >= 100)
      std::cout << "Yeah, you win!!\n";
   else if(game.getScore() <= 0)
      std::cout << "Sorry, you lose...\n";
   else
      std::cout << "Error. program ended with invalid score\n";

   return 0;
}
