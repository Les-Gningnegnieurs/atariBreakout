#ifndef MAINMENU_H 
#define MAINMENU_H
#include <QGraphicsScene>
#include "application.h"
class MainMenu:public QGraphicsScene
{
public:
	MainMenu(QApplication* app,QWidget*parent=nullptr): QGraphicsScene(parent){
		setBackgroundBrush(Qt::black);
		initUI();
		_app = app;
	}

private:
	void set_as_sure();

	void initUI();
	QApplication* _app;
	QLabel* import_image(QString path);
	QPushButton*add_exit();
	QLabel* import_image_up(QString path);
	QPushButton* add_center_button(QString path);
	QPushButton* _center[3];
	QPushButton* add_button(QString path, QWidget* widget);
	int imageY = 0;
public slots:
	void exit_clicked()
	{
		set_as_sure();
	}
};

#endif