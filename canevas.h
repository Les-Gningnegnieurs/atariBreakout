#include "GameLogic.h"
#define RESOLUTION_X 128
#define RESOLUTION_Y 128


class Canevas
{
private:
	GameLogic _game;
	int _windowResolutionX = RESOLUTION_X;
	int _windowResolutionY = RESOLUTION_Y;
	char userInterface [RESOLUTION_X] [RESOLUTION_Y];

public:
	Canevas(GameLogic in);
	~Canevas();
	friend istream& operator>>(istream& s, Level& l);
	void erase();
	void draw();
	void update (float ElapsedTime);
	bool Is_GameOver();
	
	

};
