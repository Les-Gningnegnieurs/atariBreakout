#include "GameOver.h"


GameOver::GameOver(QApplication* app, QWidget* parent) : QGraphicsScene(parent)
{
	setBackgroundBrush(Qt::black);
	_utils = new MenuUtils(this, app);
	_app = app;
	
	initUI();
}


void GameOver::initUI()
{
	QLabel* lab = _utils->import_image_up("image/title/gameOver.png", 1);
	int imageY = lab->height();
	int x = lab->pos().x() + lab->width() / 2;



	CustomButton* _button1 = _utils->add_button("replay.png", nullptr);
	_button1->move(x - _button1->width(), imageY);
	addWidget(_button1);
	CustomButton* _button2 = _utils->add_button("menu.png", nullptr);
	_button2->move(x + lab->width()/2 - _button2->width(), imageY);
	addWidget(_button2);


}