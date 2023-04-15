#include "Level.h"
Level::Level(LevelInfos I, Score* score, QGraphicsScene* scene): _scene(scene), _score(score){
    rows = I.rows;
    columns = I.columns;
    BrickHeigth = I.Brick_heigth;
    BrickLength = I.Brick_length;
}
Level::Level() {
}
Level :: ~Level(){

}

void Level::draw() {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
             _board[i][j]->draw();
        }

    }
}

void Level::checkColl_DOWN_RIGHT(Balle* b, std::vector <Powerups*>& p, Controller& c){
    
    //    LE CODE EN COMMENTAIRE EST UNE IDÉE POUR OPTIMISER LES CHECKCOLLISIONS: ON CHECK JUSTE LES BRIQUES AUTOUR
    //  DE LA BALLE AU LIEU DE CHECK L'ENSEMBLE DE L'ARRAY
    //for (int i = 0; i < rows / BrickHeigth; i++) //haut en bas
    //{
        //for (int j = 0; j < columns / BrickLength; j++) //gauche a droite
    int i_max = (b->getPos().y / BrickHeigth) + 2;
    int j_max = (b->getPos().x / BrickLength) + 2;
    if (i_max > rows )
        i_max = rows;
    if (j_max > columns )
        j_max = columns;
    int i = i_max - 3;
    if (i < 0)
        i = 0;
    for(i; i < i_max; i++)
    {
        int j = j_max - 3;
        if (j < 0)
            j = 0;
        for(j;j<j_max;j++)
   
        {
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case UP:
                    b->changeVelocity(0, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case CN:
                    b->changeVelocity(1, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
void Level::checkColl_DOWN_LEFT(Balle* b,std::vector <Powerups*>& p, Controller& c){
    int i_max = (b->getPos().y / BrickHeigth) + 2;
    int j_max = (b->getPos().x / BrickLength) - 1;
    if (i_max > rows )
        i_max = rows;
    if (j_max < 0)
        j_max = 0;
    int i = i_max - 3;
    if (i < 0)
        i = 0;
    for (i; i < i_max; i++)
    {
        int j = j_max + 2;
        if (j >= columns-1)
            j = columns-1;
        for (j; j >= j_max; j--)
        {
    //for (int i = 0; i < rows / BrickHeigth; i++) //haut en bas
    //{
        //for (int j = (columns / BrickLength) - 1; j >= 0; j--) //droite a gauche
        //{
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case UP:
                    b->changeVelocity(0, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case CN:
                    b->changeVelocity(1, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
void Level::checkColl_UP_RIGHT(Balle* b, std::vector <Powerups*>& p, Controller& c){
    int i_max = (b->getPos().y / BrickHeigth) - 1;
    int j_max = (b->getPos().x / BrickLength) + 2;
    if (i_max < 0)
        i_max = 0;
    if (j_max > columns)
        j_max = columns;
    int i = i_max + 2;
    if (i >= rows-1)
        i = rows-1;
    for (i; i >= i_max; i--)
    {
        int j = j_max - 3;
        if (j < 0)
            j = 0;
        for (j; j < j_max; j++)
        { 
    //for (int i = (rows / BrickHeigth) - 1; i >= 0; i--) //bas vers le haut
    //{
        //for (int j = 0; j < columns / BrickLength; j++) //gauche a droite
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case UP:
                    b->changeVelocity(0, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case CN:
                    b->changeVelocity(1, 1);
                    if (_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
void Level::checkColl_UP_LEFT(Balle* b, std::vector <Powerups*>& p, Controller& c){
    int i_max = (b->getPos().y / BrickHeigth) - 1;
    int j_max = (b->getPos().x / BrickLength) - 1;
    if (i_max < 0)
        i_max = 0;
    if (j_max < 0)
        j_max = 0;
    int i = i_max + 2;
    if (i >= rows-1)
        i = rows -1;
    for(i; i>= i_max; i--)
    {
        int j = j_max + 2;
        if (j >= columns-1)
            j = columns-1;
        for(j; j >= j_max; j--)
        {

    //for (int i = (rows / BrickHeigth) - 1; i >= 0; i--) //bas vers le haut
    //{
        //for (int j = (columns / BrickLength) - 1; j >= 0; j--) //droite vers la gauche
            if (!_board[i][j]->est_Detruite())
            {
                Collision check = _board[i][j]->checkCollision(b);
                switch (check) {
                case LT:
                    b->changeVelocity(1, 0);
                    if(_board[i][j]->increase_Damage(p, _scene, c))   //si la brique est peté
                        _score->increase();
                    break;
                case RT:
                    b->changeVelocity(1, 0);
                    if(_board[i][j]->increase_Damage(p, _scene, c))
                        _score->increase();
                    break;
                case DN:
                    b->changeVelocity(0, 1);
                    if(_board[i][j]->increase_Damage(p, _scene, c))
                        _score->increase();
                    break;
                case UP:
                    b->changeVelocity(0, 1);
                    if(_board[i][j]->increase_Damage(p, _scene, c))
                        _score->increase();
                    break;
                case CN:
                    b->changeVelocity(1, 1);
                    if(_board[i][j]->increase_Damage(p, _scene, c))
                        _score->increase();
                    break;
                case NO:
                    break;
                }
            }
        }
    }
}
  
void Level :: checkCollision(Balle* b, std::vector<Powerups*>& p, Controller& c){
    //On va faire une fonction qui décide les valeurs du for loop pour chaque cas
    //pour simplifier le code mais dans le fond g fait 4 facons différentes de checker l'Array qui dépende de la 
    //vitesse de la balle. Cette methode permet d'empecher qu'une balle qui est supposé frapper le bas d'une brique
    //detecte dabord la collision de coin de la prochaine brique et fasse une collision qui fait pas de sens
    if (b->getSpeed().y > 0 && b->getSpeed().x >= 0) // si la balle descend et va vers la droite
    {
        checkColl_DOWN_RIGHT(b, p, c);
    }
    else if (b->getSpeed().y > 0 && b->getSpeed().x <= 0) // si la balle descend et va vers la gauche
    {
        checkColl_DOWN_LEFT(b, p, c);
    }
    else if(b->getSpeed().y <= 0 && b->getSpeed().x >= 0){ //si la balle monte et va vers la droite
        checkColl_UP_RIGHT(b, p, c);
    }
    else if (b->getSpeed().y <= 0 && b->getSpeed().x <= 0) { //si la balle monte et va vers la gauche
        checkColl_UP_LEFT(b, p, c);
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
        //for(int i=0; i< I.getRows()/I.getHeigth(); i++)
        for (int i = 0; i < I.getRows() ; i++)
        {
            //for(int j=0; j<I.getColumns()/I.getLength(); j++)
            for(int j=0; j<I.getColumns(); j++)
            {
                s >> x;
                if(x == 1){
                    //pourrait faire dequoi avec le 128 pour ajuster l'écran
                    //si == 0 : pas de brique a cette position
                    I._board[i][j] = new Briquetest(j*I.getLength()+CONTOUR, i*I.getHeigth()+CONTOUR, I.getLength(), I.getHeigth()); 
                    I._board[i][j]->setPos(j * I.BrickLength + CONTOUR,  i * I.BrickHeigth + CONTOUR);
                    I._scene->addItem(I._board[i][j]);
                }
                else if (x == 0) {
                    I._board[i][j] = new BriqueVoid(j * I.getLength() + CONTOUR, i * I.getHeigth() + CONTOUR, I.getLength(), I.getHeigth());
                    //I._scene->addItem(I._board[i][j]->getRect());
                }
                
                else if (x == 2) {
                    I._board[i][j] = new BriqueB(j * I.getLength() + CONTOUR, i * I.getHeigth() + CONTOUR, I.getLength(), I.getHeigth());
                    I._board[i][j]->setPos(j * I.BrickLength + CONTOUR, i * I.BrickHeigth + CONTOUR);
                    I._scene->addItem(I._board[i][j]);
                }
                
                else if (x == 3) {
                    I._board[i][j] = new BriqueC(j * I.getLength() + CONTOUR, i * I.getHeigth() + CONTOUR, I.getLength(), I.getHeigth());
                    I._board[i][j]->setPos(j * I.BrickLength + CONTOUR, i * I.BrickHeigth + CONTOUR);
                    I._scene->addItem(I._board[i][j]);
                }

                else if (x == 8) {
                    I._board[i][j] = new BriqueT(j * I.getLength() + CONTOUR, i * I.getHeigth() + CONTOUR, I.getLength(), I.getHeigth());
                    I._board[i][j]->setPos(j * I.BrickLength + CONTOUR, i * I.BrickHeigth + CONTOUR);
                    I._scene->addItem(I._board[i][j]);
                }
                
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
