#include "Progressa.h"
Progressa::Progressa(QWidget *parent):QDialog(parent)
{
    labelFromto = new QLabel;
    labelFromto->setText("this is a test");

    labelAvance = new QLabel;
    labelAvance->setText("36/43");
    CurrentFileProgress = new QProgressBar;
    CurrentFileProgress->setGeometry(10, 60, 150, 20);
    CurrentFileProgress->setRange(0,100);
    AllFilesProgress = new QProgressBar;
    AllFilesProgress->setGeometry(10, 60, 150, 20);  
    AllFilesProgress->setRange(0,100);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(labelFromto);
    layout->addWidget(CurrentFileProgress);
    layout->addWidget(AllFilesProgress);
    layout->addWidget(labelAvance);
     this->setLayout(layout);
    setFixedSize(500, 200);


}
