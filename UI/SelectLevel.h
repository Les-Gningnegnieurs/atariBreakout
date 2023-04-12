#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H

#include <QGraphicsScene>
#include "application.h"
#include "MenuUtils.h"
#include <QObject>


class SelectLevel:public QGraphicsScene
{
	Q_OBJECT
public:
		SelectLevel(QApplication* app, QWidget* parent = nullptr) : QGraphicsScene(parent) {
		setBackgroundBrush(Qt::black);
		utils = new MenuUtils(this, app);
		initUI();
		_app = app;

	}

private:
	void initUI();
	QApplication* _app;
	QPushButton* _images[6];
	MenuUtils* utils;


	int imageY = 0;
public slots:
	void exit_clicked()
	{

	}





};

#endif