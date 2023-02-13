/*
	Auteur: Victor Turcotte
	Date de création : 13/02/2023
	Lieu : Universite de Sherbrooke
*/
#ifndef BRIQUE_H
#define BRIQUE_H

#include <iostream>
#include <istream>
#include "BricksInfo.h"

using namespace std;

class Brique
{
public:
	//on entre simplement les coordonnées. la hauteur et la largeur sont déja définies
	Brique(int x, int y, int l, int h);

	virtual ~Brique();

	
	virtual bool checkCollision(int x, int y);

	virtual void update(float timeElapsed);

	virtual bool est_Detruite();

	/// @brief
	/// @return Destroyed ou autres
	virtual PV getPV();

	/// @brief 
	/// @param l'état à devenir
	/// @return true or false
	virtual bool setPV(PV state);

	virtual bool increase_Damage();

	virtual istream& importer(istream &s);

	virtual void afficher(ostream& s) = 0; //pour les test � l'�cran
protected:
	Hitbox _pos;
	PV _pv;
	int _sizeX;
	int _sizeY;
};

#endif