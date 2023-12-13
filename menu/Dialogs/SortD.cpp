#include "SortD.h"
#include "../../tabwidget.h"
SortD::SortD(Achille *parent):QDialog(parent)
{
    layout = new QVBoxLayout;
    QLabel *label = new QLabel("Sort by");
    label->setFont(QFont("calibri",15));
    //QGroupBox *groupbox = new QGroupBox("Sort by",this);
    QRadioButton *choix= new QRadioButton("Type");
    QRadioButton *choix1 = new QRadioButton("Name(Z-A)");
    QRadioButton *choix2= new QRadioButton("Name(A-Z");
    QRadioButton *choix3= new QRadioButton("Date(oldest-latest)");
    QRadioButton *choix4= new QRadioButton("Date(latest-oldest)");
    QRadioButton *choix5= new QRadioButton("Size(large-small)");
    QRadioButton *choix6= new QRadioButton("Size(small-large)");
    //bool checked;
    layout->addWidget(label);
    layout->addWidget(choix);
    layout->addWidget(choix1);
    layout->addWidget(choix2);
    layout->addWidget(choix3);
    layout->addWidget(choix4);
    layout->addWidget(choix5);
    layout->addWidget(choix6);
    this->setLayout(layout);
    choix->setStyleSheet("QVBoxLayout color: red; background-color: white");
   // groupbox->setLayout(layout);

}
