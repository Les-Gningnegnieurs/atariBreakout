#include "GameLogic.h"


GameLogic::GameLogic()
{
    for (int i = 0; i < RESOLUTION_X - 1; i++)
	{
		for (int j = 0; j < RESOLUTION_Y - 1; j++)
		{
			UI [i] [j] = ' ';
		}
	}
	InitialiseBricks();
}

void GameLogic::ClearUI()
{
	for (int i = 0; i < RESOLUTION_X; i++)
	{
		for (int j = 0; j < RESOLUTION_Y; j++)
		{
			UI [i] [j] = ' ';
		}
	}
}

void GameLogic::InitialiseBricks()
{
	bricks = new Brick[NOMBER_OF_BRICKS];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < RESOLUTION_X; j++)
		{
			Coordonnees pos; pos.x = j; pos.y = i + 3;
			bricks[j + RESOLUTION_X * i].Set_Pos(pos);
		}
	}
}

void GameLogic::Input()
{
	std::cout << "Enter input: w:left e:right q:quit" << std::endl;
	std::cin >> keyboardValue;
	if (keyboardValue == 'w') pl.Move(LEFT);
	if (keyboardValue == 'e') pl.Move(RIGHT);
}



void GameLogic::UpdateBall()
{
	UI [ball.getPos().x] [ball.getPos().y] = 'o';
}

bool GameLogic::UpdateAll()
{
	Input();
	CheckCollision();

    gameOver = !ball.Update();
    int x = ball.getPos().x;
    int y = ball.getPos().y;
    if (UI [x+1] [y] == '-' || UI [x-1] [y] == '-') ball.Collision(HORIZONTAL);
    if (UI [x] [y+1] == '-' || UI [x] [y-1] == '-') ball.Collision(VERTICAL);

	
    ClearUI();

	UpdateBall();

	for (int i = 0; i < NOMBER_OF_BRICKS; i++)
	{
		if (bricks[i].Is_Active())
		{
			UI [bricks[i].Get_Pos().x] [bricks[i].Get_Pos().y] = 'X';
		}
	}


    for (int i = pl.Get_X(); i < pl.Get_X()+pl.Get_SizeX(); i++)
	{
		UI [i] [pl.Get_Y()] = '-';
	}

	return true;
}

void GameLogic::PrintUI()
{
	system("clear"); //LINUX TERMINAL
	for (int j = 0; j < RESOLUTION_Y; j++)
	{
		for (int i = 0; i < RESOLUTION_X; i++)
		{
			std::cout << UI [i] [j];
		}
		std::cout <<std::endl;
	}
}