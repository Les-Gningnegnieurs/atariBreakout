#include "GameLogic.h"
#include <stdlib.h>
#define RESOLUTION_X 80
#define RESOLUTION_Y 25


class Canevas
{
private:
	GameLogic _game;
	int _windowResolutionX = RESOLUTION_X;
	int _windowResolutionY = RESOLUTION_Y;

public:
	Canevas();
	friend std::istream& operator>>(std::istream& s, Canevas& can);
	void erase();
	void draw(std::ostream &s);
	void update (Controller& c);
	bool Is_GameOver();
	
	

};
