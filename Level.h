#ifndef LEVEL_H
#define LEVEL_H

#include "Brique.h"
#include "Structs.h"
#include "Briquetest.h"
#include <iostream>
#define MAX_ROWS 128
#define MAX_COLUMNS 128

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

        int getRows();

        void setColumns(int columns);
        
        int getColumns();

        int getHeigth();

        void setHeigth(int y);

        int getLength();

        void setLength(int x);

        bool checkCollision(int x, int y);

        Brique* getBrique(int row_idx, int column_idx); //utile pour set le level au debut

        bool setBrique(int row_idx, int column_idx, Brique* brique); //utile pour set le level au debut


        void afficher(std::ostream& s);

        friend std::istream& operator >>(std::istream& s, Level& I);

};
#endif