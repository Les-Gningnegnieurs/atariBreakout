#include "Level.h"
Level :: Level(){
    _info.rows = MAX_ROWS;
    _info.columns = MAX_COLUMNS;
}
Level :: ~Level(){

}

void Level :: draw(){

}

void Level :: update(float timeElapsed){

}

bool Level :: checkCollision(int x, int y){
    return false;
}

bool Level :: addBrick(Brique *brick){//utile pour set le level au debut
    return true;
}

Brique* Level :: deleteBrick(int row, int column){ //utile pour set le level au debut
    return nullptr;
}

Brique* Level :: edit_Brique(int row, int column){
    return nullptr;
}

void Level :: afficher(ostream& s){
    s << _info.rows << " , " << _info.columns << endl; 
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
std::istream& operator >> (istream& s, Level& I){
    string ch;
    int x;
    s >> ch;    //rows
    x = atoi(ch.c_str());
    setRows(x); 
    s >> ch;    //columns
    x=atoi(ch.c_str());
    setRows(x); 
    s >> ch; //length
    x = atoi(ch.c_str());
    setLength(x);
    s>>ch; //heigth
    x = atoi(ch.c_str());
    setHeigth(x);
    while(!eof()){
        for(int i=0; i< I.getRows(); i++)
        {
            for(int j=0; j<I.getColumns(); j++)
            {
                s >> ch;
                if(ch == "1"){
                    //pourrait faire dequoi avec le 128 pour ajuster l'écran
                    //si == 0 : pas de brique a cette position
                    I._board[i][j] = new Brique(j*I.getLength(), i*I.getHeigth, I.getLength(), I.getHeigth()); 
                }
            }
        }
    }
    return s;
}