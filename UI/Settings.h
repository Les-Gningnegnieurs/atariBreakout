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
#include <QPointer>
#include "MenuUtils.h"



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
	QPointer<MenuUtils> utils;
	int imageY = 0;
	QPushButton* _buttons[9];
signals:
	void exit_click();
public slots:
	void exit_clicked();
};

#endif