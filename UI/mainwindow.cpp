#include "mainWindow.h"

MainWindow::MainWindow(){}

MainWindow::MainWindow(QApplication *app, QWidget* parent, QGraphicsScene* game,Menu*menu) : QMainWindow(parent) {
	_view = new QGraphicsView();
	_game = game;
	_menuGame = menu;
	_app = app;
	setWindowIcon(QIcon("image/icon.png"));
	_menuPause = nullptr;

	_view->setParent(this);
	_game->setParent(this);
	QPointer<MainMenu> _menuTemp = new MainMenu(app, this);
	QPointer<SelectLevel> _selectLevelTemp = new SelectLevel(app, this);
	QPointer<Settings> _settingsTemp = new Settings(app, this);
	QPointer<GameOver> _gameOverTemp = new GameOver(app, _score, this);
	QPointer<GameCompleted> _gameCompletedTemp = new GameCompleted(app, _score, this);



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
	QObject::connect(_selectLevelTemp, &SelectLevel::levelSelected, this, &MainWindow::levelConfirm);

	QObject::connect(_settingsTemp, &Settings::apply_click, _menuGame, &Menu::updateSettingsRequested);
	QObject::connect(_settingsTemp, &Settings::comSelected, _menuGame, &Menu::comRequested);
	QObject::connect(_settingsTemp, &Settings::keyboardSelected, _menuGame, &Menu::keyboardModeRequested);
	QObject::connect(_settingsTemp, &Settings::controllerSelected, _menuGame, &Menu::controllerModeRequested);
	QObject::connect(_settingsTemp, &Settings::joystickSelected, _menuGame, &Menu::joystickModeRequested);
	QObject::connect(_settingsTemp, &Settings::accelSelected, _menuGame, &Menu::accelModeRequested);
	
	QObject::connect(_settingsTemp, &Settings::save_click, _menuGame, &Menu::saveSettingsRequested);
	QObject::connect(_settingsTemp, &Settings::load_click, _menuGame, &Menu::loadSettingsRequested);
	QObject::connect(_settingsTemp, &Settings::save_click, this, &MainWindow::buttonConfirm);
	QObject::connect(_settingsTemp, &Settings::load_click, this, &MainWindow::buttonConfirm);
	QObject::connect(_settingsTemp, &Settings::apply_click, this, &MainWindow::buttonConfirm);
	QObject::connect(_gameOverTemp, &GameOver::replayClick, this, &MainWindow::restartGameRequested);
	QObject::connect(_gameOverTemp, &GameOver::menuClick, this, &MainWindow::showMenu);
	QObject::connect(_menuGame, &Menu::connectionFailed, this, &MainWindow::connectionFailed);
	QObject::connect(_gameCompletedTemp, &GameCompleted::nextLevelClick, this, &MainWindow::nextLevel);
	QObject::connect(_gameCompletedTemp, &GameCompleted::menuClick, this, &MainWindow::showMenu);

	_gameOver = _gameOverTemp;
	_settings = _settingsTemp;
	_menu = _menuTemp;
	_selectLevel = _selectLevelTemp;
	_gameCompleted = _gameCompletedTemp;
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

void MainWindow::showGameOver(int a)
{
	_score = "Score : " + QString::number(a);
	QPointer<GameOver> _gameOverTemp = new GameOver(_app, _score, this);
	QObject::connect(_gameOverTemp, &GameOver::replayClick, this, &MainWindow::restartGameRequested);
	QObject::connect(_gameOverTemp, &GameOver::menuClick, this, &MainWindow::showMenu);
	delete _gameOver;
	_gameOver = _gameOverTemp;

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


void MainWindow::buttonConfirm()
{
	QMessageBox _text;
	_text.setText("Succes");
	_text.exec();

}

void MainWindow::levelConfirm(int x)
{
	std::string s = "Niveau " + std::to_string(x) + " selectionee";

	QMessageBox _text;
	_text.setText(QString::fromStdString(s));
	_text.exec();

}
void MainWindow::nextLevel()
{
	_menuGame->Set_Level(_menuGame->Get_Level() + 1);
	showGame();
}


void MainWindow::showGameCompleted(int x)
{
	_score = "Score final : " + QString::number(x);
	QPointer<GameCompleted> _gameCompletedTemp = new GameCompleted(_app, _score, this);
	QObject::connect(_gameCompletedTemp, &GameCompleted::nextLevelClick, this, &MainWindow::nextLevel);
	QObject::connect(_gameCompletedTemp, &GameCompleted::menuClick, this, &MainWindow::showMenu);
	delete _gameCompleted;
	_gameCompleted = _gameCompletedTemp;

	setFixedSize(1200, 800);
	_view->setFixedSize(1200, 800);
	_view->setScene(_gameCompleted);

}



void MainWindow::showPauseMenu(int x)
{
	if (_menuPause != nullptr)
		delete _menuPause;
	_score = "Score : " + QString::number(x);
	QPointer<MenuPause> menuPauseTemp = new MenuPause(_app, _score, this);
	QObject::connect(menuPauseTemp, &MenuPause::resumeClick, this, &MainWindow::resumeGameRequested);
	QObject::connect(menuPauseTemp, &MenuPause::menuClick, this, &MainWindow::showMenu);
	_menuPause = menuPauseTemp;

	setFixedSize(1200, 800);
	_view->setFixedSize(1200, 800);
	_view->setScene(_menuPause);

}

void MainWindow::resumeGameRequested()
{
	_view->setScene(_game);
	emit resumeGame();

}