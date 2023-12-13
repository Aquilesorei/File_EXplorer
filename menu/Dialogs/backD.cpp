#include "backD.h"
#include "../../components/tabwidget.h"
#include <QtConcurrent>
#include <QFuture>
#include <QStorageInfo>

backD::backD(CentralWidget *parent): QDialog(parent)
{



    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    int pos = currentPath.lastIndexOf('/');
    currentPath = currentPath.left(pos);
       //QFuture<qlonglong> future = QtConcurrent::run([this] () -> qlonglong { return analysa(); });//work !
       //QFuture<qlonglong> future =QtConcurrent::run([]{ return analysa(); }); //work !
   //   QFuture<qlonglong> future = QtConcurrent::run(analysa);work !
    // QFuture<qlonglong> future = QtConcurrent::run(&analysa);//work !
   // QFuture<qlonglong> future = QtConcurrent::run(this,&backD::analysa);
 //   qlonglong size= future.result();
     QString path ="C:\\Users\\ZONGO CentralWidget\\Documents\\QtCreator\\File_EXplorer";//QDir::toNativeSeparators(currentPath);
   // QStringList arguments { "C:\\Users\\ZONGO CentralWidget\\Documents\\QtCreator\\File_EXplorer\\PyGetFolderSize.py",path};
   process = new QProcess(this);
   const QString program = QDir::toNativeSeparators("C:/Users/ZONGO CentralWidget/AppData/Local/Programs/Python/Python310/python.exe");
   /*process->setProgram(program);
    process->start();
    qDebug() <<process->processId();
   process->waitForFinished();
    QString Size = process->readAll();

    qDebug() << Size;
    process->close();*/




    QFileInfo infos(currentPath);

    layout = new QVBoxLayout;
    QLabel *labelT = new QLabel(this);
    QString line = "Type : folder";
    labelT->setText(line);
    labelT->setFont(QFont("calibri"));
    QLabel *labelT1 = new QLabel(this);
  //  connect(this,&backD::sizeIcrease,this,&backD::setTexte);
    QVariant T =store(analysa());

    //comm();

    if((T.toInt()/1000000)>1000)
    {
        QVariant gb = T.toInt()/1000000000;

        labelT1->setText("Size :    "+gb.toString()+"GBytes ("+T.toString()+" bytes)");
    }
    else
    {
        QVariant Mb = T.toInt()/1000000;

        labelT1->setText("Size :    "+Mb.toString()+"MBytes ("+T.toString()+" bytes)");

    }
     QLabel *labelT2 = new QLabel(this);

     QDir dir(currentPath);

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

     labelT5->setText("Path : "+currentPath);
     QLabel *labelT6 = new QLabel(this);
     QVariant U(infos.permissions());
     labelT6->setText("Permissions : "+U.toString());
     QLabel *labelT7 = new QLabel(this);

    QString text = (infos.isHidden())? "Yes":"No";
    labelT7->setText(text);

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
QVariant backD::store(unsigned long int value)
{

       unsigned long long data = (unsigned long long) value;
       QVariant qvariant( data );
       return qvariant;
    }



qlonglong  backD::analysa()
{
    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    qlonglong size=0;

    QDirIterator it(currentPath,QStringList()<<"*.*",QDir::Files,QDirIterator::Subdirectories);
    while(it.hasNext())
    {


        QFileInfo infos(it.next());

        size += infos.size();

    }
    return size;
}




//QtConcurrent::run<backD *, long long (backD::*)()>
void backD::comm()
{
    const QString program = QDir::toNativeSeparators("C:/Users/ZONGO CentralWidget/AppData/Local/Programs/Python/Python310/python.exe");
    qDebug()<<"le renard passe passe";


    QProcess::startDetached(program);

}

