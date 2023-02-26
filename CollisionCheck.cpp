#include "GameLogic.h"


bool GameLogic::PlateformCollision()
{
    if (ball.getPos().y == pl.GetPos().y + 1)
	{
		if (ball.getPos().x >= pl.GetPos().x &&
			ball.getPos().x <= pl.GetPos().x + pl.Get_SizeX())
			ball.Collision(HORIZONTAL);
	}
    return true;
}

bool GameLogic::BrickCollision()
{
    bool returnValue = false;
    //Brick frappé par le bas
	for (int i = 0; i < NOMBER_OF_BRICKS; i++)
	{
		if (ball.getPos().y == bricks[i].Get_Pos().y + 1)
		{
			if (ball.getPos().x == bricks[i].Get_Pos().x)
			{
				if (bricks[i].Is_Active())
				{
					bricks[i].Collision();
					ball.Collision(VERTICAL);
                    returnValue = true;
				}
			}
		}
	}
	//Brick frappé par le haut
	for (int i = 0; i < NOMBER_OF_BRICKS; i++)
	{
		if (ball.getPos().y == bricks[i].Get_Pos().y - 1)
		{
			if (ball.getPos().x == bricks[i].Get_Pos().x)
			{
				if (bricks[i].Is_Active())
				{
					bricks[i].Collision();
					ball.Collision(VERTICAL);
                    returnValue = true;
				}
			}
		}
	}
	//Brick frappé par la gauche
	for (int i = 0; i < NOMBER_OF_BRICKS; i++)
	{
		if (ball.getPos().x == bricks[i].Get_Pos().x - 1)
		{
			if (ball.getPos().y == bricks[i].Get_Pos().y)
			{
				if (bricks[i].Is_Active())
				{
					bricks[i].Collision();
					ball.Collision(HORIZONTAL);
                    returnValue = true;
				}
			}
		}
	}
	//Brick frappé par la droite
	for (int i = 0; i < NOMBER_OF_BRICKS; i++)
	{
		if (ball.getPos().x == bricks[i].Get_Pos().x + 1)
		{
			if (ball.getPos().y == bricks[i].Get_Pos().y)
			{
				if (bricks[i].Is_Active())
				{
					bricks[i].Collision();
					ball.Collision(HORIZONTAL);
                    returnValue = true;
				}
			}
		}
	}

    if (!returnValue)
    {
        for (int i = 0; i < NOMBER_OF_BRICKS; i++)
	    {
		    if (ball.getPos().x + ball.getSpeed().x == bricks[i].Get_Pos().x
                && ball.getPos().y + ball.getSpeed().y == bricks[i].Get_Pos().y)
		    {
			    if (bricks[i].Is_Active())
				{
				    bricks[i].Collision();
				    ball.Collision(CORNER);
                    returnValue = true;
				}
			}
		}
	}
    return returnValue;

}


void GameLogic::CheckCollision()
{
	PlateformCollision();

	BrickCollision();
}