#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QString>
#include <QRect>
#include <QStyle>

class MainWindow : public QMainWindow {
public:
	MainWindow(QGraphicsScene* scene, QGraphicsScene* menu);

	void showMenu();
	void showGame();
public slots:

private:
	int activeScene = 0; //menu : 0 | game : 1 ...

	QGraphicsScene* _scene;
	QGraphicsScene* _menu;
};
#endif