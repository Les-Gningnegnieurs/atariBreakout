#include "Level.h"
Level :: Level(){
    _info.rows = MAX_ROWS;
    _info.columns = MAX_COLUMNS;
    _info.Brick_length = 4;
    _info.Brick_heigth = 1;
}
Level :: ~Level(){

}

void Level :: draw(){
    std::cout << "Informations sur le niveau" << std::endl;
    for (int i = 0; i < _info.rows; i++) {
        for (int j = 0; j < _info.columns; j++) {
            _board[i][j]->afficher(std::cout);
        }
        //std::cout << endl;
    }

}

void Level :: update(float timeElapsed){

}

bool Level :: checkCollision(int x, int y){
    for (int i = 0; i < _info.rows; i++)
    {
        for (int j = 0; j < _info.columns; j++)
        {
            if (_board[i][j]->checkCollision(x, y))
                return true;
        }
    }
    return false;
}

Brique* Level::getBrique(int row_idx, int column_idx) { //utile pour set le level au debut
    if (row_idx >= _info.rows || column_idx >= _info.columns)
        return nullptr;
    return _board[row_idx][column_idx];
}
bool Level::setBrique(int row_idx, int column_idx, Brique* brique) { //utile pour set le level au debut
    if (row_idx >= _info.rows || column_idx >= _info.columns)
        return false;
    _board[row_idx][column_idx] = brique;
}
void Level :: afficher(std::ostream& s){
    s << _info.rows << " , " << _info.columns << std::endl; 
}

void Level :: setRows(int rows){
    _info.rows = rows;
}

void Level :: setColumns(int columns){
    _info.columns = columns;
}

int Level :: getRows(){
    return _info.rows;
}
int Level :: getColumns(){
    return _info.columns;
}

int Level :: getHeigth(){
    return _info.Brick_heigth;
}
void Level :: setHeigth(int y){
    _info.Brick_heigth = y;
}

int Level :: getLength(){
    return _info.Brick_length;
}
void Level :: setLength(int x){
    _info.Brick_length = x;
}
std::istream& operator >> (std::istream& s, Level& I){
    int x;
    s >> x;    //rows
    I.setRows(x); 
    s >> x;    //columns
    I.setColumns(x); 
    s >> x; //length
    I.setLength(x);
    s>>x; //heigth
    I.setHeigth(x);
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
            }
        }
    }
    return s;
}