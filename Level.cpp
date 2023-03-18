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

void Level::checkColl_DOWN_RIGHT(Balle* b, int& score, std::vector <Powerups*>& p){
    for (int i=0; i < rows/BrickHeigth; i++) //haut en bas
    {
        for (int j=0; j < columns/BrickLength; j++) //gauche a droite
        {
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case UP:
                    score++;
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case CN:
                    score++;
                    b->changeVelocity(1, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
void Level::checkColl_DOWN_LEFT(Balle* b, int& score, std::vector <Powerups*>& p){
    for (int i = 0; i < rows / BrickHeigth; i++) //haut en bas
    {
        for (int j = (columns / BrickLength) - 1; j >= 0; j--) //droite a gauche
        {
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case UP:
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case CN:
                    b->changeVelocity(1, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
void Level::checkColl_UP_RIGHT(Balle* b, int& score, std::vector <Powerups*>& p){
    for (int i = (rows / BrickHeigth) - 1; i >= 0; i--) //bas vers le haut
    {
        for (int j = 0; j < columns / BrickLength; j++) //gauche a droite
        {
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case UP:
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case CN:
                    b->changeVelocity(1, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
void Level::checkColl_UP_LEFT(Balle* b, int& score, std::vector <Powerups*>& p){
    for (int i = (rows / BrickHeigth) - 1; i >= 0; i--) //bas vers le haut
    {
        for (int j = (columns / BrickLength) - 1; j >= 0; j--) //droite vers la gauche
        {
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case UP:
                    b->changeVelocity(0, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case CN:
                    b->changeVelocity(1, 1);
                    _board[i][j]->increase_Damage(p,score);
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
  
void Level :: checkCollision(Balle* b, int& score, std::vector<Powerups*>& p){
    //On va faire une fonction qui décide les valeurs du for loop pour chaque cas
    //pour simplifier le code mais dans le fond g fait 4 facons différentes de checker l'Array qui dépende de la 
    //vitesse de la balle. Cette methode permet d'empecher qu'une balle qui est supposé frapper le bas d'une brique
    //detecte dabord la collision de coin de la prochaine brique et fasse une collision qui fait pas de sens
    if (b->getSpeed().y > 0 && b->getSpeed().x >= 0) // si la balle descend et va vers la droite
    {
        checkColl_DOWN_RIGHT(b, score, p);
    }
    else if (b->getSpeed().y > 0 && b->getSpeed().x <= 0) // si la balle descend et va vers la gauche
    {
        checkColl_DOWN_LEFT(b, score, p);
    }
    else if(b->getSpeed().y <= 0 && b->getSpeed().x >= 0){ //si la balle monte et va vers la droite
        checkColl_UP_RIGHT(b, score, p);
    }
    else if (b->getSpeed().y <= 0 && b->getSpeed().x <= 0) { //si la balle monte et va vers la gauche
        checkColl_UP_LEFT(b, score, p);
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
    //while(!s.eof()){
        for(int i=0; i< I.getRows()/I.getHeigth(); i++)
        {
            for(int j=0; j<I.getColumns()/I.getLength(); j++)
            {
                s >> x;
                if(x == 1){
                    //pourrait faire dequoi avec le 128 pour ajuster l'écran
                    //si == 0 : pas de brique a cette position
                    I._board[i][j] = new Briquetest(j*I.getLength(), i*I.getHeigth(), I.getLength(), I.getHeigth()); 
                }
                else if (x == 0) 
                    I._board[i][j] = new BriqueVoid(j * I.getLength(), i * I.getHeigth(), I.getLength(), I.getHeigth());
                
                else if (x == 2)
                    I._board[i][j] = new BriqueB(j * I.getLength(), i * I.getHeigth(), I.getLength(), I.getHeigth());
                
                else if(x == 3)
                    I._board[i][j] = new BriqueC(j * I.getLength(), i * I.getHeigth(), I.getLength(), I.getHeigth());

                else if (x == 8) 
                    I._board[i][j] = new BriqueT(j * I.getLength(), i * I.getHeigth(), I.getLength(), I.getHeigth());
                
            }
        }
        
   // }
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
