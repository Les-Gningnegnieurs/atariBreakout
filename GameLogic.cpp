#include "GameLogic.h"

GameLogic::GameLogic()
{
}

GameLogic:: GameLogic(LevelInfos i)
{
    _info = i;
    maxSizeX = _info.columns;
    maxSizeY = _info.rows;
    _livesLeft=3;
     _platform=Plateforme(_info);
    _score=0;
    Position posB;
    posB.x = i.pos_Ball_iniX;
    posB.y = i.pos_Ball_iniY;
    _balls.push_back(new Balle(posB,i.ball_radius));
    _level = Level(_info);
    for (int i = 0; i < maxSizeY; i++) {
        for (int j = 0; j < maxSizeX; j++) {
            UI[i][j] = ' ';
        }
    }
}

GameLogic::~GameLogic(){
    _balls.clear();
}

void GameLogic:: update(Controller& c)
{
    _level.draw(UI);
    //move plateform
    _platform.move(c.getJoystick().x);
    _platform.update(); //update la position
    _platform.draw(UI); //update le dessin dans le tableau

    for (int i = 0; i < _powers.size(); i++)
    {
        _powers[i]->update();
        _powers[i]->draw(UI);
        if (_powers[i]->getState() == Done || _powers[i]->getState() == OutOfBounds)
        {
            if (_powers[i]->getState() == Done)
            
                _powers[i]->resetPowerups(_balls, _platform, c);
            UI[_powers[i]->getPos().y][_powers[i]->getPos().x] = ' ';
            delete _powers[i];
;             _powers.erase(_powers.begin() + i);
            
        }
    }

    //update Game / do logic
    for(int i=0; i< _balls.size();i++)
    {
        _balls[i]->update();
        _balls[i]->draw(UI);
    }

    //check les collisions une fois que les positions ont ete updatés
    checkCollisions(c);
    draw(std::cout);
    //Update controller status (LED & bargrpah)
    //TODO quand on vas avoir déterminé une utilité
}

bool GameLogic::isGameOver()
{
    if (_livesLeft<0)  return true;
    else return false;
}

//Retirer les valeurs de limite hardcodé et enovyer balle en reference 
//dans les check collision pour utiliser leur vélocité pour savoir d'ou elles arrivent pour le check colision
//et determiner l'angle de renvoi
void GameLogic::checkCollisions(Controller &control) {
    Position pos;

    for (int i = 0; i < _powers.size(); i++)
    {
        if (_powers[i]->getPos().y + _powers[i]->getHeight() >= maxSizeY)
            _powers[i]->setState(OutOfBounds); 
        
        if (_powers[i]->checkCollisions(_platform)) {
            UI[_powers[i]->getPos().y][_powers[i]->getPos().x] = ' ';
            _powers[i]->setPowerups(_balls, _platform, control);
        }
    }
    for(int i=0; i< _balls.size();i++)
    {
        pos= _balls[i]->getPos();
        if (pos.y >= maxSizeY) //check si mort
        {
            //_balls[i]->changeVelocity(0, 1); //faire bounce dans le bas
            delete _balls[i];
            _balls.erase(_balls.begin()+i);
        }
        else
        {
            _platform.checkCollision(_balls[i]);
            
            //Balle *b = _balls[i];
            _level.checkCollision(_balls[i], _score,_powers);

            if (pos.y <= 0) //Hit  plafond
            {
                _balls[i]->changeVelocity(0, 1);//inverser direction de la balle en Y
            }

            //check walls collision
            if (pos.x <= 0 || pos.x + _balls[i]->getrayon() >= maxSizeX - 1)
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
        }
    }
    if(_balls.empty())
    {
        _livesLeft--;
        Sleep(200);
        Position posb; 
        posb.x = _info.pos_Ball_iniX;
        posb.y = _info.pos_Ball_iniY;
        Balle* p1 = new Balle(posb,_info.ball_radius);
        _balls.push_back(p1);
    }

}

int GameLogic::getScoreInfo() {
    return _score;
}

void GameLogic::draw(std::ostream& s) {
    DWORD dw;
    COORD here;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //draw bricks
    for (int i = 0; i < maxSizeY; i++) {
        for (int j = 0; j < maxSizeX; j++) {
            here.Y = i;
            here.X = j;

            TCHAR strFromConsole[1];
            ReadConsoleOutputCharacter(hStdOut, strFromConsole, 1, here, &dw);
            char c = strFromConsole[0];
            if (c != UI[i][j])
            {
                char text[1];
                text[0] = UI[i][j];
                wchar_t wtext[1];
                mbstowcs(wtext, text, 2);
                LPWSTR ptr = wtext;
                WriteConsoleOutputCharacter(hStdOut, ptr, 1, here, &dw);
            }
        }
    }
}

std::istream& operator>>(std::istream& s, GameLogic &gl){
    
    s >> gl._level;
    return s;
 }


Plateforme& GameLogic::getPlaform() { return _platform; }