#include "MenuPause.h"


MenuPause::MenuPause(QApplication* app, QString score, QWidget* parent) : QGraphicsScene(parent)
{
	setBackgroundBrush(Qt::black);
	_utils = new MenuUtils(this, app);
	_app = app;
	_score = score;
	initUI();
}


void MenuPause::initUI()
{
	QLabel* lab = _utils->import_image_up("image/title/paused.png", 1);
	int imageY = lab->height();
	int x = lab->pos().x() + lab->width() / 2;

	QGraphicsTextItem* textItem = new QGraphicsTextItem(_score);

	// D�finir la police du texte
	QFont font;
	font.setFamily("Helvetica");
	font.setPointSize(24);
	font.setBold(true);
	textItem->setFont(font);
	// D�finir la couleur du texte
	QColor color(255, 0, 0); // Rouge
	textItem->setDefaultTextColor(color);
	// Ajouter l'objet texte � la sc�ne
	addItem(textItem);
	textItem->moveBy(x - lab->width() / 2, imageY);
	imageY += 50;

	CustomButton* _button1 = _utils->add_button("resume.png", nullptr);
	_button1->move(x - _button1->width(), imageY);
	QObject::connect(_button1, &QPushButton::clicked, this, &MenuPause::resumeRequested);
	addWidget(_button1);
	CustomButton* _button2 = _utils->add_button("quit.png", nullptr);
	_button2->move(x + (_button1->width() -_button2->width()) /2, imageY);
	addWidget(_button2);
	//qDebug() << _score;
	QObject::connect(_button2, &QPushButton::clicked, this, &MenuPause::menuRequested);

}

void MenuPause::menuRequested()
{
	emit menuClick();
}
void MenuPause::resumeRequested()
{
	emit resumeClick();
}