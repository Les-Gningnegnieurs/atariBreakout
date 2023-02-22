#ifndef BRIQUET_H
#define BRIQUET_H
#include "Brique.h"
/// <summary>
/// ID = A
/// PV = 1
/// </summary>
class BriqueT : public Brique {
public:
	BriqueT(int x = 0, int y = 0, int l = 6, int h = 2);

	~BriqueT();

	void update(float timeElapsed);

	void afficher(std::ostream& s); //pour les testcran
protected:
	Hitbox _posT;
	state _etat;
	int _sizeX;
	int _sizeY;
	int _PV;
	int _PVini;
};
#endif
