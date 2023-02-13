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

std::istream& operator >> (istream& s, Level& I){
}