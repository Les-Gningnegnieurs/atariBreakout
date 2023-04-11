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
    QPixmap level1(":\level\level1.jpg");
    QPushButton* level1Button = new QPushButton(level1,"level1");
    //level1Label->setCursor(Qt::PointingHandCursor);
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
    gridLayout->setAlignment(Qt::AlignCenter);
  
    layout->addLayout(gridLayout);
    

    this->setLayout(layout);
}
