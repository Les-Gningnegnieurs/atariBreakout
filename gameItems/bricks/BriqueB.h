#ifndef BRIQUEB_H
#define BRIQUEB_H
#include "Brique.h"
/// <summary>
/// ID = B
/// PV = 2
/// </summary>
class BriqueB : public Brique {
public:
	BriqueB(int x = 0, int y = 0, int l = 1, int h = 1);

	~BriqueB();

	void update();

	void afficher(std::ostream& s); //pour les testcran
	void update_hurt(int pv, QGraphicsScene* _scene);
};
#endif
