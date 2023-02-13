/*
	Auteur: Victor Turcotte
	Date de création : 13/02/2023
	Lieu : Universite de Sherbrooke
*/

#ifndef BRICKSINFO_H
#define BRICKSINFO_H
/// @brief coordonnées du coin gauche
struct Hitbox {
	x;
	y;
};
/// @brief Destroyed(0) = delete la brique, Hurt(1-4)= 4 niveau de vie pour l'instant
enum PV{
    Destroyed,
    Hp1,
    Hp2,
    Hp3,
    Hp4, 
};
/// @brief def: pour les différentes textures des briques à plusieurs vies. Big number = big damage
enum HurtType{
    Hurt0,
    Hurt1,
    Hurt2,
    Hurt3
    //..... 
};


#endif
