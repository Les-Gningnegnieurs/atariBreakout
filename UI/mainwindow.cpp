#include "mainWindow.h"

MainWindow::MainWindow(QGraphicsScene* scene, QGraphicsScene* menu) {
	_scene = scene;
	_menu = menu;

	this->setFixedSize(1200, 750);
	this->show();

	//focus sur menu en premier
	_scene->setFocus();
}

void MainWindow::showMenu() {
	//show menu

	//hide game
}

void MainWindow::showGame() {
	//show game

	//hide menu
}