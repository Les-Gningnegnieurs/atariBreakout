#include "MenuUtils.h"
//
//MenuUtils::MenuUtils(QWidget* parent) : QObject(parent) {
//
//}
//
//MenuUtils::MenuUtils(QGraphicsScene* scene, QApplication* app, QWidget* parent) : QObject(parent) {
//	_scene = scene;
//	_app = app;
//}
//
//QLabel* MenuUtils::import_image(QString path)
//{
//	QLabel* imageLabel = new QLabel();
//	QPixmap image(path);
//	imageLabel->setPixmap(image);
//
//	imageLabel->setFixedSize(image.width(), image.height());
//	_scene->addWidget(imageLabel);
//	
//	return imageLabel;
//}
//QPushButton* MenuUtils::add_exit()
//{
//	QPushButton* button = new QPushButton();
//
//	QPixmap pixmap("image/unselected/exit.png");
//	QIcon icon(pixmap); // Création d'une icône à partir de la première image
//	button->setIcon(icon); // Définition de l'icône pour le bouton
//	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
//	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
//	button->setFlat(true);
//
//
//	int buttonX = MARGIN;
//	int buttonY = _scene->height() - (EXIT_HEIGHT + MARGIN);
//
//	button->move(buttonX, buttonY);
//	_scene->addWidget(button);
//
//	return button;
//
//}
//QLabel* MenuUtils::import_image_up(QString path,bool add)
//{
//	QLabel* imageLabel = new QLabel();
//	QPixmap image(path);
//	imageLabel->setPixmap(image);
//
//	int imageX = (RESOLUTION_X - image.width()) / 2; // Position horizontale de l'image
//	imageLabel->setGeometry(imageX, imageY, image.width(), image.height());
//	imageY += image.height();
//	if(add)
//		_scene->addWidget(imageLabel);
//
//	return imageLabel;
//}
//QPushButton* MenuUtils::add_center_button(QString path)
//{
//	QPushButton* button = new QPushButton();
//
//	QPixmap pixmap(path);
//	QIcon icon(pixmap); // Création d'une icône à partir de la première image
//	button->setIcon(icon); // Définition de l'icône pour le bouton
//	button->setIconSize(pixmap.rect().size()); // Définition de la taille de l'icône pour le bouton
//	button->setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
//	button->setFlat(true);
//
//	button->move((_scene->width() - pixmap.width()) / 2, imageY);
//	imageY += pixmap.height();
//	_scene->addWidget(button);
//
//	return button;
//}
//QPushButton* MenuUtils::add_button(QString path, QWidget* widget)
//{
//	QPushButton* button = new QPushButton();
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
//void MenuUtils::set_as_sure()
//{
//	QMainWindow* win = new QMainWindow();
//	win->setStyleSheet("background-color: black;");
//	QWidget* centralWidget = new QWidget(win);
//	win->setCentralWidget(centralWidget);
//	win->resize(400, 300);
//	QLabel* imageLabel = import_image_up("image/title/sure.png",0);
//	QVBoxLayout* layout = new QVBoxLayout(centralWidget);
//	centralWidget->setLayout(layout);
//	layout->addWidget(imageLabel);
//
//	QPushButton* yes = add_button("image/unselected/yes.png", win);
//	layout->addWidget(yes);
//
//	yes->move(_scene->width() / 2 - yes->width(), imageY);
//	QObject::connect(yes, &QPushButton::clicked, _app, &QApplication::quit);
//
//	QPushButton* cancel = add_button("image/unselected/cancel.png", win);
//	layout->addWidget(cancel);
//
//	cancel->move(_scene->width() / 2, imageY);
//	QObject::connect(cancel, &QPushButton::clicked, win, &QMainWindow::close);
//	win->show();
//}