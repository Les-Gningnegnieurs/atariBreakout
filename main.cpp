#include <iostream>
#include "GameLogic.h"

int main()
{
	GameLogic game;
	
	while(game.Get_Value() != 'q' && !game.Is_GameOver())
	{
		game.UpdateAll();
		game.PrintUI();
	}

	return 0;
}

