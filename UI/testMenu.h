#pragma once

#include <QObject>

class testMenu  : public QObject
{
	Q_OBJECT

public:
	testMenu(QObject *parent = nullptr);
	~testMenu();
};
