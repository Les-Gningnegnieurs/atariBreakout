#include "Extendplatform.h"

void Extendplatform::modifyPlateform(Plateforme& platform, bool reset)
{
	int change = 0;
	if (reset) {
		change = platform.getLenght() / EXTENDFACTOR <= MINSIZE ? MINSIZE : platform.getLenght() / EXTENDFACTOR;
		platform.setLenght(change);
	}
	else 
	{
		change = platform.getLenght() * EXTENDFACTOR >= MAXSIZE ? MAXSIZE : platform.getLenght() * EXTENDFACTOR;
		platform.setLenght(change);
	}
}

Extendplatform::Extendplatform(Position positionDestroyed,  int height , int lenght ) :Powerups( positionDestroyed,    height ,  lenght )
{

}