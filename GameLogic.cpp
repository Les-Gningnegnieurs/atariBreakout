#include "GameLogic.h"

GameLogic::GameLogic(QGraphicsScene* scene) : _scene(scene)
{
}

GameLogic:: GameLogic(LevelInfos i, QGraphicsScene* scene) : _scene(scene)
{
    _info = i;
    maxSizeX = _info.columns;
    maxSizeY = _info.rows;
    _livesLeft=3;
    _platform=Plateforme(_info, _scene);
   /* _plat = new  MyRect(i);
    _plat->setPos(i.pos_Plat_iniX, i.pos_Plat_iniY);
    _scene->addItem(_plat);*/
    //QPen pen(Qt::black);  // Create a black pen
    //pen.setWidth(50);      // Set the width of the pen to 2
    //pen.setStyle(Qt::SolidLine);  // Set the pen style to solid
    //QGraphicsLineItem* left_contour = new QGraphicsLineItem(0, 0, 0, i._windowResolutionY - 200);
    //QGraphicsLineItem* top_contour = new QGraphicsLineItem(0, 0, i._windowResolutionX, 0);
    //QGraphicsLineItem* right_contour = new QGraphicsLineItem(i._windowResolutionX - 50, 0, i._windowResolutionX - 50, i._windowResolutionY - 200);
    //left_contour->setPen(pen);
    //top_contour->setPen(pen);
    //right_contour->setPen(pen);
    //_scene->addItem(left_contour);
    //_scene->addItem(top_contour);
    //_scene->addItem(right_contour);
    QPixmap side("ressources/sides.png");
    QPixmap top("ressources/sidetop.png");
    QPixmap bot("ressources/sideBot.png");

    QGraphicsPixmapItem* side_left = new QGraphicsPixmapItem();
    side_left->setPixmap(side);
    side_left->setPos(0, 0);

    QGraphicsPixmapItem* side_right = new QGraphicsPixmapItem();
    side_right->setPixmap(side);
    side_right->setPos(1150, 0);

    QGraphicsPixmapItem* side_top = new QGraphicsPixmapItem();
    side_top->setPixmap(top);
    side_top->setPos(50, 0);

    QGraphicsPixmapItem* side_bot = new QGraphicsPixmapItem();
    side_bot->setPixmap(bot);
    side_bot->setPos(0, 650);

    _scene->addItem(side_left);
    _scene->addItem(side_right);
    _scene->addItem(side_top);
    _scene->addItem(side_bot);





    /*QGraphicsPixmapItem(QPixmap("ressources/sides.png")
    _scene->addItem(QGraphicsPixmapItem(QPixmap("ressources/sides.png")))
    _scene->addLine(25, 0, 25, i._windowResolutionY - 200, pen);
    _scene->addLine(0, 25, i._windowResolutionX, 25, pen);
    _scene->addLine(i._windowResolutionX - 25, 0, i._windowResolutionX - 25, i._windowResolutionY - 200,pen);*/

    Position posB;
    posB.x = i.pos_Ball_iniX;
    posB.y = i.pos_Ball_iniY;
    /*QGraphicsRectItem* rect_Left = new QGraphicsRectItem(0,0,50,i._windowResolutionY-200);
    rect_Left->setBrush(Qt::lightGray);
    QGraphicsRectItem* rect_Top = new QGraphicsRectItem(0, 0, i._windowResolutionX, 50);
    rect_Top->setBrush(Qt::lightGray);
    QGraphicsRectItem* rect_Right = new QGraphicsRectItem(i._windowResolutionX-50, 0, 50, i._windowResolutionY-200);
    rect_Right->setBrush(Qt::lightGray);
    _scene->addItem(rect_Left);
    _scene->addItem(rect_Top);
    _scene->addItem(rect_Right);*/

    _balls.push_back(new Balle(_info, _scene));
    QGraphicsTextItem* VIES = new QGraphicsTextItem();
    VIES->setPlainText(QString("Health: "));
    VIES->setDefaultTextColor(Qt::red);
    VIES->setFont(QFont("Helvetica", 14));
    VIES->setPos(10, i._windowResolutionY - 70);
    scene->addItem(VIES);
    _vies1 = new Health();
    _vies2 = new Health();
    _vies3 = new Health();
    _vies1->setPos(80, i._windowResolutionY - 70);
    _vies2->setPos(120, i._windowResolutionY - 70);
    _vies3->setPos(160, i._windowResolutionY - 70);
    scene->addItem(_vies1);
    scene->addItem(_vies2);
    scene->addItem(_vies3);

    QPixmap pixmap("ressources/scoreboard.png");
    QGraphicsPixmapItem* _scoreboard = new QGraphicsPixmapItem();
    _scoreboard->setPixmap(pixmap);
    _scoreboard->setPos(10, i._windowResolutionY - 140);
    scene->addItem(_scoreboard);
    _score = new Score();
    _score->setPos(30, i._windowResolutionY - 127);
    scene->addItem(_score);

    Plati* _bargraph = new Plati(200, 50, "ressources/bar3.png");
    _bargraph->setPos(450, i._windowResolutionY-110);
    _scene->addItem(_bargraph);
    init_virtual_bar();
    _level = new Level(_info, _score, _scene);

}
void GameLogic::init_virtual_bar() {
    int starting = 488;
    for (int j = 0; j < 20; j++)
    {
        array[j] = new QGraphicsRectItem(starting + (j * 15) + 2, _info._windowResolutionY - 104, 14, 35);
        array[j]->setBrush(Qt::red);
        _scene->addItem(array[j]);
        array[j]->hide();
    }
}
GameLogic::~GameLogic(){
    for (int i = 0; i < _powers.size(); i++)
    {
        delete _powers[i];
    }
    _balls.clear();
    delete _level;
}
void GameLogic::update2() {
    /*_plat->setFlag(QGraphicsItem::ItemIsFocusable);
    _plat->setFocus();*/
    _scene->setFocusItem(_platform.getplat());
}
void GameLogic:: update(Controller& c, bool accelmode)
{
    //move plateform
    if (accelmode)
        _platform.move(c.getAccelerometre().x);
    else
        _platform.move(c.getJoystick().x);
    _platform.update(); //update la position
    bool foundTimer = false;
        
    for (int i = 0; i < _powers.size(); i++)
    {
        _powers[i]->update();
        if (_powers[i]->getState() == Active && _powers[i]->getLedinfo().hasTimer && !foundTimer)
        {

            if (c.statusLed(0) || c.statusLed(1)) {
                c.setLED(0, 0, 0, 0, 0);
                c.setLED(1, 0, 0, 0, 0);
            }
            else {
                if (_powers[i]->getLedinfo().color == 'r') {
                    c.setLED(0, 1, 255, 0, 0);
                    c.setLED(1, 1, 255, 0, 0);
                }

                else if (_powers[i]->getLedinfo().color == 'g') {
                    c.setLED(0, 1, 0, 255, 0);
                    c.setLED(1, 1, 0, 255, 0);
                }
                else if (_powers[i]->getLedinfo().color == 'b') {
                    c.setLED(0, 1, 0, 0, 255);
                    c.setLED(1, 1, 0, 0, 255);
                }
            }
           
            foundTimer = true;
            
            //Logique a revoir
            int timer = _powers[i]->getTimer();
            int nbLeds = ((timer * 10) / PTIMELIMIT);
            nbLeds = nbLeds % 10;
            for (int i = 0; i < 10; i++)
            {
                if (nbLeds > i)
                    c.setBargraph(i, 0);
                //rajouter une methode qui va update les carrés rouges
                else
                    c.setBargraph(i, 1);
            }
            //setvirtualbargraph(c);
            setvirtualbargraph(c);

            c.setPower(true);
        }
        
        
        if (_powers[i]->getState() == Done || _powers[i]->getState() == OutOfBounds)
        {
            if (_powers[i]->getState() == Done)
                _powers[i]->resetPowerups(_balls, _platform, c);
            delete _powers[i];
           _powers.erase(_powers.begin() + i);
            reset_virtual_bargraph();
            
        }
    }
    //update Game / do logic
    //check les collisions une fois que les positions ont ete updatés
    for (int i = 0; i < _balls.size(); i++)
    {
        _balls[i]->update();
    }
    checkCollisions(c, accelmode);
    draw();
    if (!foundTimer)
    {
        if (c.statusLed(0))
            c.TurnOffLed(0);

        if (c.statusLed(1))
            c.TurnOffLed(1);
    }
   
}

