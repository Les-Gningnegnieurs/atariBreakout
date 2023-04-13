#include "Settings.h"


Settings::Settings() {

}

Settings::Settings(QApplication* app, QWidget* parent) : QGraphicsScene(parent) {
	setBackgroundBrush(Qt::black);
	utils = new MenuUtils(this,app);
	initUI();
	
	_app = app;

}

void Settings::initUI()
{
	QLabel* _controllers = utils->import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE_exits = add_exit(_settings);
	_controllers->move(RESOLUTION_X - _controllers->width() - MARGIN, RESOLUTION_Y - _controllers->height() - MARGIN);

	QPushButton*_exits = utils->add_exit();
	_exits->move(MARGIN, RESOLUTION_Y - _exits->height() - MARGIN);

	QWidget* temp;
	QLabel* lab = utils->import_image_up("image/title/settings_menu.png",1);
	imageY += lab->height();

	_buttons[0] = utils->add_button("playing_mode.png",temp);
	_buttons[0]->move(this->width() / 2 - _buttons[0]->width(), imageY);
	addWidget(_buttons[0]);
	_buttons[6] = utils->add_button("joystick.png", temp);
	_buttons[6]->move(this->width() / 2, imageY);
	addWidget(_buttons[6]);
	imageY += _buttons[0]->height();
	
	_buttons[1] = utils->add_button("COM.png", temp);
	_buttons[1]->move(this->width() / 2 - _buttons[1]->width(), imageY);
	addWidget(_buttons[1]);
	_buttons[7] = utils->add_button("joystick.png", temp);
	_buttons[7]->move(this->width() / 2, imageY);
	addWidget(_buttons[7]);
	imageY += _buttons[1]->height();
	
	_buttons[2] = utils->add_button("input.png", temp);
	_buttons[2]->move(this->width() / 2 - _buttons[2]->width(), imageY);
	imageY += _buttons[2]->height();
	addWidget(_buttons[2]);

	_buttons[3] = utils->add_center_button("apply.png");
	_buttons[3]->move(_buttons[3]->pos().x(), imageY);
	imageY += _buttons[3]->height();

	_buttons[4] = utils->add_button("load.png", temp);
	_buttons[4]->move(this->width() / 2 - _buttons[4]->width() - 50, imageY);
	addWidget(_buttons[4]);

	_buttons[5] = utils->add_button("save.png", temp);
	_buttons[5]->move(this->width() / 2 + 50, imageY);
	addWidget(_buttons[5]);

	 QObject::connect(_exits, &QPushButton::clicked, this, &Settings::exit_clicked);
	
}

void Settings::exit_clicked() {
	emit exit_click();
}