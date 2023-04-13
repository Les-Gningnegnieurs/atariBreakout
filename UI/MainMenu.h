#ifndef MAINMENU_H 
#define MAINMENU_H
#include <QGraphicsScene>
#include <QPointer>
#include <QObject>
#include "MenuUtils.h"
#include "Settings.h"


class MainMenu:public QGraphicsScene
{
	Q_OBJECT;
public:
	MainMenu(QApplication* app, QWidget* parent = nullptr);
	bool on_menu() { return menu_on; }
private:
	void initUI();
	QApplication* _app;
	QPushButton* _center[3];
	QPointer<MenuUtils> _utils;
	bool menu_on = true;


	int imageY = 0;
public slots:
	void exit_clicked()
	{
		_utils->set_as_sure();
	};
	void showSettingsUI()
	{
		emit showSettingsRequested();
	};
	void showGameUI()
	{
		emit showGameRequested();
		menu_on = false;
	};
	void showSelectLevelUI()
	{
		emit showSelectLevelRequested();
	};

signals:
	void showSettingsRequested();
	void showGameRequested();
	void showSelectLevelRequested();


	
};

#endif