void GameLogic::reset_virtual_bargraph() {
    for (int i = 0; i < 20; i++)
        array[i]->hide();
}

bool GameLogic::isGameOver()
{
    if (_livesLeft <= 0)
    {
        std::cout << _score->getScore();
        Sleep(500);
        return true;
    }
    else return false;
}
//Retirer les valeurs de limite hardcodé et enovyer balle en reference 
//dans les check collision pour utiliser leur vélocité pour savoir d'ou elles arrivent pour le check colision
//et determiner l'angle de renvoi
void GameLogic::checkCollisions(Controller &control, bool accelmode) {
    Position pos;

    for (int i = 0; i < _powers.size(); i++)
    {
        if (_powers[i]->getPos().y + _powers[i]->getHeight() >= _info._windowResolutionY - 110)
        {
            _powers[i]->setState(OutOfBounds);
            _powers[i]->hide_powerup();
        }
        
        if (_powers[i]->checkCollisions(_platform)) {
            bool typefound = false;
            if (!_powers[i]->getStackable())
            {
               
                for (int j = 0; j < _powers.size(); j++)
                {
                    if (_powers[i]->getName() == _powers[j]->getName() && j!=i && _powers[j]->getState()==Active)
                    {
                        _powers[j]->resetTimer();
                        //UI[_powers[i]->getPos().y][_powers[i]->getPos().x] = ' ';
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
                //UI[_powers[i]->getPos().y][_powers[i]->getPos().x] = ' ';
            }
                
            
        }
    }
    for(int i=0; i< _balls.size();i++)
    {
        pos= _balls[i]->getPos();
        Velocity speed = _balls[i]->getSpeed();
        int rayon = _balls[i]->getrayon();
        _platform.checkCollision(_balls[i]);
        if (pos.y + rayon*2 > _platform.getPos().y + _platform.getHeight() + 50 && speed.y > 0) //check si mort 
        {
            //_balls[i]->changeVelocity(0, 1); //faire bounce dans le bas
            delete _balls[i];
            _balls.erase(_balls.begin()+i);
        }
        else
        {      
            //Balle *b = _balls[i];
            _level->checkCollision(_balls[i],_powers, control);

            if (pos.y < 50 && speed.y < 0) //Hit  plafond
            {
                _balls[i]->changeVelocity(0, 1);//inverser direction de la balle en Y
            }

            //check walls collision
            if (pos.x < 50 && speed.x < 0)
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
            if(pos.x + rayon*2 > _info._windowResolutionX - 50 && speed.x > 0)
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
        }
    }
    if(_balls.empty())
    {
        if (!waiting)
        {
            _livesLeft--;
            if (_livesLeft == 2 && _vies3 != nullptr)
                delete _vies3;
            else if (_livesLeft == 1 && _vies2 != nullptr)
                delete _vies2;
            else if (_livesLeft == 0 && _vies1 != nullptr)
                delete _vies1;
        }
        Position posb; 
        //posb.x = _info.pos_Ball_iniX; 
        posb.y = _info.pos_Ball_iniY ;
        posb.x = _platform.getPos().x + _platform.getLenght()/2;
        waiting = true;
        if (control.getButton(0) == 1)
        {
            //control.receiveInputs();
            //if (accelmode)
            //    _platform.move(control.getAccelerometre().x);
            //else
            //    _platform.move(control.getJoystick().x);
            //_platform.update(); //update la position
            //_platform.draw();
            Balle* p1 = new Balle(_scene, posb, _info.ball_radius, _info.speed_B_x, _info.speed_B_y, control.getRand());
            _balls.push_back(p1);
            waiting = false;
        }
    }

}

int GameLogic::getScoreInfo() {
    return _score->getScore();
}

void GameLogic::draw() {
    _platform.draw(); //update le dessin dans le tableau
    

    for (int i = 0; i < _balls.size(); i++)
    {
        _balls[i]->draw();
    }

    for (int i = 0; i < _powers.size(); i++)
    {
        _powers[i]->draw();
    }

}

std::istream& operator>>(std::istream& s, GameLogic &gl){
    
    s >> *gl._level;
    return s;
 }


Plateforme& GameLogic::getPlaform() { return _platform; }

bool GameLogic::isCompleted() {
    if (_score->getScore() >= _level->getmaxScore())
        return true;
    return false;
}
void GameLogic::setvirtualbargraph(Controller& c) {
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (c.getBargraph().status[i] == 0)
        {
            array[i + j]->hide();
            array[i + 1 + j]->hide();
        }

        else
        {
            array[i + j]->show();
            array[i + 1 + j]->show();
        }
        j++;
    }
}
