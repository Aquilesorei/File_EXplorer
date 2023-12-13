#include "FileD.h"
#include "../../components/tabwidget.h"

FileD::FileD(CentralWidget *parent): QDialog(parent)
{
    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    QString currentName = tabWidget::currentWidget()->currentItemName();
    QString selectedItems = tabWidget::currentWidget()->view->currentItem()->text();
    QFileInfo infos(currentPath+selectedItems);
    layout = new QVBoxLayout;
    QLabel *labelT8 = new QLabel(this);
    labelT8->setText(infos.fileName());
    labelT8->setFont(QFont("calibri",10));

    QLabel *labelT = new QLabel(this);
    QString line = "Type : File";
    labelT->setText(line);
    labelT->setFont(QFont("calibri"));
    QLabel *labelT1 = new QLabel(this);
    QVariant T(infos.size());
    widget = new QWidget;
    if((T.toInt()/1000000)>1000)
    {
        QVariant gb = T.toInt()/1000000000;

        labelT1->setText("Size :    "+gb.toString()+"GBytes ("+T.toString()+" bytes)");
        labelT1->setFont(QFont("calibri"));
    }
    else
    {
        QVariant gb = T.toInt()/1000000;

        labelT1->setText("Size :    "+gb.toString()+"MBytes ("+T.toString()+" bytes)");
        labelT1->setFont(QFont("calibri"));

    }

     QLabel *labelT3 = new QLabel(this);
     QVariant E(infos.birthTime());
     labelT3->setText("Created  : "+E.toString());
     labelT3->setFont(QFont("calibri"));
     QLabel *labelT4 = new QLabel(this);
     QVariant R(infos.lastModified());

     labelT4->setText("Modified : "+R.toString());
     labelT4->setFont(QFont("calibri"));
     QLabel *labelT5 = new QLabel(this);

     labelT5->setText("Path : "+currentPath+selectedItems);
     labelT5->setFont(QFont("calibri"));
     QLabel *labelT6 = new QLabel(this);
     QVariant U(infos.permissions());
     labelT6->setText("Permissions : "+U.toString());
     labelT6->setFont(QFont("calibri"));
     QLabel *labelT7 = new QLabel(this);
     if(infos.isHidden())
     {
         labelT7->setText("Hidden :  Yes");
         labelT7->setFont(QFont("calibri"));
      }

     else{
         labelT7->setText("Hidden :  No");
         labelT7->setFont(QFont("calibri"));
     }

     layout->addWidget(labelT8);
     layout->addWidget(labelT);
     layout->addWidget(labelT1);

     layout->addWidget(labelT3);
     layout->addWidget(labelT4);
     layout->addWidget(labelT5);
     layout->addWidget(labelT6);
     layout->addWidget(labelT7);
     this->setLayout(layout);


}
