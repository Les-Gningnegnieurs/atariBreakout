#include "Level.h"
Level::Level(LevelInfos I){
    rows = I.rows;
    columns = I.columns;
    BrickHeigth = I.Brick_heigth;
    BrickLength = I.Brick_length;
}
Level::Level() {
}
Level :: ~Level(){

}

void Level::draw(char UI[RESMAX_Y][RESMAX_X]) {

    for (int i = 0; i < rows/BrickHeigth; i++) {
        for (int j = 0; j < columns/BrickLength; j++) {
            _board[i][j]->draw(UI);
        }

    }


}



void Level :: checkCollision(Balle *b, int& score){
  
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    score++;
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage();
                    break;
                case RT:
                    score++;
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage();
                    break;
                case DN:
                    score++;
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage();
                    break;
                case UP:
                    score++;
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage();
                    break;
                case CN:
                    score++;
                    b->changeVelocity(1, 1);
                    _board[i][j]->increase_Damage();
                case NO:
                    break;
                }
            }
        }
    }
}

Brique* Level::getBrique(int row_idx, int column_idx) { //utile pour set le level au debut
    if (row_idx >= rows || column_idx >= columns)
        return nullptr;
    return _board[row_idx][column_idx];
}
bool Level::setBrique(int row_idx, int column_idx, Brique* brique) { //utile pour set le level au debut
    if (row_idx >= rows || column_idx >= columns)
        return false;
    _board[row_idx][column_idx] = brique;
}
void Level :: afficher(std::ostream& s){
    s << "Informations sur le niveau" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            _board[i][j]->afficher(s);
        }
    }
}

int Level :: getRows(){
    return rows;
}
int Level :: getColumns(){
    return columns;
}

int Level :: getHeigth(){
    return BrickHeigth;
}

int Level :: getLength(){
    return BrickLength;
}
std::istream& operator >> (std::istream& s, Level& I){
    //on est rendu aux infos sur le level
    int x=0;
    while(!s.eof()){
        for(int i=0; i< I.getRows(); i++)
        {
            for(int j=0; j<I.getColumns(); j++)
            {
                s >> x;
                if(x == 1){
                    //pourrait faire dequoi avec le 128 pour ajuster l'écran
                    //si == 0 : pas de brique a cette position
                    I._board[i][j] = new Briquetest(j*I.getLength(), i*I.getHeigth(), I.getLength(), I.getHeigth()); 
                }
                else if (x == 0) {
                    I._board[i][j] = new BriqueVoid(j * I.getLength(), i * I.getHeigth(), I.getLength(), I.getHeigth());
                }
            }
        }
        
    }
    return s;
}
//pour les briques de hauteur plus que 1.. comprend pas trop comment ca fonctionne donc on en va pas l'utiliser pour live
/*void Level::levelDrawline(std::ostream& s, int ligne) {
             for(int i=0;i< _info.Brick_heigth;i++)
             {
                 for(int j=0;j<_info.columns;j++)
                 {
                     _board[ligne][j]->draw(s);
                 }
                s<<std::endl;



            }
        }
        */
