#include "Myrect.h"
#include <QDebug>
void MyRect::keyPressEvent(QKeyEvent *event) {
	//qDebug() << "MyRect knows that you pressed a key";
	if (event->key() == Qt::Key_Left)
		setPos(x() - 10, y());
	else if (event->key() == Qt::Key_Right)
		setPos(x() + 10, y());

}