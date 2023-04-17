#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H

#include <QGraphicsScene>
#include "MenuUtils.h"
#include <QObject>
#include <QPointer>


class SelectLevel :public QGraphicsScene
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
	QPointer<MenuUtils> utils;


	int imageY = 0;

signals:
	void exit_click();
	void levelSelected(int _level);
public slots:
	void exit_clicked();
	void level1Requested();
	void level2Requested();
	void level3Requested();
	void level4Requested();
	void level5Requested();
	void level6Requested();

	
	





};

#endif