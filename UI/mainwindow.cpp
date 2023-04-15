#include "mainWindow.h"

MainWindow::MainWindow(){}

MainWindow::MainWindow(QApplication *app, QWidget* parent, QGraphicsScene* game,Menu*menu) : QMainWindow(parent) {
	_view = new QGraphicsView();
	_game = game;
	_menuGame = menu;

	_view->setParent(this);
	_game->setParent(this);
	QPointer<MainMenu> _menuTemp = new MainMenu(app, this);
	QPointer<SelectLevel> _selectLevelTemp = new SelectLevel(app, this);
	QPointer<Settings> _settingsTemp = new Settings(app, this);
	QPointer<GameOver> _gameOverTemp = new GameOver(app, this);



	_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setFixedSize(W_RESOLUTION_X, W_RESOLUTION_Y);
	setCentralWidget(_view);
	QObject::connect(_menuTemp, &MainMenu::showGameRequested, this, &MainWindow::showGame);
	QObject::connect(_menuTemp, &MainMenu::showSelectLevelRequested, this, &MainWindow::showSelectLevel);
	QObject::connect(_menuTemp, &MainMenu::showSettingsRequested, this, &MainWindow::showSettings);
	QObject::connect(_settingsTemp, &Settings::exit_click, this, &MainWindow::showMenu);
	QObject::connect(_selectLevelTemp, &SelectLevel::exit_click, this, &MainWindow::showMenu);
	QObject::connect(_selectLevelTemp, &SelectLevel::levelSelected, _menuGame, &Menu::levelRequested);
	QObject::connect(_settingsTemp, &Settings::apply_click, _menuGame, &Menu::updateSettingsRequested);
	QObject::connect(_settingsTemp, &Settings::comSelected, _menuGame, &Menu::comRequested);
	QObject::connect(_settingsTemp, &Settings::keyboardSelected, _menuGame, &Menu::keyboardModeRequested);
	QObject::connect(_settingsTemp, &Settings::controllerSelected, _menuGame, &Menu::controllerModeRequested);
	QObject::connect(_settingsTemp, &Settings::joystickSelected, _menuGame, &Menu::joystickModeRequested);
	QObject::connect(_settingsTemp, &Settings::accelSelected, _menuGame, &Menu::accelModeRequested);
	QObject::connect(_settingsTemp, &Settings::apply_click, _menuGame, &Menu::updateSettingsRequested);
	QObject::connect(_settingsTemp, &Settings::save_click, _menuGame, &Menu::saveSettingsRequested);
	QObject::connect(_settingsTemp, &Settings::load_click, _menuGame, &Menu::loadSettingsRequested);
	QObject::connect(_gameOverTemp, &GameOver::replayClick, this, &MainWindow::restartGameRequested);
	QObject::connect(_gameOverTemp, &GameOver::menuClick, this, &MainWindow::showMenu);
	QObject::connect(_menuGame, &Menu::connectionFailed, this, &MainWindow::connectionFailed);
	
	
	_gameOver = _gameOverTemp;
	_settings = _settingsTemp;
	_menu = _menuTemp;
	_selectLevel = _selectLevelTemp;
	showMenu();
	
	this->show();

	
}

void MainWindow::showMenu() {
	setFixedSize(RESOLUTION_X, RESOLUTION_Y);
	_view->setFixedSize(RESOLUTION_X, RESOLUTION_Y);
	_view->setScene(_menu);
}

void MainWindow::showGame() {
	//setFixedSize(1200, 800);
	//_view->setFixedSize(1200, 800);
	emit startGame();
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

void MainWindow::showGameOver()
{
	setFixedSize(1200, 800);
	_view->setFixedSize(1200, 800);
	_view->setScene(_gameOver);

}

void MainWindow::restartGameRequested()
{
	emit restartGame();
	_view->setScene(_game);
}

void MainWindow::connectionFailed()
{
	QMessageBox _text;
	_text.setText("Connection Echouer");
	_text.exec();
}