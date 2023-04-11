#include "mainWindow.h"

MainWindow::MainWindow(QGraphicsScene* scene, QGraphicsScene* menu) {
	_scene = scene;
	_menu = menu;

	this->setFixedSize(1000, 800);
	this->show();

	//focus sur menu en premier
	_menu->setFocus();
}

void MainWindow::showMenu() {
	//show menu

	//hide game
}

void MainWindow::showGame() {
	//show game

	//hide menu
}