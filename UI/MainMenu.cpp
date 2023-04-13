#include "MainMenu.h"

MainMenu::MainMenu(QApplication* app, QWidget* parent) : QGraphicsScene(parent) {
	setBackgroundBrush(Qt::black);
	_utils = new MenuUtils(this, app);
	initUI();
	_app = app;

}

void MainMenu:: initUI()
{
	//// CREATING MAIN
	QLabel*_controllerm = _utils->import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE
	_controllerm->move(RESOLUTION_X - _controllerm->width() - MARGIN, RESOLUTION_Y - _controllerm->height() - MARGIN);

	QPushButton*_exitm = _utils->add_exit();
	_exitm->move(MARGIN, RESOLUTION_Y - _exitm->height() - MARGIN);

	 imageY = 100;
	QLabel* im1 = _utils->import_image_up("image/title/logo.png",1);
	QLabel* im2 = _utils->import_image_up("image/title/team.png",1);
	_center[0] = _utils->add_center_button("image/unselected/play_game.png");
	_center[1] = _utils->add_center_button("image/unselected/select_level.png");
	_center[2] = _utils->add_center_button("image/unselected/settings.png");


	QObject::connect(_exitm, &QPushButton::clicked, this, &MainMenu::exit_clicked);
	QObject::connect(_center[0], &QPushButton::clicked, this, &MainMenu::showGameUI);
	QObject::connect(_center[1], &QPushButton::clicked, this, &MainMenu::showSelectLevelUI);
	QObject::connect(_center[2], &QPushButton::clicked, this, &MainMenu::showSettingsUI);

}

