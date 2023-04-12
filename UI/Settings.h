#ifndef SETTINGS_H 
#define SETTINGS_H 
#include <QGraphicsScene>
#include "application.h"
#include "MenuUtils.h"
class Settings : public QGraphicsScene
{
	Q_OBJECT
public:
	Settings(QApplication* app, QWidget* parent = nullptr) : QGraphicsScene(parent) {
		setBackgroundBrush(Qt::black);
		utils = new MenuUtils(this,app);
		initUI();
		_app = app;

	}

private:
	void initUI();
	QApplication* _app;
	QPushButton* _center[3];
	MenuUtils* utils;
	int imageY = 0;
	QPushButton* _buttons[6];

public slots:
	void exit_clicked()
	{
		
	}
};

#endif