#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QRect>
#include <QStyle>

class MainWindow : public QMainWindow {
public:
	MainWindow(QWidget* parent, QGraphicsView* view, QGraphicsScene* scene);

	void showMenu();
	void showGame();
public slots:

private:
	int activeScene = 0; //menu : 0 | game : 1 ...

	QGraphicsView* _view;
	QGraphicsView* _menu;
	QGraphicsScene* _scene;
};
#endif