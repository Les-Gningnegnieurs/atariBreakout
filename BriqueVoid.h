#ifndef BRIQUEVOID_H
#define BRIQUEVOID_H

#include "Brique.h"
class BriqueVoid : public Brique {
public:
	BriqueVoid(int x = 0, int y = 0, int l = 6, int h = 2);

	~BriqueVoid();

	void update(float timeElapsed);

	void afficher(std::ostream& s); //pour les testcran
protected:
	Hitbox _posBVoid;
	state _etat;
	int _sizeX;
	int _sizeY;
	int _PV;
	int _PVini;
};
#endif