#include "SelectLevel.h"

void SelectLevel :: initUI()
{
    // Create a grid layout for level selection
    QLayout* oldLayout = this->layout();
    if (oldLayout != nullptr) {
        delete oldLayout;
    }

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(100);
   

    

    // Add level images to the grid
    QPixmap level1("../ressources/Level.png");
    QPushButton* level1Button = new QPushButton("level1");
    QIcon icon(level1);
    level1Button->setIcon(icon);
    level1Button->setIconSize(level1.rect().size()); 
    level1Button->setFixedSize(level1.rect().size()); 
    level1Button->setFlat(true);
    gridLayout->addWidget(level1Button, 0, 0);

    // Add level images to the grid
    QPixmap level2(":\level\level1.jpg");
    QPushButton* level2Button = new QPushButton(level2, "level2");
    //level1Label->setCursor(Qt::PointingHandCursor);
    gridLayout->addWidget(level2Button, 0, 1);

    // Add level images to the grid
    QPixmap level3(":\level\level3.jpg");
    QPushButton* level3Button = new QPushButton(level3, "level3");
    //level1Label->setCursor(Qt::PointingHandCursor);
    gridLayout->addWidget(level3Button, 1, 0);

    // Set the layout for the widget


    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);

    QLabel* text = new QLabel();
    QPixmap pix =  QPixmap("../ressources/Select_Level.png");
    text->setPixmap(pix);
    text->move(400, 100);
    layout->addWidget(text);
   
  
    layout->addLayout(gridLayout);
    
    this->setStyleSheet("background-color: gray;");
  
    this->setLayout(layout);
}
