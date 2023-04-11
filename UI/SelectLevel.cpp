#include "SelectLevel.h"

void SelectLevel :: initUI()
{
    // Create a grid layout for level selection
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(10);

    // Add level images to the grid
    QPixmap level1(":/level/level1.jpg");
    QLabel* level1Label = new QLabel();
    level1Label->setPixmap(level1);
    level1Label->setCursor(Qt::PointingHandCursor);
    gridLayout->addWidget(level1Label, 0, 0);

    QPixmap level2(":/level/level2.jpg");
    QLabel* level2Label = new QLabel();
    level2Label->setPixmap(level2);
    level2Label->setCursor(Qt::PointingHandCursor);
    gridLayout->addWidget(level2Label, 0, 1);

    QPixmap level3(":/level/level3.jpg");
    QLabel* level3Label = new QLabel();
    level3Label->setPixmap(level3);
    level3Label->setCursor(Qt::PointingHandCursor);
    gridLayout->addWidget(level3Label, 1, 0);

    // Set the layout for the widget
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addLayout(gridLayout);
    layout->addStretch();

    setLayout(layout);
}
