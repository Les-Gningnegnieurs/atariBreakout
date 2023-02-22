#ifndef BRIQUEB_H
#define BRIQUEB_H
#include "Brique.h"
/// <summary>
/// ID = B
/// PV = 2
/// </summary>
class BriqueB : public Brique {
public:
	BriqueB(int x = 0, int y = 0, int l = 6, int h = 2);

	~BriqueB();

	void update(float timeElapsed);

	void afficher(std::ostream& s); //pour les testcran
};
#endif
