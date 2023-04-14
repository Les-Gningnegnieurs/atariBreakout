#ifndef CMAINWINDOW_H_
#define CMAINWINDOW_H_
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QRect>
#include <QStyle>
#include <QLabel>
#include <QGraphicsTextItem>
#include "Settings.h"
#include "MainMenu.h"
#include "MenuUtils.h"
#include "SelectLevel.h"
#include <QMessageBox>

#define W_RESOLUTION_X 1200
#define W_RESOLUTION_Y 800


class MainWindow : public QMainWindow {
	Q_OBJECT;
public:
	MainWindow();
	MainWindow(QApplication* app, QWidget* parent, QGraphicsScene* game, Menu * menu);

public slots:
	void showMenu();
	void showGame();
	void showSettings();
	void showSelectLevel();

signals:
	void startGame();




private:
	QGraphicsView* _view;
	QGraphicsScene* _menu;
	QGraphicsScene* _settings;
	QGraphicsScene* _game;
	QGraphicsScene* _selectLevel;
	Menu *_menuGame;
};
#endif