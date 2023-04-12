//#include "MainMenu.h"
//
//MainMenu::MainMenu(QApplication* app, QWidget* parent) : QGraphicsScene(parent) {
//	setBackgroundBrush(Qt::black);
//	utils = new MenuUtils(this, app);
//	initUI();
//	_app = app;
//
//}
//
//void MainMenu:: initUI()
//{
//	//// CREATING MAIN
//	QLabel*_controllerm = utils->import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE
//	_controllerm->move(RESOLUTION_X - _controllerm->width() - MARGIN, RESOLUTION_Y - _controllerm->height() - MARGIN);
//
//	QPushButton*_exitm = utils->add_exit();
//	 imageY = 100;
//	QLabel* im1 = utils->import_image_up("image/title/logo.png",1);
//	QLabel* im2 = utils->import_image_up("image/title/team.png",1);
//	_center[0] = utils->add_center_button("image/unselected/play_game.png");
//	_center[1] = utils->add_center_button("image/unselected/select_level.png");
//	_center[2] = utils->add_center_button("image/unselected/settings.png");
//
//
//	QObject::connect(_exitm, &QPushButton::clicked, this, &MainMenu::exit_clicked);
//	QObject::connect(_center[0], &QPushButton::clicked, this, &MainMenu::showGameUI);
//	QObject::connect(_center[1], &QPushButton::clicked, this, &MainMenu::showSelectLevelUI);
//	QObject::connect(_center[2], &QPushButton::clicked, this, &MainMenu::showSettingsUI);
//
//}
//
////int main(int argc,char *argv[])
////{
////	QApplication app(argc, argv);
////	QGraphicsView* mainwindow = new QGraphicsView;
////	MainMenu* menu = new MainMenu(&app);
////	Settings* settings = new Settings(&app);
////	mainwindow->setScene(menu);
////
////	mainwindow->resize(RESOLUTION_X, RESOLUTION_Y);
////	mainwindow->show();
////	return app.exec();
////}