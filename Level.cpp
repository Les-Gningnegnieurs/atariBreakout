#include "Level.h"
Level :: Level(){
    _level. = MAX_ROWS;
    newLevel.columns = MAX_COLUMNS;
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
    s << _level.rows << " , " << _level.columns << endl; 
}

friend istream& operator >> (istream& s, Level& I){

}