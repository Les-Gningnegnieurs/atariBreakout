#include "Extendplatform.h"

void Extendplatform::setPowerups(GameLogic& gm)
{
	Plateforme p = gm.getplaform();
	p.setLenght(p.getLenght() * EXTENDFACTOR);
}
void Extendplatform::resetPowerups(GameLogic& gm)
{
	Plateforme p = gm.getplaform();
	p.setLenght(p.getLenght() * (1/EXTENDFACTOR));
}