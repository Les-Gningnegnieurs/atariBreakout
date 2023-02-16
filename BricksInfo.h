/*
	Auteur: Victor Turcotte
	Date de création : 13/02/2023
	Lieu : Universite de Sherbrooke
*/

#ifndef BRICKSINFO_H
#define BRICKSINFO_H
/// @brief coordonnées du coin gauche
struct Hitbox {
	int x;
	int y;
};
/// @brief Destroyed(0) = delete la brique, Hurt = touché, Alive = pas touché
enum state{
    Destroyed,
    Hurt,
    Alive, 
};


#endif
