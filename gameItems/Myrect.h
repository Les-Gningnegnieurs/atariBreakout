#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsTextItem>

#include <QDebug>
#include <QFont>
#include <QColor>
class MyRect : public QGraphicsRectItem {
public:
	void keyPressEvent(QKeyEvent* event);

};

class Score : public QGraphicsTextItem {
public:
	Score(QGraphicsItem* parent = 0);
	void increase();
	void resetScore();
	int getScore();
	
private:
	int score;
};
class Health : public QGraphicsTextItem {
public:
	Health(QGraphicsItem* parent = 0);
	void decrease();
	int GetHealth();
private:
	int vies;
};

#endif MYRECT_H