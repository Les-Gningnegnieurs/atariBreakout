#include "Testballe.h"
#include <QTimer>
#include <QDebug>
// Q_OBJECT
testBalle::testBalle(LevelInfos I) {
	setRect(0, 0, 10, 10);
    _Position.x = I.pos_Ball_iniX;
    _Position.y = I.pos_Ball_iniY;
    oldPosX = _Position.x;
    oldPosY = _Position.y;
    speed.y = I.speed_B_y;
    speed.x = I.speed_B_x;
    rayon = I.ball_radius;
    setBrush(Qt::magenta);
	/*QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(50);*/
}
bool testBalle::checkCollisions() {
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if (pos().y() > 650)
    {
        scene()->removeItem(this);
        return true;
    }
        for (int i = 0, n = colliding_items.size(); i < n; i++) {
            if (typeid(*(colliding_items[i])) == typeid(Briquetest) || typeid(*(colliding_items[i])) == typeid(BriqueB)
                || typeid(*(colliding_items[i])) == typeid(BriqueC) || typeid(*(colliding_items[i])) == typeid(BriqueT))
            {
                // check if ball hit the sides of the brick
                if (oldPosX + rayon < colliding_items[i]->pos().x() || oldPosX + rayon > colliding_items[i]->pos().x() + colliding_items[i]->boundingRect().width())
                {
                    speed.x *= -1;
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                }
                // check if ball hit the top or bottom of the brick
                else if (oldPosY + rayon  < colliding_items[i]->pos().y() || oldPosY > colliding_items[i]->pos().y() + colliding_items[i]->boundingRect().height())
                {
                    speed.y *= -1;
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                }
            }
            else if (typeid(*(colliding_items[i])) == typeid(QGraphicsRectItem))//collision murs côté *Créer un nouveau type de myrect pour le top
            {
                {
                    // check if ball hit the sides of the brick
                    if (oldPosX + rayon  < colliding_items[i]->pos().x() || oldPosX+rayon > colliding_items[i]->pos().x() + colliding_items[i]->boundingRect().width())
                    {
                        speed.x *= -1;
                   
                    }
                    // check if ball hit the top or bottom of the brick
                    else if (oldPosY + rayon  < colliding_items[i]->pos().y() || oldPosY > colliding_items[i]->pos().y() + colliding_items[i]->boundingRect().height())
                    {
                        speed.y *= -1;
                     
                    }
                }
            }
            else if (typeid(*(colliding_items[i])) == typeid(MyRect)) {  //collision plateforme
                if (pos().x() + rayon < colliding_items[i]->pos().x() + colliding_items[i]->boundingRect().width() / 2 && speed.x>0)
                    speed.x *= -1;
                speed.y *= -1;
            }
        }
        return false;
}
void testBalle::move() {
    if (checkCollisions())
    {
        delete this;
        return;
    }
    else {
        int speedX;
        int speedY;
        speedX = 1 * speed.x;
        speedY = 1 * speed.y;
        oldPosX = _Position.x;
        oldPosY = _Position.y;

        _Position.x += speedX;
        _Position.y += speedY;
        setPos(_Position.x, _Position.y);
    }
}