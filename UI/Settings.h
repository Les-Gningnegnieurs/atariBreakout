#ifndef CSETTINGS_H 
#define CSETTINGS_H 
#include <iostream>
#include <string>
#include "menu.h"
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QIcon>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QObject>
//#include "MenuUtils.h"

#define RESOLUTION_X 1200
#define RESOLUTION_Y 800

#define EXIT_WIDTH 50
#define EXIT_HEIGHT 50
#define MARGIN 50
class Settings : public QGraphicsScene
{
	Q_OBJECT;
public:
	Settings();
	Settings(QApplication* app, QWidget* parent = nullptr);

private:
	void initUI();
	QApplication* _app;
	QPushButton* _center[3];
	//MenuUtils* utils;
	int imageY = 0;
	QPushButton* _buttons[6];

public slots:
	void exit_clicked();
};

#endif