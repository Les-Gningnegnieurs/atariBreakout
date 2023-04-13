#ifndef CSETTINGS_H 
#define CSETTINGS_H 
#include <iostream>
#include <string>
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
	QPushButton* _center[3];
	QPointer<MenuUtils> utils;
	int imageY = 0;
	QPushButton* _buttons[15];
	bool _playingMode;
	short _COM;
	bool _input;


signals:
	void exit_click();
	void load_click();
	void save_click();
	void apply_click();
public slots:
	void click()
	{
		if (_playingMode == 0)
		{
			_playingMode = 1;

			QPixmap pixmap("joystick.png"); // Charger l'image à partir du chemin d'image
			QIcon icon(pixmap); // Créer une icône à partir de la pixmap
			_buttons[0]->setIcon(icon); // Définir l'icône comme source d'image pour le bouton

		}
			

		else
		{
			_playingMode = 0;

			QPixmap pixmap("yes.png"); // Charger l'image à partir du chemin d'image
			QIcon icon(pixmap); // Créer une icône à partir de la pixmap
			_buttons[0]->setIcon(icon); // Définir l'icône comme source d'image pour le bouton
		}
	}
	void exit_clicked();
	void load_clicked();
	void save_clicked();
	void apply_clicked();
};

#endif