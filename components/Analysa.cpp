#include "Analysa.h"

#include <QDirIterator>
#include <QSaveFile>

Analysa::Analysa()
{

    files();
    config();
  //  config2();

}

void Analysa::config()
{

    QSaveFile file(workingDirectoryPath+"Apps.txt");
     qDebug()<<folderApps.size();
   if(file.open(QIODevice::WriteOnly| QIODevice::Text))
    {
        for(int i=0;i<folderApps.size(); ++i )
        {
            QTextStream out(&file);
            out<<folderApps.at(i)+"\n";
            if(folderApps.at(i)==folderApps.last())
                file.commit();
        }
    }
}

void Analysa::config2()
{
    QSaveFile file2(workingDirectoryPath+"Archive.txt");
    if(file2.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        for(int i=0;i<folderComp.size(); ++i )
        {
            QTextStream outta(&file2);
            outta<<folderApps.at(i)+"\n";
            qDebug()<<"writing";
            if(folderComp.at(i)==folderComp.last())
                file2.commit();
        }
    }
}


bool Analysa::files()
{
   // QString currentPath = tabWidget::currentWidget()->fsCurrentPath();

      //  QDir dir(QDir::homePath());
        bool value;
        QDirIterator it(QDir::homePath(),all,QDir::AllDirs,QDirIterator::Subdirectories);
        while(it.hasNext())
        {

            QDir dire(it.next());
            if(dire.dirName().startsWith(".")){value =false;qDebug()<<"hidden";}
            else{folders<<it.next();value = true;qDebug()<<"ok";}



        }
  //  folders = dir.entryList(searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
        qint64 u = folders.size();
        qint64 pro =0;
    for(const auto & folder : folders)
    {
        QDirIterator iter(folder,QDir::AllDirs);
          while(iter.hasNext())
          {
             QDir dir(iter.next());
             if(dir.exists())
             {
               if(dir.dirName()=="bin"|| dir.dirName()=="installer" || dir.dirName()=="include"){value =false;qDebug()<<"installer package";}
               else {
                   if (containsApps(folder)) {
                       folderApps << folder;
                       value = true;
                       qDebug() << "filling folderApps";

                   } else {
                       if (containsComp(folder)) {
                           folderComp << folder;
                           qDebug() << "filling folderComp";
                       };
                   }
    }}}
          --u;
        pro=100-100*u/folders.size();
        QVariant T(pro);
     qDebug()<<"progress : "+T.toString()+"%";

}
    return value;
}

void Analysa::hek()
{
      qDebug()<<"preparing";
}
bool Analysa::containsApps(const QString& folderPath)
{



    QDirIterator it(folderPath,list_Apps,QDir::Files);
    bool value=false;
    while(it.hasNext())
    {
         QFileInfo infos(it.next());
         QString ext =infos.suffix();
         if(veriff(list_Apps,ext))
             value =true;


    }

    return value;
}

bool Analysa::containsComp(const QString& folderPath)
{

    QDirIterator it(folderPath,list_Archive,QDir::Files);
    bool value=false;
    while(it.hasNext())
    {
         QFileInfo infos(it.next());
         QString ext =infos.suffix();
         if(veriff(list_Archive,ext))
             value =true;

    }

    return value;
}


bool Analysa::veriff(const QList<QString>& liste,const QString& item)
{
    for (auto &i: liste) {
        if (item == i) {
            return true;
        };
    };
    return false;

   }


