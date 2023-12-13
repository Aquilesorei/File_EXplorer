#include "MultiD.h"
#include "../../components/tabwidget.h"
MultiD::MultiD(CentralWidget *parent): QDialog(parent)
{
    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    QString currentName = tabWidget::currentWidget()->currentItemName();
    layout = new QVBoxLayout;
    QLabel *labelT = new QLabel(this);

    int nbfiles=0;
    QLabel *labelT1 = new QLabel(this);
    //QVariant T(infos.size());
    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();//plusieurs
    QStringList list;

    QString path = tabWidget::currentWidget()->currentPath;
    if(selectedItems.size()>1)
    {
        for(int i= 0;i<selectedItems.size();++i)
        {
           list.push_back(path+selectedItems.at(i));
           QFileInfo infos(list.at(i));
           QVariant T(infos.size());
           size += T.toInt();


        }
        QVariant T(size);
        if((T.toInt()/1000000)>1000)
        {
            QVariant gb = T.toInt()/1000000000;

            labelT->setText("Size :    "+gb.toString()+"GBytes ("+T.toString()+" bytes)");

        }
        else
        {
            QVariant gb = T.toInt()/1000000;

            labelT->setText("Size :    "+gb.toString()+"MBytes ("+T.toString()+" bytes)");

        }
        labelT->setFont(QFont("calibri"));






        for(int i= 0;i<list.size();++i)
        {
         QFileInfo infos(list.at(i));
         if(infos.isFile())
             nbfiles++;
         else{

        QString path = list.at(i);

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
            folders += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
            files += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
        } else {
            folders += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
            files += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
        }
        QVariant Y(folders.size());
        QVariant Z(files.size());
        QVariant fich(Z.toInt()+nbfiles);

        labelT1->setText("Content  Folder : "+Y.toString()+"   Files : "+fich.toString());}

}
    }
    layout->addWidget(labelT);
    layout->addWidget(labelT1);
    this->setLayout(layout);
}
