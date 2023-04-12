//#include "application.h"
//
///*
//void Window::set_as_sure()
//{
//	resize(400, 300);
//	QLabel* imageLabel = import_image_up("image/title/sure.png", this);
//
//	QPushButton* yes = add_button("image/unselected/yes.png", this);
//	yes->move(this->width() / 2 - yes->width(), imageY);
//	connect(yes, &QPushButton::clicked, app, &QApplication::quit);
//
//	QPushButton* cancel = add_button("image/unselected/cancel.png", this);
//	cancel->move(this->width() / 2, imageY);
//	connect(cancel, &QPushButton::clicked, this, &Window::close);
//}
//void Window::set_as_paused() //NON TERMINÉ
//{
//	/*QPushButton* yes = add_button("image/unselected/resume.png");
//	yes->move(this->width() / 2 - yes->width(), imageY);
//
//	QPushButton* cancel = add_button("image/unselected/quit.png");
//	cancel->move(this->width() / 2, imageY);
//}
//
//// Permet d'ajouter un bouton image à l'endroit désiré
//QPushButton* Window::add_button(QString path, QWidget* widget)
//{
//	QPushButton* button = new QPushButton(widget);
//
//	QPixmap pixmap(path);
//	QIcon icon(pixmap); // Création d'une icône à partir de la première image
//	button->setIcon(icon); // Définition de l'icône pour le bouton
//	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
//	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
//	button->setFlat(true);
//
//	return button;
//}
//
//
///// Permet de placer une image dans le haut de la page
//QLabel* Window::import_image_up(QString path, QWidget* widget)
//{
//	QLabel* imageLabel = new QLabel(widget);
//	QPixmap image(path);
//	imageLabel->setPixmap(image);
//
//	int imageX = (this->width() - image.width()) / 2; // Position horizontale de l'image
//	imageLabel->setGeometry(imageX, imageY, image.width(), image.height());
//	imageY += image.height();
//
//	return imageLabel;
//}
//
//
//
//
//
//Menu_UI::Menu_UI(QApplication* a, Menu* m)
//{
//	app = a;
//	resize(1200, 800);
//	
//	_menu = m;
//	
//	_main->resize(RESOLUTION_X, RESOLUTION_Y);
//	_level->resize(RESOLUTION_X, RESOLUTION_Y);
//	_settings->resize(RESOLUTION_X, RESOLUTION_Y);
//
//	//// CREATING MAIN
//	_controllerm = import_image("image/unselected/keyboard.png", _main); // A REVOIR POUR LA MANETTE
//	_controllerm->move(RESOLUTION_X - _controllerm->width() - MARGIN, RESOLUTION_Y - _controllerm->height() - MARGIN);
//	
//	_exitm = add_exit(_main);
//	imageY = 100;
//	QLabel* im1 = import_image_up("image/title/logo.png", _main);
//	QLabel* im2 = import_image_up("image/title/team.png", _main);
//	_center[0] = add_center_button("image/unselected/play_game.png", _main);
//	_center[1] = add_center_button("image/unselected/select_level.png", _main);
//	_center[2] = add_center_button("image/unselected/settings.png", _main);
//
//	QObject::connect(_exitm, &QPushButton::clicked, this, &Menu_UI::exit_clicked);
//	QObject::connect(_center[0], &QPushButton::clicked, this, &Menu_UI::level_clicked);
//	QObject::connect(_center[1], &QPushButton::clicked, this, &Menu_UI::level_clicked);
//	QObject::connect(_center[2], &QPushButton::clicked, this, &Menu_UI::settings_clicked);
//
//
//	//// CREATING LEVEL
//	_controllerl = import_image("image/unselected/keyboard.png", _level); // A REVOIR POUR LA MANETTE_exits = add_exit(_settings);
//	_controllerl->move(RESOLUTION_X - _controllerl->width() - MARGIN, RESOLUTION_Y - _controllerl->height() - MARGIN);
//
//	_exitl = add_exit(_level);
//
//	imageY = 50;
//	import_image_up("image/title/select_level_menu.png", _level);
//
//	QObject::connect(_exitl, &QPushButton::clicked, this, &Menu_UI::exits);
//
//
//	//// CREATING SETTINGS
//	_controllers = import_image("image/unselected/keyboard.png", _settings); // A REVOIR POUR LA MANETTE_exits = add_exit(_settings);
//	_controllers->move(RESOLUTION_X - _controllers->width() - MARGIN, RESOLUTION_Y - _controllers->height() - MARGIN);
//	
//	_exits = add_exit(_settings);
//
//	imageY = 50;
//	import_image_up("image/title/settings_menu.png", _settings);
//	_buttons[0] = add_button("image/unselected/playing_mode.png", _settings);
//	_buttons[0]->move(this->width() / 2 - _buttons[0]->width(), imageY);
//	imageY += _buttons[0]->height();
//
//	_buttons[1] = add_button("image/unselected/COM.png", _settings);
//	_buttons[1]->move(this->width() / 2 - _buttons[1]->width(), imageY);
//	imageY += _buttons[1]->height();
//
//	_buttons[2] = add_button("image/unselected/input.png", _settings);
//	_buttons[2]->move(this->width() / 2 - _buttons[2]->width(), imageY);
//	imageY += _buttons[2]->height();
//
//	_buttons[3] = add_center_button("image/unselected/apply.png", _settings);
//
//	_buttons[4] = add_button("image/unselected/load.png", _settings);
//	_buttons[4]->move(this->width() / 2 - _buttons[4]->width() - 50, imageY);
//
//	_buttons[5] = add_button("image/unselected/save.png", _settings);
//	_buttons[5]->move(this->width() / 2 + 50, imageY);
//
//	QObject::connect(_exits, &QPushButton::clicked, this, &Menu_UI::exits);
//
//	stackedWidget->addWidget(_main);
//	stackedWidget->addWidget(_level);
//	stackedWidget->addWidget(_settings);
//
//	setCentralWidget(stackedWidget);
//
//}
//
//void Menu_UI::set_as_main()
//{
//	stackedWidget->setCurrentIndex(0);
//}
//
//void Menu_UI::set_as_level()
//{
//	stackedWidget->setCurrentIndex(1);
//}
//
//void Menu_UI::set_as_settings()
//{
//	stackedWidget->setCurrentIndex(2);
//}
//
//
//QPushButton* Menu_UI::add_exit(QWidget* widget)
//{
//
//	QPushButton* button = new QPushButton(widget);
//	QPixmap pixmap("image/unselected/exit.png");
//	QIcon icon(pixmap); // Création d'une icône à partir de la première image
//	button->setIcon(icon); // Définition de l'icône pour le bouton
//	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
//	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
//	button->setFlat(true);
//
//
//	int buttonX = MARGIN;
//	int buttonY = height() - (EXIT_HEIGHT + MARGIN);
//
//	button->move(buttonX, buttonY);
//
//	return button;
//}
//QLabel* Menu_UI::import_image(QString path, QWidget* widget)
//{
//	QLabel* imageLabel = new QLabel(widget);
//	QPixmap image(path);
//	imageLabel->setPixmap(image);
//
//	imageLabel->setFixedSize(image.width(), image.height());
//
//	return imageLabel;
//}
//
//QPushButton* Menu_UI::add_center_button(QString path, QWidget* widget)
//{
//	QPushButton* button = new QPushButton(widget);
//
//	QPixmap pixmap(path);
//	QIcon icon(pixmap); // Création d'une icône à partir de la première image
//	button->setIcon(icon); // Définition de l'icône pour le bouton
//	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
//	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
//	button->setFlat(true);
//	
//	button->move((width() - pixmap.width()) / 2, imageY);
//	imageY += pixmap.height();
//
//	return button;
//}
//*/
///*
//int main(int argc, char* argv[]) {
//	QApplication app(argc, argv);
//
//	Menu_UI* win = new Menu_UI(&app);
//
//	win->show();
//	win->set_as_main();
//
//	return app.exec();
//}*/
//
//#include <QApplication>
//#include <QWidget>
//#include <QPushButton>
//#include <QLabel>
//
///*int main(int argc, char* argv[])
//{
//	QApplication app(argc, argv);
//	//button2->setGeometry(200, 20, 100, 30); // Définir la position et la taille du bouton 2
//	Menu m;
//	Menu_UI* menu = new Menu_UI(&app, &m);
//
//	menu->set_as_main();
//
//	menu->show();
//
//
//	return app.exec();
//}
//*/
