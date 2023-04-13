#include "SelectLevel.h"

void SelectLevel::initUI()
{
	QLabel* _controllers = utils->import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE_exits = add_exit(_settings);
	_controllers->move(RESOLUTION_X - _controllers->width() - MARGIN, RESOLUTION_Y - _controllers->height() - MARGIN);

	QPushButton* _exits = utils->add_exit();
	_exits->move(MARGIN, RESOLUTION_Y - _exits->height() - MARGIN);

	QWidget* temp;
	QLabel* lab = utils->import_image_up("image/title/select_level_menu.png", 1);
	imageY += lab->height();





	_images[0] = utils->add_button("ressources/steve.png", temp);
	_images[0]->move(this->width() / 4 - _images[0]->width() / 2, imageY);
	addWidget(_images[0]);

	_images[1] = utils->add_button("ressources/steve.png", temp);
	_images[1]->move((this->width() - _images[1]->width()) / 2, imageY);
	addWidget(_images[1]);

	_images[2] = utils->add_button("ressources/steve.png", temp);
	_images[2]->move(3 * this->width() / 4 - _images[0]->width() / 2, imageY);
	addWidget(_images[2]);
	imageY += _images[1]->height() + 50;

	_images[3] = utils->add_button("ressources/steve.png", temp);
	_images[3]->move(this->width() / 4 - _images[3]->width() / 2, imageY);
	addWidget(_images[3]);

	_images[4] = utils->add_button("ressources/steve.png", temp);
	_images[4]->move((this->width() - _images[4]->width()) / 2, imageY);
	addWidget(_images[4]);

	_images[5] = utils->add_button("ressources/steve.png", temp);
	_images[5]->move(3 * this->width() / 4 - _images[5]->width() / 2, imageY);
	addWidget(_images[5]);
	QObject::connect(_exits, &QPushButton::clicked, this, &SelectLevel::exit_clicked);



}

void SelectLevel::exit_clicked()
{
	emit exit_click();
}