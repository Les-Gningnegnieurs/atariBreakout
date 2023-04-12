#ifndef MENUUTILS_H
#define MENUUTILS_H
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QGraphicsScene>
#include "application.h" 
class MenuUtils {
public:
	MenuUtils(){}
	MenuUtils(QGraphicsScene * scene) { _scene = scene; }
	QLabel* import_image(QString path);
	QPushButton* add_exit();
	QLabel* import_image_up(QString path);
	QPushButton* add_center_button(QString path);
	QPushButton* add_button(QString path, QWidget* widget);
private:
	QGraphicsScene * _scene;
	int imageY = 0;

};

#endif