//#include <QApplication>
//#include <QMainWindow>
//#include <QPushButton>
//#include <QMessageBox>
//#include <QString>
//#include <QRect>
//#include <QStyle>
//
//
//class CustomBtn : public QPushButton {
//public:
//	CustomBtn(std::string name = "", std::string message = "");
//	void clicked();
//	QMessageBox* getMB();
//private:
//	std::string _name;
//	std::string _msg;
//	QMessageBox* _mb;
//
//};
//
//class MainWindow : public QMainWindow {
//public:
//	MainWindow(CustomBtn* btn);
//public slots:
//	void handleMbClosed();
//private:
//	CustomBtn* _btn;
//};
//
//MainWindow::MainWindow(CustomBtn* btn) {
//	this->resize(600, 600);
//	_btn = btn;
//	_btn->setParent(this);
//	_btn->setGeometry(15, 15, 150, 50);
//	QMessageBox* mb = _btn->getMB();
//	connect(mb, &QMessageBox::accepted, this, &MainWindow::handleMbClosed);
//	_btn->show();
//}
//
//void MainWindow::handleMbClosed() {
//	setStyleSheet("QMainWindow {background-color: 'green'}");
//	show();
//}
//
//CustomBtn::CustomBtn(std::string name, std::string message) : QPushButton(QString::fromStdString(name)) {
//	_name = name;
//	_msg = message;
//	_mb = new QMessageBox();
//	connect(this, &QPushButton::released, this, &CustomBtn::clicked);
//}
//
//void CustomBtn::clicked() {
//	_mb->setText(QString::fromStdString(_msg));
//	_mb->show();
//}
//
//QMessageBox* CustomBtn::getMB() {
//	return _mb;
//}
//
//int main(int argc, char **argv)
//{
// QApplication app (argc, argv);
// CustomBtn* button = new CustomBtn("ouvrir message box", "Ceci est une message box");
// MainWindow m(button);
// m.show();
// return app.exec();
//}

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Level.h"
#include "Brique.h"
#include "Structs.h"
#include <fstream>
#include "GameLoop.h"
#include "Myrect.h"
#include "Plateforme.h"
#include "Controller.h"
#include <QTimer>
#include <QObject>

int main(int argc, char** argv)
{
	QApplication a(argc, argv);

	//std::string input_data = "1 1 1 1 1 1 1 1";

	// create a Level object and a std::istringstream object from the input data
	
	//std::istringstream input_stream(input_data);

	// use the overloaded operator to read the input data into the Level object


	//Level _level(_info);
	//std::string s = "1 1 1 1 1 1 1 1";
	//input_stream >> _level;

	//QGraphicsView* view = new QGraphicsView(_level.getScene());


	//view->show();
	//view->setFixedSize(800, 600);
	
	GameLoop game;
	
	return a.exec();
}
