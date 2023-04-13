#include "mainWindow.h"

MainWindow::MainWindow(){}

MainWindow::MainWindow(QApplication *app, QWidget* parent, QGraphicsScene* game) : QMainWindow(parent) {
	_view = new QGraphicsView();
	_game = game;

	_view->setParent(this);
	_game->setParent(this);
	QPointer<MainMenu> _menuTemp = new MainMenu(app, this);
	QPointer<SelectLevel> _selectLevelTemp = new SelectLevel(app, this);
	QPointer<Settings> _settingsTemp = new Settings(app, this);



	_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setFixedSize(W_RESOLUTION_X, W_RESOLUTION_Y);
	setCentralWidget(_view);
	QObject::connect(_menuTemp, &MainMenu::showGameRequested, this, &MainWindow::showGame);
	QObject::connect(_menuTemp, &MainMenu::showSelectLevelRequested, this, &MainWindow::showSelectLevel);
	QObject::connect(_menuTemp, &MainMenu::showSettingsRequested, this, &MainWindow::showSettings);
	QObject::connect(_settingsTemp, &Settings::exit_click, this, &MainWindow::showMenu);
	QObject::connect(_selectLevelTemp, &SelectLevel::exit_click, this, &MainWindow::showMenu);

	_settings = _settingsTemp;
	_menu = _menuTemp;
	_selectLevel = _selectLevelTemp;
	showMenu();
	//showGame();
	//showSettings();
	//showSelectLevel();
	this->show();

	////focus sur menu en premier
	//_scene->setFocus();
}

void MainWindow::showMenu() {
	setFixedSize(RESOLUTION_X, RESOLUTION_Y);
	_view->setFixedSize(RESOLUTION_X, RESOLUTION_Y);
	_view->setScene(_menu);
}

void MainWindow::showGame() {
	setFixedSize(1200, 800);
	_view->setFixedSize(1200, 800);
	_view->setScene(_game);
}

void MainWindow::showSettings() {
	setFixedSize(1200, 800);
	_view->setFixedSize(1200, 800);
	_view->setScene(_settings);
}

void MainWindow::showSelectLevel() {
	setFixedSize(1200, 800);
	_view->setFixedSize(1200, 800);
	_view->setScene(_selectLevel);
}