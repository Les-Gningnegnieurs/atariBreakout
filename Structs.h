//
// Created by stao0901 on 2023-02-13.
//

#ifndef STRUCTS_H
#define STRUCTS_H

#define RESMAX_X 80
#define RESMAX_Y 25

struct Position {
    int x;
    int y;
};
struct Velocity {
    int x;
    int y;
};

struct LevelInfos{
    int rows;
    int columns;
    int Brick_length; //in pixels
    int Brick_heigth; //in pixels
    int pos_Plat_iniX;
    int pos_Plat_iniY;
    int Plat_length;
    int Plat_heigth;
    int pos_Ball_iniX;
    int pos_Ball_iniY;
    float ball_radius;
};

/// @brief coordonnées du coin gauche
struct Hitbox {
    int x;
    int y;
};
/// @brief Destroyed(0) = delete la brique, Hurt = touché, Alive = pas touché, Indestructible
enum state{
    Destroyed,
    Hurt,
    Alive,
    Indestructible,
};
enum gameState {
    Stopped,
    Paused,
    Starting,
    Running,

};
enum Collision {
    LT,
    RT,
    DN,
    UP,
    NO,
};

#endif
