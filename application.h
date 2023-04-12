//#ifndef UI_MENU_CLASS
//#define UI_MENU_CLASS
//
//#include <iostream>
//#include <string>
//#include "menu.h"
//#include <QApplication>
//#include <QMainWindow>
//#include <QWidget>
//#include <QLabel>
//#include <QPushButton>
//#include <QHBoxLayout>
//#include <QSpacerItem>
//#include <QIcon>
//#include <QtWidgets>
//#include <QGraphicsScene>
//
//#include <QObject>
//
//
//#define RESOLUTION_X 1200
//#define RESOLUTION_Y 800
//
///*
//class Window : public QGraphicsScene
//{
//protected:
//	Menu* _menu;
//	int imageY = 0; // Position verticale de la prochaine image à ajouter
//	QApplication* app;
//public:
//	Window(QWidget* parent = nullptr) : QGraphicsScene(parent)
//	{
//		setBackgroundBrush(Qt::black);
//	}
//	Window(QApplication* a, QWidget* parent = nullptr) : QGraphicsScene(parent)
//	{
//		app = a;
//		setBackgroundBrush(Qt::black);
//	}
//
//	QLabel* import_image_up(QString path, QWidget* widget);
//	QPushButton* add_button(QString path, QWidget* widget);
//
//	void set_as_sure();
//	void set_as_paused();
//
//};
//
//
//class Menu_UI : public Window
//{
//protected:
//	QStackedWidget* stackedWidget = new QStackedWidget(this);
//
//	// for main
//	QWidget* _main = new QWidget();
//	QLabel* _controllerm; 
//	QPushButton* _exitm;
//	QPushButton* _center[3];
//	
//	//for level
//	QWidget* _level = new QWidget();
//	QLabel* _controllerl;
//	QPushButton* _exitl;
//
//	//for settings
//	QWidget* _settings = new QWidget();
//	QLabel* _controllers;
//	QPushButton* _exits;
//	QPushButton* _buttons[6];
//public:
//	Menu_UI(QApplication* a, Menu* m);
//	QPushButton* add_exit(QWidget* widget);
//	QLabel* import_image(QString path, QWidget* widget);
//	QPushButton* add_center_button(QString path, QWidget* widget);
//
//	void set_as_main();
//	void set_as_settings();
//	void set_as_level();
//
//public slots:
//	void exit_clicked()
//	{
//		QMainWindow* win = new QMainWindow();
//		win->show();
//	}
//	void level_clicked()
//	{
//		set_as_level();
//	}
//	void settings_clicked()
//	{
//		set_as_settings();
//	}
//	void exits()
//	{
//		set_as_main();
//	}
//
//};
//
//*/
//#endif
