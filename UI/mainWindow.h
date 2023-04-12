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
#include "Settings.h"
//#include "MainMenu.h"

#define W_RESOLUTION_X 1200
#define W_RESOLUTION_Y 800

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
	MainWindow(QApplication* app, QWidget* parent, QGraphicsScene* game);

	void showMenu();
	void showGame();
private:
	QGraphicsView* _view;
	/*MainMenu* _menu;*/
	Settings* _settings;
	QGraphicsScene* _game;
};
#endif