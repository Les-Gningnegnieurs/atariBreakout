/*
	Auteur: Victor Turcotte
	Date de création : 13/02/2023
	Lieu : Universite de Sherbrooke
*/
#ifndef BRIQUE_H
#define BRIQUE_H
#include "Structs.h"
#include "Balle.h"
#include <vector>
#include "Extendplatform.h"
#include "Addballs.h"
#include "Swapcontrol.h"
#include <QGraphicsRectItem>
#include <QColor>
#include <QBrush>
#include <QGraphicsScene>
#include <random>
#include <iostream>


class Brique: public QGraphicsRectItem
{
public:
	//on entre simplement les coordonnées. la hauteur et la largeur sont déja définies
	Brique(int x = 0, int y = 0, int l = 6, int h = 2, state s = Alive);

	bool increase_Damage(std::vector<Powerups*>& p, QGraphicsScene* _scene, Controller& c);

	virtual ~Brique();

	
	Collision checkCollision(Balle*b);

	//QGraphicsRectItem* getRect();

	//virtual void update(float timeElapsed);

	bool est_Detruite();

	/// @brief
	/// @return Destroyed ou autres
	state getstate();

	void setstate(state s);
	int GetHauteur() { return _sizeY; }
	int getPv() { return _PV; }

	//void draw(char UI[RESMAX_Y][RESMAX_X]);
	void draw();
	virtual void afficher(std::ostream& s) = 0;
	virtual void addPowerUp(std::vector<Powerups*>& p, QGraphicsScene* _scene, Controller& c);
	virtual void update_hurt(int pv)=0;
protected:
	Position _posBrique;
	state _etat;
	int _sizeX;
	int _sizeY;
	int _PV;
	std::random_device rd;
	QGraphicsScene* _scene;
	
};

#endif