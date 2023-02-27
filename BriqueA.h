#ifndef BRIQUEA_H
#define BRIQUEA_H

#include "Brique.h"
/// <summary>
/// ID = A
/// PV = 1
/// </summary>
class BriqueA : public Brique {
public:
	BriqueA(int x = 0, int y = 0, int l = 1, int h = 1);

	~BriqueA();

	void update(float timeElapsed);

	void afficher(std::ostream& s); //pour les testcran
};
#endif
