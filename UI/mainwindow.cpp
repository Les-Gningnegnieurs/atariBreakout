#include "mainWindow.h"

MainWindow::MainWindow(QWidget* parent, QGraphicsView* view, QGraphicsScene* scene) : QMainWindow(parent) {
	_view = view;
	_scene = scene;

	_view->setParent(this);
	_scene->setParent(this);
	_game->setParent(this);
	
	QPointer<MainMenu> _menuTemp = new MainMenu(app,this);
	QPointer<Settings> _settingsTemp = new Settings(app,this);
	QPointer<SelectLevel> _selectLevelTemp=new SelectLevel(app,this);
	_settings = new Settings(app, this);
	_menu = new MainMenu(app, this);
	_selectLevel = new SelectLevel(app, this);


	this->setFixedSize(1200, 800);
	setCentralWidget(_view);


	QObject::connect(_menuTemp,&MainMenu::showGameRequested,this,&MainWindow::showGame);
	QObject::connect(_menuTemp, &MainMenu::showSettingsRequested, this, &MainWindow::showSettings);
	QObject::connect(_menuTemp, &MainMenu::showSelectLevelRequested, this, &MainWindow::showSelectLevel);
	QObject::connect(_settingsTemp, &Settings::exit_click, this, &MainWindow::showMenu);
	QObject::connect(_selectLevelTemp, &SelectLevel::exit_click, this, &MainWindow::showMenu);
	_menu = _menuTemp;
	_settings = _settingsTemp;
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
	_view->setScene(_menu);
}

void MainWindow::showGame() {
	_view->setScene(_game);
}

void MainWindow::showSelectLevel() {
	_view->setScene(_selectLevel);

}

void MainWindow::showSettings() {
	_view->setScene(_settings);
}