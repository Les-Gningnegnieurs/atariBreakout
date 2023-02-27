#ifndef BRIQUETEST_H
#define BRIQUETEST_H

#include "Brique.h"

//brique de longueur 4, hauteur 1
class Briquetest : public Brique {
public:
	Briquetest(int x = 0, int y = 0, int l = 1, int h = 1, state s = Alive);

	~Briquetest();

	void update(float timeElapsed);
	void afficher(std::ostream& s); //pour les testcran

};
#endif