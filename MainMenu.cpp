#include "MainMenu.h"

void MainMenu:: initUI()
{
	//// CREATING MAIN
	QLabel*_controllerm = import_image("image/unselected/keyboard.png"); // A REVOIR POUR LA MANETTE
	_controllerm->move(RESOLUTION_X - _controllerm->width() - MARGIN, RESOLUTION_Y - _controllerm->height() - MARGIN);

	QPushButton*_exitm = add_exit();
	 imageY = 100;
	QLabel* im1 = import_image_up("image/title/logo.png");
	QLabel* im2 = import_image_up("image/title/team.png");
	_center[0] = add_center_button("image/unselected/play_game.png");
	_center[1] = add_center_button("image/unselected/select_level.png");
	_center[2] = add_center_button("image/unselected/settings.png");


	QObject::connect(_exitm, &QPushButton::clicked, this, &MainMenu::exit_clicked);
	//QObject::connect(_center[0], &QPushButton::clicked, this, &Menu_UI::level_clicked);
	//QObject::connect(_center[1], &QPushButton::clicked, this, &Menu_UI::level_clicked);
	//QObject::connect(_center[2], &QPushButton::clicked, this, &Menu_UI::settings_clicked);
}

QLabel* MainMenu::import_image(QString path)
{
	QLabel* imageLabel = new QLabel();
	QPixmap image(path);
	imageLabel->setPixmap(image);

	imageLabel->setFixedSize(image.width(), image.height());
	addWidget(imageLabel);

	return imageLabel;
}

QPushButton* MainMenu::add_exit()
{

	QPushButton* button = new QPushButton();
	QPixmap pixmap("image/unselected/exit.png");
	QIcon icon(pixmap); // Cr�ation d'une ic�ne � partir de la premi�re image
	button->setIcon(icon); // D�finition de l'ic�ne pour le bouton
	button->setIconSize(pixmap.rect().size()); // D�finition de la taille de l'ic�ne pour le bouton
	button->setFixedSize(pixmap.rect().size()); // D�finition de la taille fixe du bouton pour correspondre � la taille de l'ic�ne
	button->setFlat(true);


	int buttonX = MARGIN;
	int buttonY = height() - (EXIT_HEIGHT + MARGIN);

	button->move(buttonX, buttonY);
	addWidget(button);

	return button;
}

QLabel* MainMenu::import_image_up(QString path)
{
	QLabel* imageLabel = new QLabel();
	QPixmap image(path);
	imageLabel->setPixmap(image);

	int imageX = (RESOLUTION_X - image.width()) / 2; // Position horizontale de l'image
	imageLabel->setGeometry(imageX, imageY, image.width(), image.height());
	imageY += image.height();
	addWidget(imageLabel);

	return imageLabel;
}



QPushButton* MainMenu::add_center_button(QString path)
{
	QPushButton* button = new QPushButton();

	QPixmap pixmap(path);
	QIcon icon(pixmap); // Cr�ation d'une ic�ne � partir de la premi�re image
	button->setIcon(icon); // D�finition de l'ic�ne pour le bouton
	button->setIconSize(pixmap.rect().size()); // D�finition de la taille de l'ic�ne pour le bouton
	button->setFixedSize(pixmap.rect().size()); // D�finition de la taille fixe du bouton pour correspondre � la taille de l'ic�ne
	button->setFlat(true);

	button->move((width() - pixmap.width()) / 2, imageY);
	imageY += pixmap.height();
	addWidget(button);

	return button;
}

void MainMenu::set_as_sure()
{
	QMainWindow* win = new QMainWindow();
	win->setStyleSheet("background-color: black;");
	QWidget* centralWidget = new QWidget(win);
	win->setCentralWidget(centralWidget);
	win->resize(400, 300);
	QLabel* imageLabel = import_image_up("image/title/sure.png");
	QVBoxLayout* layout = new QVBoxLayout(centralWidget);
	centralWidget->setLayout(layout);
	layout->addWidget(imageLabel);

	QPushButton* yes = add_button("image/unselected/yes.png",win);
	layout->addWidget(yes);

	yes->move(this->width() / 2 - yes->width(), imageY);
	QObject::connect(yes, &QPushButton::clicked, _app, &QApplication::quit);

	QPushButton* cancel = add_button("image/unselected/cancel.png",win);
	layout->addWidget(cancel);

	cancel->move(this->width() / 2, imageY);
	QObject::connect(cancel, &QPushButton::clicked, win, &QMainWindow::close);
	win->show();
}

QPushButton* MainMenu::add_button(QString path, QWidget* widget)
{
	QPushButton* button = new QPushButton();

	QPixmap pixmap(path);
	QIcon icon(pixmap); // Cr�ation d'une ic�ne � partir de la premi�re image
	button->setIcon(icon); // D�finition de l'ic�ne pour le bouton
	button->setIconSize(pixmap.rect().size()); // D�finition de la taille de l'ic�ne pour le bouton
	button->setFixedSize(pixmap.rect().size()); // D�finition de la taille fixe du bouton pour correspondre � la taille de l'ic�ne
	button->setFlat(true);

	return button;
}



int main(int argc,char *argv[])
{
	QApplication app(argc, argv);
	QGraphicsView* mainwindow = new QGraphicsView;
	MainMenu* menu = new MainMenu(&app);
	mainwindow->setScene(menu);
	mainwindow->resize(RESOLUTION_X, RESOLUTION_Y);
	mainwindow->show();
	return app.exec();
}