#include "Testballe.h"
#include <QTimer>
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
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(50);
}
void testBalle::checkCollisions() {
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if (pos().y() > 650)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Briquetest) || typeid(*(colliding_items[i])) == typeid(BriqueB)
            || typeid(*(colliding_items[i])) == typeid(BriqueC) || typeid(*(colliding_items[i])) == typeid(BriqueT))
        {
            speed.y *= -1;
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(QGraphicsRectItem))//collision murs côté *Créer un nouveau type de myrect pour le top
            speed.x *= -1;
        if (typeid(*(colliding_items[i])) == typeid(MyRect)) {  //collision plateforme
            speed.y *= -1;
        }

        
    }
}
void testBalle::move() {
    checkCollisions();
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