#include "GameOver.h"


GameOver::GameOver(QApplication* app, QString score, QWidget* parent) : QGraphicsScene(parent)
{
	setBackgroundBrush(Qt::black);
	_utils = new MenuUtils(this, app);
	_app = app;
	_score = score;
	initUI();
}


void GameOver::initUI()
{
	QLabel* lab = _utils->import_image_up("image/title/gameOver.png", 1);
	int imageY = lab->height();
	int x = lab->pos().x() + lab->width() / 2;

	
	//QString qstringValue = QString::number(*_score);
	qDebug() << _score << "Tats iy";
	// Créer un objet texte
	QGraphicsTextItem* textItem = new QGraphicsTextItem(_score);
	
	// Définir la police du texte
	QFont font;
	font.setFamily("Helvetica");
	font.setPointSize(24);
	font.setBold(true);
	textItem->setFont(font);
	// Définir la couleur du texte
	QColor color(255, 0, 0); // Rouge
	textItem->setDefaultTextColor(color);
	// Ajouter l'objet texte à la scène
	addItem(textItem);
	textItem->moveBy(x - lab->width() / 2, imageY);
	imageY += 50;

	CustomButton* _button1 = _utils->add_button("replay.png", nullptr);
	_button1->move(x - _button1->width(), imageY);
	QObject::connect(_button1, &QPushButton::clicked, this, &GameOver::replayRequested);
	addWidget(_button1);
	CustomButton* _button2 = _utils->add_button("menu.png", nullptr);
	_button2->move(x + lab->width()/2 - _button2->width(), imageY);
	addWidget(_button2);
	//qDebug() << _score;
	QObject::connect(_button2, &QPushButton::clicked, this, &GameOver::menuRequested);
	
}

void GameOver:: menuRequested()
{
	emit menuClick();
}
void GameOver::replayRequested()
{
	emit replayClick();
}