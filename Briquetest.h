#ifndef BRIQUETEST_H
#define BRIQUETEST_H

#include "Brique.h"

//brique de longueur 4, hauteur 1
class Briquetest : public Brique {
	Briquetest(int x, int y, int l, int h);

	~Briquetest();

	bool checkCollision(int x, int y);

	void update(float timeElapsed);

	bool est_Detruite();

	/// @brief
	/// @return Destroyed ou autres
	state getstate();

	/// @brief 
	/// @param l'état à devenir
	/// @return true or false
	bool setPV(state state);

	bool increase_Damage();

	istream& importer(istream& s);

	void afficher(ostream& s) = 0; //pour les testcran
protected:
	Hitbox _pos;
	state _etat;
	int _sizeX;
	int _sizeY;
};
#endif