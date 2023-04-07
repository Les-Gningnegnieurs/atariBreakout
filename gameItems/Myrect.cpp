#include "Myrect.h"

void MyRect::keyPressEvent(QKeyEvent *event) {
	//qDebug() << "MyRect knows that you pressed a key";
	if (event->key() == Qt::Key_Left)
		setPos(x() - 10, y());
	else if (event->key() == Qt::Key_Right)
		setPos(x() + 10, y());

}

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
	score = 0;
	setPlainText(QString("Score: ") + QString::number(score));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("Helvetica", 14));
}
void Score::increase() {
	score++;
}
void Score::resetScore() {
	score = 0;
}
int Score::getScore() {
	return score;
}
Health::Health(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
	vies = 3;
	setPlainText(QString("Health: ") + QString::number(vies));
	setDefaultTextColor(Qt::red);
	setFont(QFont("Helvetica", 14));
}
void Health::decrease() {
	vies--;
}
int Health::GetHealth() {
	return vies;
}