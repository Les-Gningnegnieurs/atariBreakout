#ifndef MAINMENU_H 
#define MAINMENU_H
#include <QGraphicsScene>
#include "application.h"
#include "MenuUtils.h"
#include "Settings.h"
class MainMenu:public QGraphicsScene
{
	Q_OBJECT
public:
	MainMenu(QApplication* app,QWidget*parent=nullptr): QGraphicsScene(parent){
		setBackgroundBrush(Qt::black);
		utils = new MenuUtils(this,app);
		initUI();
		_app = app;
		
	}

private:
	void initUI();
	QApplication* _app;
	QPushButton* _center[3];
	MenuUtils* utils;


	int imageY = 0;
public slots:
	void exit_clicked()
	{
		utils->set_as_sure();
	}
};

#endif