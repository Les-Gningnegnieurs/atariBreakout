#include "Extendplatform.h"

void Extendplatform::modifyPlateform(Plateforme& platform, bool reset)
{
	if (reset)
	
		platform.setLenght(platform.getLenght() /EXTENDFACTOR);
	
	else 
		platform.setLenght(platform.getLenght() * EXTENDFACTOR);
}

Extendplatform::Extendplatform(Position positionDestroyed,  int height , int lenght ) :Powerups( positionDestroyed,    height ,  lenght )
{

}