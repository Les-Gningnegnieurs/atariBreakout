#ifndef LEVEL_H
#define LEVEL_H

#include "Brique.h"
#include "LevelInfo.h"
#include <ostream>
#include <istream>
#define MAX_ROWS 4
#define MAX_COLUMNS 8

class Level{
    private: 
        LevelInfos _info;
        Brique *_board[MAX_ROWS][MAX_COLUMNS];
    public:
        Level();
        ~Level();

        void draw();

        void update(float timeElapsed);

        void setRows(int rows);

        void setColumns(int columns);

        bool checkCollision(int x, int y);

        bool addBrick(Brique *brick); //utile pour set le level au debut

        Brique* deleteBrick(int row, int column); //utile pour set le level au debut

        Brique* edit_Brique(int row, int column); 

        void afficher(ostream& s);

        friend istream& operator >>(istream& s, Level& I);

};
#endif