#ifndef UI_MENU_CLASS
#define UI_MENU_CLASS

#include <iostream>
#include <string>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QIcon>
#include <QtWidgets>

#include <QObject>


#define RESOLUTION_X 1200
#define RESOLUTION_Y 800

#define EXIT_WIDTH 50
#define EXIT_HEIGHT 50
#define MARGIN 50

class Window : public QMainWindow
{
protected:
	int imageY = 0; // Position verticale de la prochaine image à ajouter
	QApplication* app;
	QWidget* centralWidget = new QWidget();
public:
	Window(QWidget* parent = nullptr) : QMainWindow(parent)
	{
		setStyleSheet("background-color: black;");
		setWindowTitle("Atari Breakout - P3");
		setWindowIcon(QIcon("image/icon.png"));
	}
	Window(QApplication* a, QWidget* parent = nullptr) : QMainWindow(parent)
	{
		app = a;
		setStyleSheet("background-color: black;");
		setWindowTitle("Atari Breakout - P3");
		setWindowIcon(QIcon("image/icon.png"));
	}

	QLabel* import_image_up(QString path);
	QPushButton* add_button(QString path);

	void set_as_sure();
	void set_as_paused();

};


class Menu_UI : public Window
{
protected:
	QPushButton* _exit;
	QPushButton* _center[3];
	QLabel* controller;
public:
	Menu_UI(QApplication* a);
	QPushButton* add_exit();
	QLabel* import_image(QString path);
	QPushButton* add_center_button(QString path);

	void set_as_main();
	void set_as_settings();
	void set_as_level();

public slots:
	void exit_clicked()
	{
		Window* win = new Window(app);
		win->set_as_sure();
		win->show();
	}


};
/*
class Settings_UI : public Menu_UI
{
public:
	Settings_UI();
};

class Level_UI : public Menu_UI
{
public:
	Level_UI();
};

class Main_UI : public Menu_UI
{
	
public:
	Main_UI(QApplication* a);
public slots:
	void exit_clicked()
	{
		Window* win = new Window(app);
		win->set_as_sure();
		win->show();
	}
	void level_clicked()
	{
		Level_UI* win = new Level_UI;
		win->show();
	}
	void settings_clicked()
	{
		Settings_UI * win = new Settings_UI;
		win->show();
	}
};
*/



#endif