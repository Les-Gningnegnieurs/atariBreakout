#ifndef BRIQUEC_H
#define BRIQUEC_H
#include "Brique.h"
/// <summary>
/// ID = C
/// PV = 3
/// </summary>
class BriqueC : public Brique {
public:
	BriqueC(int x = 0, int y = 0, int l = 6, int h = 2);

	~BriqueC();

	void update(float timeElapsed);

	void afficher(std::ostream& s); //pour les testcran
};

#endif
