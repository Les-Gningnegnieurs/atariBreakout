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
		if (!(pos().x() - 50 > 0))
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
Plati::Plati(LevelInfos I) {
	setPos(0, 0);
	QPixmap pixmap("ressources/bar1.png");
	QPixmap scaledPixmap = pixmap.scaled(I.Plat_length, I.Plat_heigth, Qt::KeepAspectRatioByExpanding);
	setPixmap(scaledPixmap);  
}

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
	score = 0;
	setPlainText(QString("Score: ") + QString::number(score));
	setDefaultTextColor(Qt::black);
	QFont font("Ad Lib BT", 14);
	font.setBold(true);
	setFont(font);
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
	QPixmap pixmap("ressources/heart2.png");
	QPixmap scaledPixmap = pixmap.scaled(26, 26, Qt::KeepAspectRatioByExpanding);
	setPixmap(scaledPixmap);
	//voici comment render une image provenant du fichier ressource
	//QImage* im = new QImage(":/game/ui/heart");
}
void Health::decrease() {
	vies--;
}
int Health::GetHealth() {
	return vies;
}
