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
#include <QGraphicsScene>
#include "Myrect.h"



class Level{
    private: 
        //LevelInfos _info;
        int rows;
        int columns;
        int BrickHeigth;
        int BrickLength;
        Brique *_board[RESMAX_Y][RESMAX_X];
        QGraphicsScene* _scene;
        Score* _score;

    public:
        Level(LevelInfos I, Score* score, QGraphicsScene* scene);
        Level();
        ~Level();

        void draw();

        void setRows(int rows);

        int getRows();

        void setColumns(int columns);
        
        int getColumns();

        int getHeigth();

        int getLength();
        int I(int i_start, int i_end, int i);
        int J(int j_start, int j_end, int j);

        void checkColl_DOWN_RIGHT(Balle* b, std::vector <Powerups*>& p);
        void checkColl_DOWN_LEFT(Balle* b, std::vector <Powerups*>& p);
        void checkColl_UP_RIGHT(Balle* b, std::vector <Powerups*>& p);
        void checkColl_UP_LEFT(Balle* b, std::vector <Powerups*>& p);
        void checkCollision(Balle *b, std::vector <Powerups*> &p);

        Brique* getBrique(int row_idx, int column_idx); //utile pour set le level au debut

        bool setBrique(int row_idx, int column_idx, Brique* brique); //utile pour set le level au debut


        void afficher(std::ostream& s);


        friend std::istream& operator >>(std::istream& s, Level& I);

};
#endif