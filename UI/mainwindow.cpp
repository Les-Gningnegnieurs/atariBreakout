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
	QObject::connect(_selectLevelTemp, &SelectLevel::level1Selected, this, &MainWindow::level1Selected);
	QObject::connect(_selectLevelTemp, &SelectLevel::level2Selected, this, &MainWindow::level2Selected);
	QObject::connect(_selectLevelTemp, &SelectLevel::level3Selected, this, &MainWindow::level3Selected);
	QObject::connect(_selectLevelTemp, &SelectLevel::level4Selected, this, &MainWindow::level4Selected);
	QObject::connect(_selectLevelTemp, &SelectLevel::level5Selected, this, &MainWindow::level5Selected);
	QObject::connect(_selectLevelTemp, &SelectLevel::level6Selected, this, &MainWindow::level6Selected);
	QObject::connect(_settingsTemp, &Settings::load_click, this, &MainWindow::loadConfig);
	QObject::connect(_settingsTemp, &Settings::apply_click, this, &MainWindow::applyConfig);
	QObject::connect(_settingsTemp, &Settings::save_click, this, &MainWindow::saveConfig);

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
	//setFixedSize(1200, 800);
	//_view->setFixedSize(1200, 800);
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

void MainWindow::level1Selected() {
	QMessageBox _text;
	_text.setText("Level 1 Selectionee");
	_text.exec();
}


void MainWindow::level2Selected() {
	QMessageBox _text;
	_text.setText("Level 2 Selectionee");
	_text.exec();
}



void MainWindow::level3Selected() {
	QMessageBox _text;
	_text.setText("Level 3 Selectionee");
	_text.exec();
}




void MainWindow::level4Selected() {
	QMessageBox _text;
	_text.setText("Level 4 Selectionee");
	_text.exec();
}



void MainWindow::level5Selected() {
	QMessageBox _text;
	_text.setText("Level 5 Selectionee");
	_text.exec();
}



void MainWindow::level6Selected() {
	QMessageBox _text;
	_text.setText("Level 6 Selectionee");
	_text.exec();
}
void MainWindow::applyConfig()
{
	QMessageBox _text;
	_text.setText("Configuration Appliquer");
	_text.exec();
}
void MainWindow::loadConfig() {
	QMessageBox _text;
	_text.setText("Configuration Charger");
	_text.exec();
}
void MainWindow::saveConfig() {
	QMessageBox _text;
	_text.setText("Configuration Sauvegarder");
	_text.exec();
}
