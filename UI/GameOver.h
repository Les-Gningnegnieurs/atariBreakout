#pragma once
#include <QGraphicsScene>
#include <QPointer>
#include <QObject>
#include "MenuUtils.h"
#include "Settings.h"
#include <QObject>

class GameOver : public QGraphicsScene
{
	Q_OBJECT
public:
	GameOver(QApplication* app, QWidget* parent = nullptr);
	void initUI();
private:
	QPointer<MenuUtils> _utils;
	QApplication* _app;

signals:
	void replayClick();
	void menuClick();

public slots:
	void replayRequested();
	void menuRequested();
};

