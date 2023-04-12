#include "Settings.h"

void Settings::initUI()
{
	QLabel* _controllers = utils->import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE_exits = add_exit(_settings);
	_controllers->move(RESOLUTION_X - _controllers->width() - MARGIN, RESOLUTION_Y - _controllers->height() - MARGIN);

	QPushButton*_exits = utils->add_exit();
	QWidget* temp;
	imageY = 50;
	utils->import_image_up("image/title/settings_menu.png");
	_buttons[0] = utils->add_button("image/unselected/playing_mode.png",temp);
	_buttons[0]->move(this->width() / 2 - _buttons[0]->width(), imageY);
	imageY += _buttons[0]->height();
	addWidget(_buttons[0]);
	_buttons[1] = utils->add_button("image/unselected/COM.png", temp);
	_buttons[1]->move(this->width() / 2 - _buttons[1]->width(), imageY);
	imageY += _buttons[1]->height();
	addWidget(_buttons[1]);

	_buttons[2] = utils->add_button("image/unselected/input.png", temp);
	_buttons[2]->move(this->width() / 2 - _buttons[2]->width(), imageY);
	imageY += _buttons[2]->height();
	addWidget(_buttons[2]);

	_buttons[3] = utils->add_center_button("image/unselected/apply.png");

	_buttons[4] = utils->add_button("image/unselected/load.png", temp);
	_buttons[4]->move(this->width() / 2 - _buttons[4]->width() - 50, imageY);
	addWidget(_buttons[4]);

	_buttons[5] = utils->add_button("image/unselected/save.png", temp);
	_buttons[5]->move(this->width() / 2 + 50, imageY);
	addWidget(_buttons[5]);

	 QObject::connect(_exits, &QPushButton::clicked, this, &Settings::exit_clicked);
	
}