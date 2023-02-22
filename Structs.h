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
    int Brick_length;
    int Brick_heigth;
};

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
enum gameState {
    Stopped,
    Paused,
    Starting,
    Running,

};


#endif
