#include "SelectLevel.h"

void SelectLevel::initUI()
{
	QPushButton*exit=utils->add_exit();

	

	for (int i = 0; i < 6; i++)
	{
		_images[i] = utils->add_button("ressources/steve.png",nullptr);
		
		addWidget(_images[i]);

	}
	
	_images[0]->move((RESOLUTION_X - _images[0]->width()) / 3, RESOLUTION_Y / 2);
	_images[1]->move(((RESOLUTION_X - _images[0]->width()) / 3)+_images[0]->width(), RESOLUTION_Y / 2 -_images[1]->height());

	_images[2]->move((RESOLUTION_X - _images[2]->width()) / 3, RESOLUTION_Y / 2);
	

}