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