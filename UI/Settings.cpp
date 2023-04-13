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
	imageY1 = lab->height();

	_buttons[0] = utils->add_button("playing_mode.png",temp);
	_buttons[0]->move(this->width() / 2 - _buttons[0]->width(), imageY1);
	addWidget(_buttons[0]);
	_buttons[6] = utils->add_button("joystick.png", temp);
	_buttons[6]->move(this->width() / 2, imageY1);
	addWidget(_buttons[6]);
	imageY2 = imageY1 + _buttons[0]->height();
	
	_buttons[1] = utils->add_button("COM.png", temp);
	_buttons[1]->move(this->width() / 2 - _buttons[1]->width(), imageY2);
	addWidget(_buttons[1]);
	_buttons[7] = utils->add_button("1.png", temp);
	_buttons[7]->move(this->width() / 2, imageY2);
	addWidget(_buttons[7]);
	imageY3 = imageY2 + _buttons[1]->height();
	
	_buttons[2] = utils->add_button("input.png", temp);
	_buttons[2]->move(this->width() / 2 - _buttons[2]->width(), imageY3);
	addWidget(_buttons[2]);
	_buttons[8] = utils->add_button("keyboard_mode.png", temp);
	_buttons[8]->move(this->width() / 2, imageY3);
	addWidget(_buttons[8]);
	imageY4 = imageY3 + _buttons[2]->height();
	
	_buttons[3] = utils->add_center_button("apply.png");
	_buttons[3]->move(_buttons[3]->pos().x(), imageY4);
	imageY5 = imageY4 + _buttons[3]->height();

	_buttons[4] = utils->add_button("load.png", temp);
	_buttons[4]->move(this->width() / 2 - _buttons[4]->width() - 50, imageY5);
	addWidget(_buttons[4]);
	QObject::connect(_buttons[4], &QPushButton::clicked, this, &Settings::load_clicked);

	_buttons[5] = utils->add_button("save.png", temp);
	_buttons[5]->move(this->width() / 2 + 50, imageY5);
	addWidget(_buttons[5]);
	QObject::connect(_buttons[5], &QPushButton::clicked, this, &Settings::save_clicked);

	QObject::connect(_buttons[6], &QPushButton::clicked, this, &Settings::click_playingMode);
	QObject::connect(_buttons[7], &QPushButton::clicked, this, &Settings::click_COM);
	QObject::connect(_buttons[8], &QPushButton::clicked, this, &Settings::click_input);

	QObject::connect(_exits, &QPushButton::clicked, this, &Settings::exit_clicked);
}

void Settings::exit_clicked() {
	emit exit_click();
}
void Settings::load_clicked() {
	emit load_click();
}
void Settings::save_clicked() {
	emit save_click();
}
void Settings::apply_clicked() {
	emit apply_click();
}

void Settings::click_playingMode() {
	if (_playingMode)
	{
		_playingMode = 0;
		delete _buttons[6];
		_buttons[6] = utils->add_button("accelerometer.png", nullptr);
		_buttons[6]->move(this->width() / 2, imageY1);
		addWidget(_buttons[6]);
		QObject::connect(_buttons[6], &QPushButton::clicked, this, &Settings::click_playingMode);
		
	}
	else
	{
		_playingMode = 1;
		delete _buttons[6];
		_buttons[6] = utils->add_button("accelerometer.png", nullptr);
		_buttons[6]->move(this->width() / 2, imageY1);
		addWidget(_buttons[6]);
		QObject::connect(_buttons[6], &QPushButton::clicked, this, &Settings::click_playingMode);
		
	}
}
void Settings::click_COM() {}
void Settings::click_input() {}
//if (_playingMode)
//{
//	_playingMode = 0;
//	delete _buttons[7];
//	_buttons[7] = utils->add_button("joystick.png", nullptr);
//	int x = 50;
//	_buttons[7]->move(this->width() / 2 + x, imageY1);
//	addWidget(_buttons[7]); x += _buttons[7]->width();
//}
//else
//{
//	delete _buttons[7];
//	_buttons[7] = utils->add_button("joystick.png", nullptr);
//	int x = 50;
//	_buttons[7]->move(this->width() / 2 + x, imageY1);
//	addWidget(_buttons[7]); x += _buttons[7]->width();
//}
