#include "application.h"


void Window::set_as_sure()
{
	resize(400, 300);
	QLabel* imageLabel = import_image_up("image/title/sure.png");

	QPushButton* yes = add_button("image/unselected/yes.png");
	yes->move(this->width() / 2 - yes->width(), imageY);
	connect(yes, &QPushButton::clicked, app, &QApplication::quit);

	QPushButton* cancel = add_button("image/unselected/cancel.png");
	cancel->move(this->width() / 2, imageY);
	connect(cancel, &QPushButton::clicked, this, &Window::close);
}
void Window::set_as_paused() //NON TERMINÉ
{
	QPushButton* yes = add_button("image/unselected/resume.png");
	yes->move(this->width() / 2 - yes->width(), imageY);

	QPushButton* cancel = add_button("image/unselected/quit.png");
	cancel->move(this->width() / 2, imageY);
}

// Permet d'ajouter un bouton image à l'endroit désiré
QPushButton* Window::add_button(QString path)
{
	QPushButton* button = new QPushButton(centralWidget);

	QPixmap pixmap(path);
	QIcon icon(pixmap); // Création d'une icône à partir de la première image
	button->setIcon(icon); // Définition de l'icône pour le bouton
	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
	button->setFlat(true);

	return button;
}


/// Permet de placer une image dans le haut de la page
QLabel* Window::import_image_up(QString path)
{
	QLabel* imageLabel = new QLabel(centralWidget);
	QPixmap image(path);
	imageLabel->setPixmap(image);

	int imageX = (this->width() - image.width()) / 2; // Position horizontale de l'image
	imageLabel->setGeometry(imageX, imageY, image.width(), image.height());
	imageY += image.height();

	return imageLabel;
}





Menu_UI::Menu_UI(QApplication* a)
{
	app = a;
	resize(1200, 800);
	_exit = add_exit();
	controller = import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE
	controller->move(RESOLUTION_X - controller->width() - MARGIN, 0);
	centralWidget->resize(1200, 800);
}

void Menu_UI::set_as_main()
{
	QObject::connect(_exit, &QPushButton::clicked, this, &Menu_UI::exit_clicked);
	imageY = 100;
	QLabel* im1 = import_image_up("image/title/logo.png");
	//imageY += 50;
	QLabel* im2 = import_image_up("image/title/team.png");
	_center[0] = add_center_button("image/unselected/play_game.png");
	_center[1] = add_center_button("image/unselected/select_level.png");
	_center[2] = add_center_button("image/unselected/settings.png");


	setCentralWidget(centralWidget);
	

}

QPushButton* Menu_UI::add_exit()
{
	QPushButton* button = new QPushButton(centralWidget);
	QPixmap pixmap("image/unselected/exit.png");
	QIcon icon(pixmap); // Création d'une icône à partir de la première image
	button->setIcon(icon); // Définition de l'icône pour le bouton
	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
	button->setFlat(true);


	int buttonX = MARGIN;
	int buttonY = height() - (EXIT_HEIGHT + MARGIN);

	button->move(buttonX, buttonY);

	return button;
}

QLabel* Menu_UI::import_image(QString path)
{
	QLabel* imageLabel = new QLabel(centralWidget);
	QPixmap image(path);
	imageLabel->setPixmap(image);

	imageLabel->setFixedSize(image.width(), image.height());

	return imageLabel;
}

QPushButton* Menu_UI::add_center_button(QString path)
{
	QPushButton* button = new QPushButton(centralWidget);

	QPixmap pixmap(path);
	QIcon icon(pixmap); // Création d'une icône à partir de la première image
	button->setIcon(icon); // Définition de l'icône pour le bouton
	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
	button->setFlat(true);
	
	button->move((width() - pixmap.width()) / 2, imageY);
	imageY += pixmap.height();

	return button;
}
/*
Main_UI::Main_UI(QApplication* a)
{
	app = a;
	imageY = 100;
	import_image_up("image/title/logo.png");
	import_image_up("image/title/team.png");
	imageY += 50;
	_center[0] = add_center_button("image/unselected/play_game.png");
	_center[1] = add_center_button("image/unselected/select_level.png");
	_center[2] = add_center_button("image/unselected/settings.png");
	QObject::connect(_exit, &QPushButton::clicked, this, &Main_UI::exit_clicked);
	QObject::connect(_center[0], &QPushButton::clicked, this, &Main_UI::settings_clicked);
	QObject::connect(_center[1], &QPushButton::clicked, this, &Main_UI::level_clicked);
	QObject::connect(_center[2], &QPushButton::clicked, this, &Main_UI::settings_clicked);
}

Settings_UI::Settings_UI()
{
	imageY = 50;
	import_image_up("image/title/settings_menu.png");
	QPushButton* _playing_mode = add_button("image/unselected/playing_mode.png");
	_playing_mode->move(this->width() / 2 - _playing_mode->width(), imageY);
	imageY += _playing_mode->height();

	QPushButton* _COM = add_button("image/unselected/COM.png");
	_COM->move(this->width() / 2 - _COM->width(), imageY);
	imageY += _COM->height();

	QPushButton* _input = add_button("image/unselected/input.png");
	_input->move(this->width() / 2 - _input->width(), imageY);
	imageY += _input->height();

	QPushButton* _apply = add_center_button("image/unselected/apply.png");

	QPushButton* _load = add_button("image/unselected/load.png");
	_load->move(this->width() / 2 - _load->width() - 50, imageY);

	QPushButton* _save = add_button("image/unselected/save.png");
	_save->move(this->width() / 2 + 50, imageY);

	connect(_exit, &QPushButton::clicked, this, &Window::close);
}

Level_UI::Level_UI()
{
	imageY = 50;
	import_image_up("image/title/select_level_menu.png");

	connect(_exit, &QPushButton::clicked, this, &Window::close);
}
*/
/*
int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	Menu_UI* win = new Menu_UI(&app);

	win->show();
	win->set_as_main();

	return app.exec();
}*/

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	//button2->setGeometry(200, 20, 100, 30); // Définir la position et la taille du bouton 2

	Menu_UI* menu = new Menu_UI(&app);

	menu->set_as_main();

	menu->show();


	return app.exec();
}
