#ifndef BRIQUEVOID_H
#define BRIQUEVOID_H

#include "Brique.h"
class BriqueVoid : public Brique {
public:
	BriqueVoid(int x = 0, int y = 0, int l = 6, int h = 2);

	~BriqueVoid();

	void update(float timeElapsed);

	void draw(std::ostream& s);

	void afficher(std::ostream& s); //pour les testcran

};
#endif