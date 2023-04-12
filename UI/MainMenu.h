//#ifndef MAINMENU_H 
//#define MAINMENU_H
//#include <QGraphicsScene>
//#include "application.h"
//#include "MenuUtils.h"
//#include "Settings.h"
//class MainMenu:public QGraphicsScene
//{
//	Q_OBJECT
//public:
//	MainMenu(QApplication* app, QWidget* parent = nullptr);
//
//private:
//	void initUI();
//	QApplication* _app;
//	QPushButton* _center[3];
//	MenuUtils* utils;
//
//
//	int imageY = 0;
//public slots:
//	void exit_clicked()
//	{
//		utils->set_as_sure();
//	}
//	void showSettingsUI() 
//	{
//		emit showSettingsRequested();
//	}
//	void showGameUI()
//	{
//		emit showGameRequested();
//	}
//	void showSelectLevelUI()
//	{
//		emit showSelectLevelRequested();
//	}
//
//signals:
//	void showSettingsRequested();
//	void showGameRequested();
//	void showSelectLevelRequested();
//
//
//	
//};
//
//#endif