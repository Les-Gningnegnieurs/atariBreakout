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
	Canevas();
	friend std::istream& operator>>(std::istream& s, Canevas& can);
	void erase(std::ostream& s);
	void draw(std::ostream &s);
	void update (float ElapsedTime);
	bool Is_GameOver();
	
	

};
