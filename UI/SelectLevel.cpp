#include "SelectLevel.h"

void SelectLevel::initUI()
{
	QLabel* _controllers = utils->import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE_exits = add_exit(_settings);
	_controllers->move(RESOLUTION_X - _controllers->width() - MARGIN, RESOLUTION_Y - _controllers->height() - MARGIN);

	QPushButton* _exits = utils->add_exit();
	_exits->move(MARGIN, RESOLUTION_Y - _exits->height() - MARGIN);

	QWidget* temp;
	QLabel* lab = utils->import_image_up("image/title/select_level_menu.png", 1);
	imageY += lab->height()+100;


	int offset = 50;


	_images[0] = utils->add_button("ressources/level_1.png", temp);
	_images[0]->move(this->width() / 5  - _images[0]->width() / 2 +offset, imageY);
	addWidget(_images[0]);
	QObject::connect(_images[0], &QPushButton::clicked, this, &SelectLevel::level1Requested);

	_images[1] = utils->add_button("ressources/level_2.png", temp);
	_images[1]->move((this->width() - _images[1]->width()) / 2 + offset, imageY);
	addWidget(_images[1]);
	QObject::connect(_images[1], &QPushButton::clicked, this, &SelectLevel::level2Requested);


	_images[2] = utils->add_button("ressources/level_3.png", temp);
	_images[2]->move(4 * this->width() / 5 - _images[0]->width() / 2 + offset, imageY);
	addWidget(_images[2]);
	QObject::connect(_images[2], &QPushButton::clicked, this, &SelectLevel::level3Requested);

	imageY += _images[1]->height() + 50;

	_images[3] = utils->add_button("ressources/level_4.png", temp);
	_images[3]->move(this->width() / 5 - _images[3]->width() / 2 + offset, imageY);
	addWidget(_images[3]);
	QObject::connect(_images[3], &QPushButton::clicked, this, &SelectLevel::level4Requested);


	_images[4] = utils->add_button("ressources/level_5.png", temp);
	_images[4]->move((this->width() - _images[4]->width()) / 2 + offset, imageY);
	QObject::connect(_images[4], &QPushButton::clicked, this, &SelectLevel::level5Requested);

	addWidget(_images[4]);

	_images[5] = utils->add_button("ressources/level_1.png", temp);
	_images[5]->move(4* this->width() / 5 - _images[5]->width() / 2 + offset, imageY);
	addWidget(_images[5]);
	QObject::connect(_images[5], &QPushButton::clicked, this, &SelectLevel::level6Requested);

	QObject::connect(_exits, &QPushButton::clicked, this, &SelectLevel::exit_clicked);



}

void SelectLevel::exit_clicked()
{
	emit exit_click();
}


void SelectLevel::level1Requested()
{
	emit level1Selected();
}

void SelectLevel::level2Requested()
{
	emit level2Selected();

}
void SelectLevel::level3Requested()
{
	emit level3Selected();

}
void SelectLevel::level4Requested()
{
	emit level4Selected();

}
void SelectLevel::level5Requested()
{
	emit level5Selected();

}
void SelectLevel::level6Requested()
{
	emit level6Selected();

}