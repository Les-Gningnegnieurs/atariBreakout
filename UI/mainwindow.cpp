#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QString>


class CustomBtn : public QPushButton {
public:
	CustomBtn(std::string name = "", std::string message = "");
	void clicked();
private:
	std::string _name;
	std::string _msg;
	QMessageBox _mb;

};

CustomBtn::CustomBtn(std::string name, std::string message) : QPushButton(QString::fromStdString(name)) {
	_name = name;
	_msg = message;
	connect(this, &QPushButton::released, this, &CustomBtn::clicked);
}

void CustomBtn::clicked() {
	_mb.setText(QString::fromStdString(_msg));
	_mb.show();
}

int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 CustomBtn button("ouvrir message box", "Ceci est une message box");
 button.show();
 return app.exec();
}