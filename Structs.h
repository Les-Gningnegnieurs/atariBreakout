//
// Created by stao0901 on 2023-02-13.
//

#ifndef STRUCTS_H
#define STRUCTS_H

struct Position {
    int x;
    int y;
};
struct Velocity {
    int x;
    int y;
};

struct LevelInfos {
    int rows;
    int columns;
    int Brick_length; //in pixels
    int Brick_heigth; //in pixels
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


#endif
