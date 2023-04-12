#include "mainWindow.h"

MainWindow::MainWindow(QWidget* parent, QGraphicsView* view, QGraphicsScene* scene) : QMainWindow(parent) {
	_view = view;
	_scene = scene;

	_view->setParent(this);
	_scene->setParent(this);


	//menu
	QGraphicsScene* testScene = new QGraphicsScene(this);
	_menu = new QGraphicsView(testScene, this);

	this->setFixedSize(1200, 800);
	setCentralWidget(_view);
	this->show();

	////focus sur menu en premier
	//_scene->setFocus();
}

void MainWindow::showMenu() {
	setCentralWidget(_menu);
}

void MainWindow::showGame() {
	setCentralWidget(_view);
}