#ifndef BRIQUEVOID_H
#define BRIQUEVOID_H

#include "Brique.h"
class BriqueVoid : public Brique {
public:
	BriqueVoid(int x = 0, int y = 0, int l = 1, int h = 1);

	~BriqueVoid();

	void update(float timeElapsed);

	void afficher(std::ostream& s); //pour les testcran

};
#endif