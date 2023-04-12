// Q_OBJECT
#include "Myrect.h"
MyRect::MyRect(LevelInfos I) {
	Window_X = I._windowResolutionX;
	Window_Y = I._windowResolutionY;
	sizeX = I.Plat_length;
	sizeY = I.Plat_heigth;
	rows = I.rows;
	setRect(0, 0, sizeX, sizeY);
	columns = I.columns;
	posPlat.x = I.pos_Plat_iniX;
	posPlat.y = I.pos_Plat_iniY;
	setBrush(Qt::gray); 
}
void MyRect::keyPressEvent(QKeyEvent *event) {
	//qDebug() << "MyRect knows that you pressed a key";
	if (event->key() == Qt::Key_Left)
	{
		//qDebug() << pos().x();
		if (!(pos().x() - 50 > 0));
		{
			setPos(x() - 10, y());
		}
	}
	else if (event->key() == Qt::Key_Right)
	{
		if(pos().x() + sizeX < Window_X-50)
			setPos(x() + 10, y());
	}

}

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
	score = 0;
	setPlainText(QString("Score: ") + QString::number(score));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("Helvetica", 14));
}
void Score::increase() {
	score+=100;
	setPlainText(QString("Score: ") + QString::number(score));
}
void Score::resetScore() {
	score = 0;
}
int Score::getScore() {
	return score;
}
Health::Health(QGraphicsPixmapItem* parent) : QGraphicsPixmapItem(parent) {
	vies = 3;
	setPixmap(QPixmap("ressources/heart.png"));
	//setPlainText(QString("Health: ") + QString::number(vies));
	//setDefaultTextColor(Qt::red);
	//setFont(QFont("Helvetica", 14));

	//voici comment render une image provenant du fichier ressource
	//QImage* im = new QImage(":/game/ui/heart");
}
void Health::decrease() {
	vies--;
}
int Health::GetHealth() {
	return vies;
}
