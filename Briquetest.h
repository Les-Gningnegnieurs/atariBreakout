#ifndef BRIQUETEST_H
#define BRIQUETEST_H

#include "Brique.h"

//brique de longueur 4, hauteur 1
class Briquetest : public Brique {
public:
	Briquetest(int x = 0, int y = 0, int l = 4, int h = 1);

	~Briquetest();

	void update(float timeElapsed);

	bool increase_Damage();

	void afficher(std::ostream& s); //pour les testcran
protected:
	Hitbox _pos;
	state _etat;
	int _sizeX;
	int _sizeY;
	int _PV;
	int _PVini;
};
#endif