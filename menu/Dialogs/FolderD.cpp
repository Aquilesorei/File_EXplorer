#include "FolderD.h"
#include "../../components/tabwidget.h"
FolderD::FolderD(CentralWidget *parent): QDialog(parent)
{




    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    QString currentName = tabWidget::currentWidget()->currentItemName();
    //QList<QListWidgetItem *> selectedItems = tabWidget::currentWidget()->view->selectedItems();
    QString selectedItems = tabWidget::currentWidget()->view->currentItem()->text();
    unsigned long int size=0;
    QDirIterator it(currentPath,QStringList()<<"*.*",QDir::Files,QDirIterator::Subdirectories);
    while(it.hasNext())
    {


        QFileInfo infos(it.next());
        size += infos.size();
        }
    QFileInfo infos(currentPath+selectedItems+'/');
    layout = new QVBoxLayout;
    QLabel *labelT = new QLabel(this);
    QString line = "Type : folder";
    labelT->setText(line);
    labelT->setFont(QFont("calibri"));
    QLabel *labelT1 = new QLabel(this);
    QVariant T =store(size);

    if((T.toInt()/1000000)>1000)
    {
        QVariant gb = T.toInt()/1000000000;

        labelT1->setText("Size :    "+gb.toString()+"GBytes ("+T.toString()+" bytes)");
    }
    else
    {
        QVariant gb = T.toInt()/1000000;

        labelT1->setText("Size :    "+gb.toString()+"MBytes ("+T.toString()+" bytes)");

    }
     QLabel *labelT2 = new QLabel(this);

     QString path = currentPath+selectedItems;

     QDir dir(path);

     QStringList folders, files;

 #ifdef _WIN32
     //Windows: use the registry
     bool hidden = false;
 #else
     bool hidden = false;
     //bool hidden = QVariant(Settings::getSetting("view/hidden","false")).toBool();
 #endif
     if (hidden) {
         folders = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
         files = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
     } else {
         folders = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
         files = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
     }
     QVariant Y(folders.size());
     QVariant Z(files.size());

     labelT2->setText("Content  Folder : "+Y.toString()+"   Files : "+Z.toString());
     QLabel *labelT3 = new QLabel(this);
     QVariant E(infos.birthTime());
     labelT3->setText("Created  : "+E.toString());
     QLabel *labelT4 = new QLabel(this);
     QVariant R(infos.lastModified());

     labelT4->setText("Modified : "+R.toString());
     QLabel *labelT5 = new QLabel(this);

     labelT5->setText("Path : "+currentPath+currentName);
     QLabel *labelT6 = new QLabel(this);
     QVariant U(infos.permissions());
     labelT6->setText("Permissions : "+U.toString());
     QLabel *labelT7 = new QLabel(this);
     if(infos.isHidden())
         labelT7->setText("Hidden :  Yes");
     else
         labelT7->setText("Hidden :  No");
     layout->addWidget(labelT);
     layout->addWidget(labelT1);
     layout->addWidget(labelT2);
     layout->addWidget(labelT3);
     layout->addWidget(labelT4);
     layout->addWidget(labelT5);
     layout->addWidget(labelT6);
     layout->addWidget(labelT7);
     this->setLayout(layout);


}
QVariant FolderD::store(unsigned long int value)
{

       unsigned long long data = (unsigned long long) value;
       QVariant qvariant( data );
       return qvariant;
    }
