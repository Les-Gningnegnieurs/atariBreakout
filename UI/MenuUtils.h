#ifndef MENUUTILS_H
#define MENUUTILS_H
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QApplication>
#include "CustomButton.h"


#define EXIT_WIDTH 50
#define EXIT_HEIGHT 50
#define MARGIN 50
#define RESOLUTION_X 1200
#define RESOLUTION_Y 800


class MenuUtils : public QObject {
	Q_OBJECT;
public:
	MenuUtils(QWidget* parent = nullptr);
	MenuUtils(QGraphicsScene* scene, QApplication* app, QWidget* parent = nullptr);
	QLabel* import_image(QString path);
	CustomButton* add_exit();
	QLabel* import_image_up(QString path, bool add);
	CustomButton* add_center_button(QString path);
	CustomButton* add_button(QString path, QWidget* widget);
	void set_as_sure();
private:
	QGraphicsScene* _scene;
	QApplication* _app;
	int imageY = 0;
};


#endif