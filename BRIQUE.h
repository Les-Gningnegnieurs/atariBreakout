/*
	Auteur: Victor Turcotte
	Date de création : 13/02/2023
	Lieu : Universite de Sherbrooke
*/
#ifndef BRIQUE_H
#define BRIQUE_H
#include "Structs.h"
#include "Balle.h"

#include <iostream>

class Brique
{
public:
	//on entre simplement les coordonnées. la hauteur et la largeur sont déja définies
	Brique(int x = 0, int y = 0, int l = 6, int h = 2, state s = Alive);

	bool increase_Damage();

	virtual ~Brique();

	
	bool checkCollision(Balle*b);

	//virtual void update(float timeElapsed);

	bool est_Detruite();

	/// @brief
	/// @return Destroyed ou autres
	state getstate();

	void setstate(state s);
    bool checkTop(Position posB);
    bool checkBot(Position posB);
    bool checkRight(Position posB);
    bool checkLeft(Position posB);
	int GetHauteur() { return _sizeY; }

	void draw(char UI[RESMAX_Y][RESMAX_X]);
	virtual void afficher(std::ostream& s) = 0;
protected:
	Hitbox _posBrique;
	state _etat;
	int _sizeX;
	int _sizeY;
	int _PV;
};

#endif