#include "Balle.h"
#include "Plateforme.h"
#include "Brick.h"
#define NOMBER_OF_BRICKS 90

class GameLogic
{
private:
    char UI [RESOLUTION_X] [RESOLUTION_Y];
    Balle ball;
    Plateforme pl;
    Brick *bricks;
    char keyboardValue;
	bool gameOver = 0;
    
public:
    GameLogic();
    void ClearUI();
    void CheckCollision(); bool PlateformCollision(); bool BrickCollision();
    void Input();
    void InitialiseBricks();
    void UpdateBall();
    bool UpdateAll();
    void PrintUI();
    bool Is_GameOver() {return gameOver;};
    char Get_Value() {return keyboardValue;};

};