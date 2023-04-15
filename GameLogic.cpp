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
    _balls.push_back(new Balle(posB,i.ball_radius, i.speed_B_x, i.speed_B_y));
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

void GameLogic:: update(Controller& c, bool accelmode)
{
    _level.draw(UI);
    //move plateform
    if (accelmode)
        _platform.move(c.getAccelerometre().x);
    else
        _platform.move(c.getJoystick().x);
    _platform.update(); //update la position
    _platform.draw(UI); //update le dessin dans le tableau
    bool foundTimer = false;
    
    
        
    for (int i = 0; i < _powers.size(); i++)
    {
      
        
        _powers[i]->update();
        if (_powers[i]->getState() == Active && _powers[i]->getLedinfo().hasTimer && !foundTimer)
        {
            //caller la couleur juste une fois au début, pas à chaque Tick
            //caller turnOn/turnOff pour faire flasher
            /*if (_powers[i]->getLedinfo().color == 'r')
            {
                c.setLED(0, 1, 255, 0, 0);
                c.setLED(1, 1, 255, 0, 0);
            }
            else
            {
                c.setLED(0, 1, 0, 255, 0);
                c.setLED(1, 1, 0, 255, 0);
            }*/
           
            foundTimer = true;
            
            
            //Logique a revoir
            int timer = _powers[i]->getTimer();
            int nbLeds = ((timer * 10) / PTIMELIMIT);
            nbLeds = nbLeds % 10;
            for (int i = 0; i < 10; i++)
            {
                if (nbLeds > i)
                    c.setBargraph(i, 1);
                else
                    c.setBargraph(i, 0);
                    
            }
            
            

            
        }
        
        
        _powers[i]->draw(UI);
        if (_powers[i]->getState() == Done || _powers[i]->getState() == OutOfBounds)
        {
            if (_powers[i]->getState() == Done)
            
                _powers[i]->resetPowerups(_balls, _platform, c);
            UI[_powers[i]->getPos().y][_powers[i]->getPos().x] = ' ';
            delete _powers[i];
;           _powers.erase(_powers.begin() + i);
            
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
    if (!foundTimer)
    {
        if (c.statusLed(0))
            c.TurnOffLed(0);

        if (c.statusLed(1))
            c.TurnOffLed(1);
    }
   
}

bool GameLogic::isGameOver()
{
    if (_livesLeft < 0)
    {
        std::cout << _score;
        Sleep(500);
        return true;
    }
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
            bool typefound = false;
            if (!_powers[i]->getStackable())
            {
               
                for (int j = 0; j < _powers.size(); j++)
                {
                    if (_powers[i]->getName() == _powers[j]->getName() && j!=i && _powers[j]->getState()==Active)
                    {
                        _powers[j]->resetTimer();
                        UI[_powers[i]->getPos().y][_powers[i]->getPos().x] = ' ';
                        delete _powers[i];
                        _powers.erase(_powers.begin() + i);
                        typefound = true;
                        break;

                        
                    }
                        

                }
               
                    
            }
            
            if (!typefound)
            {
                _powers[i]->setPowerups(_balls, _platform, control);
                UI[_powers[i]->getPos().y][_powers[i]->getPos().x] = ' ';
            }
                
            
        }
    }
    for(int i=0; i< _balls.size();i++)
    {
        pos= _balls[i]->getPos();
        Velocity speed = _balls[i]->getSpeed();
        int rayon = _balls[i]->getrayon();
        _platform.checkCollision(_balls[i]);
        if (pos.y + rayon > maxSizeY && speed.y > 0) //check si mort 
        {
            //_balls[i]->changeVelocity(0, 1); //faire bounce dans le bas
            delete _balls[i];
            _balls.erase(_balls.begin()+i);
        }
        else
        {      
            //Balle *b = _balls[i];
            _level.checkCollision(_balls[i], _score,_powers);

            if (pos.y - rayon < 0 && speed.y < 0) //Hit  plafond
            {
                _balls[i]->changeVelocity(0, 1);//inverser direction de la balle en Y
            }

            //check walls collision
            if (pos.x - rayon < 0 && speed.x < 0)
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
            if(pos.x + rayon > maxSizeX - 1 && speed.x > 0)
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
        }
    }
    if(_balls.empty())
    {
        _livesLeft--;
        Sleep(350);
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