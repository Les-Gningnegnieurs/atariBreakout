#ifndef BRIQUET_H
#define BRIQUET_H
#include "Brique.h"
/// <summary>
/// ID = A
/// PV = 1
/// </summary>
class BriqueT : public Brique {
public:
	BriqueT(int x = 0, int y = 0, int l = 1, int h = 1);

	~BriqueT();

	void update();

	void afficher(std::ostream& s); //pour les testcran
};
#endif
