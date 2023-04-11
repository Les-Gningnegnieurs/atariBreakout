#include <QtWidgets>

class SelectLevel : public QWidget
{
public:
    SelectLevel(QWidget* parent = nullptr) : QWidget(parent) {


    
        QSize mainWinSize = parent->size();
        resize(1000, 800);
        initUI(); 
    }
    

private:
    void initUI();
   
};