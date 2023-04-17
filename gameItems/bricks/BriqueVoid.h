#ifndef BRIQUEVOID_H
#define BRIQUEVOID_H

#include "Brique.h"
class BriqueVoid : public Brique {
public:
	BriqueVoid(int x = 0, int y = 0, int l = 1, int h = 1);

	~BriqueVoid();

	void update();

	void afficher(std::ostream& s); //pour les testcran

	void update_hurt(int pv, QGraphicsScene* _scene){}
};
#endif