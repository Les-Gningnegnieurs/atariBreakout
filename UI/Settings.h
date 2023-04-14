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

#define JOYSTICK 0
#define ACCELEROMETER 1
#define KEYBOARD 0
#define CONTROLLER 1


class Settings : public QGraphicsScene
{
	Q_OBJECT;
public:
	Settings();
	Settings(QApplication* app, QWidget* parent = nullptr);

private:
	void initUI();
	QApplication* _app;
	QGraphicsProxyWidget* proxy[15];
	QPointer<MenuUtils> utils;
	int imageY1, imageY2, imageY3, imageY4, imageY5 = 0;
	QPushButton* _buttons[15];
	bool _playingMode = 0;
	short _COM = 0;
	bool _input = 0;


signals:
	void exit_click();
	void load_click();
	void save_click();
	void apply_click();
	void accelSelected();
	void joystickSelected();
	void controllerSelected();
	void keyboardSelected();
	void comSelected(int _com);
	

public slots:
	void click_playingMode();
	void click_COM();
	void click_input();
	
	void exit_clicked();
	void load_clicked();
	void save_clicked();
	void apply_clicked();
};

#endif