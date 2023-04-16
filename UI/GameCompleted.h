#pragma once
#include <QGraphicsScene>
#include <QPointer>
#include <QObject>
#include "MenuUtils.h"
#include "Settings.h"
#include <QObject>

class GameCompleted : public QGraphicsScene
{
	Q_OBJECT
public:
	GameCompleted(QApplication* app, QString score, QWidget* parent = nullptr);
	void initUI();
private:
	QPointer<MenuUtils> _utils;
	QApplication* _app;
	QString _score;

signals:
	void nextLevelClick();
	void menuClick();

public slots:
	void nextlevelRequested();
	void menuRequested();
};

