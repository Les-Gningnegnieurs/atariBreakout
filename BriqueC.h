#ifndef BRIQUEC_H
#define BRIQUEC_H
#include "Brique.h"
/// <summary>
/// ID = C
/// PV = 3
/// </summary>
class BriqueC : public Brique {
public:
	BriqueC(int x = 0, int y = 0, int l = 4, int h = 1);

	~BriqueC();

	void update(float timeElapsed);

	void afficher(std::ostream& s); //pour les testcran
protected:
	Hitbox _posC;
	state _etat;
	int _sizeX;
	int _sizeY;
	int _PV;
	int _PVini;
};

#endif
