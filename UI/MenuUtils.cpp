#include "MenuUtils.h"

MenuUtils::MenuUtils(QWidget* parent) : QObject(parent) {

}

MenuUtils::MenuUtils(QGraphicsScene* scene, QApplication* app, QWidget* parent) : QObject(parent) {
	_scene = scene;
	_app = app;
}

QLabel* MenuUtils::import_image(QString path)
{
	QLabel* imageLabel = new QLabel();
	QPixmap image(path);
	imageLabel->setPixmap(image);

	imageLabel->setFixedSize(image.width(), image.height());
	_scene->addWidget(imageLabel);
	
	return imageLabel;
}
CustomButton* MenuUtils::add_exit()
{
	CustomButton* button = new CustomButton("exit.png");
	
	int buttonX = MARGIN;
	int buttonY = _scene->height() - (EXIT_HEIGHT + MARGIN);

	button->move(buttonX, buttonY);
	_scene->addWidget(button);

	return button;

}
QLabel* MenuUtils::import_image_up(QString path,bool add)
{
	QLabel* imageLabel = new QLabel();
	QPixmap image(path);
	imageLabel->setPixmap(image);

	int imageX = (RESOLUTION_X - image.width()) / 2; // Position horizontale de l'image
	imageLabel->setGeometry(imageX, imageY, image.width(), image.height());
	imageY += image.height();
	if(add)
		_scene->addWidget(imageLabel);

	return imageLabel;
}
CustomButton* MenuUtils::add_center_button(QString path)
{
	CustomButton* button = new CustomButton(path);
	
	button->move((_scene->width() - button->width()) / 2, imageY);
	imageY += button->height();
	_scene->addWidget(button);

	return button;
}
CustomButton* MenuUtils::add_button(QString path, QWidget* widget)
{
	CustomButton* button = new CustomButton(path);

	return button;
}


void MenuUtils::set_as_sure()
{
	QMainWindow* win = new QMainWindow();
	win->setStyleSheet("background-color: black;");
	QWidget* centralWidget = new QWidget(win);
	win->setCentralWidget(centralWidget);
	win->resize(400, 300);
	QLabel* imageLabel = import_image_up("image/title/sure.png",0);
	QVBoxLayout* layout = new QVBoxLayout(centralWidget);
	centralWidget->setLayout(layout);
	layout->addWidget(imageLabel);

	QPushButton* yes = add_button("yes.png", win);
	layout->addWidget(yes);

	yes->move(_scene->width() / 2 - yes->width(), imageY);
	QObject::connect(yes, &QPushButton::clicked, _app, &QApplication::quit);

	QPushButton* cancel = add_button("cancel.png", win);
	layout->addWidget(cancel);

	cancel->move(_scene->width() / 2, imageY);
	QObject::connect(cancel, &QPushButton::clicked, win, &QMainWindow::close);
	win->show();
}