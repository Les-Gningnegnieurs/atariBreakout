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
/// @brief Healty(0) = initialise, Hurt(1)= damaged mais pas brisée, Destroyed(2) = brisée/deleted
enum PV{
    Healthy,
    Hurt,
    Destroyed 
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
