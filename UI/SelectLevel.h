#include <QtWidgets>

class SelectLevel : public QWidget
{
public:
    SelectLevel(QWidget* parent = nullptr) : QWidget(parent) { initUI(); }
    

private:
    void initUI();
   
};