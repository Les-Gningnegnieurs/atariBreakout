#ifndef LEVEL_H
#define LEVEL_H

#include "Brique.h"
#include "Structs.h"
#include "Briquetest.h"
#include "BriqueVoid.h"
#include "BriqueA.h"
#include "BriqueB.h"
#include "BriqueT.h"
#include "BriqueC.h"
#include <iostream>
#include "Balle.h"
#include <vector>
#include "Powerups.h"


class Level{
    private: 
        //LevelInfos _info;
        int rows;
        int columns;
        int BrickHeigth;
        int BrickLength;
        Brique *_board[RESMAX_Y][RESMAX_X];
    public:
        Level(LevelInfos I);
        Level();
        ~Level();

        void draw(char UI[RESMAX_Y][RESMAX_X]);

        void setRows(int rows);

        int getRows();

        void setColumns(int columns);
        
        int getColumns();

        int getHeigth();

        int getLength();


        void checkCollision(Balle *b, int& score,std::vector <Powerups*> &p);

        Brique* getBrique(int row_idx, int column_idx); //utile pour set le level au debut

        bool setBrique(int row_idx, int column_idx, Brique* brique); //utile pour set le level au debut


        void afficher(std::ostream& s);
        void levelDrawline(std::ostream &s,int ligne );


        friend std::istream& operator >>(std::istream& s, Level& I);

};
#endif