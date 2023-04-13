#include <stdlib.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <Structs.h>
#include <QLabel>
#include <QGraphicsPixmapItem>



class Canevas
{
private:
	int _windowResolutionX = RESOLUTION_X;
	int _windowResolutionY = RESOLUTION_Y;
	QGraphicsScene* _scene;
public:
	Canevas();
	~Canevas();
	
	QGraphicsScene* getScene() { return _scene; }

};
