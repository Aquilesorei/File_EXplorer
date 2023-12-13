#include "Actions.h"
#include <QFile>
#include <QDir>
#include <iostream>
#include <QProgressDialog>
#include <string>
//#include <boost/asio.hpp>
#include <QByteArray>
//#include <zlib/quazip>
#include <QMessageBox>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QProcess>
#include <QClipboard>
#include <QMimeData>
#include "tabwidget.h"
#include "Achille.h"
#include <QDialog>
#include <QByteArray>
#include "menu/Dialogs/FolderD.h"
#include "menu/Dialogs/FileD.h"
#include "menu/Dialogs/MultiD.h"
#include "menu/Dialogs/SortD.h"
#include "menu/Dialogs/openWith.h"
//#include "Trash.h"
#include <QTextStream>
//#include <boost/asio.hpp>

#include "libs/quazip/JlCompress.h"
//#include <quazip5/quazip.h>
#include "Archiva.h"
Actions::Actions()
{

    board = QApplication::clipboard();
    A = new Achille;




}
void Actions::openCurrentFile()
{
    QString path = tabWidget::currentWidget()->fsCurrentPath();
      path+=tabWidget::currentWidget()->currentItemName();
      //qDebug()<<path +"c'est moiiii";
      QDesktopServices::openUrl(QUrl::fromLocalFile(path));

}
void Actions::Cut()
{
    board->clear();


 // QList<QListWidgetItem *> selectedItems = tabWidget::currentWidget()->currentItemNames();//la liste est vide
   QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();

  const QString path = tabWidget::currentWidget()->currentPath;


  if(selectedItems.size()>1){
      QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
      QString ajout;
      for(const auto & selectedItem : selectedItems)
      {
        // list.push_back(path+selectedItems.at(i));
          ajout += path+selectedItem+"\n";



      }
      ajout += "move";
     board->setText(ajout);
  }
  else if(selectedItems.size()==1)
  {  QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
      elem = currentPath+selected;
      board->setText(elem+"\nmove");
      unique = true;

  }
  move = true;
 //qDebug()<<tabWidget::currentWidget()->currentPath+selectedItems.at(0)+"cest ça";





}

void Actions::copy()
{
    board->clear();




 // QList<QListWidgetItem *> selectedItems = A->view->selectedItems();
    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();

    QString path = tabWidget::currentWidget()->currentPath;



  if(selectedItems.size()>1){
     QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
      QString ajout;
      for(const auto & selectedItem : selectedItems)
      {
        // list.push_back(path+selectedItems.at(i));
          ajout += path+selectedItem+"\n";

         //board->setText(list.at(i));

      }

      board->setText(ajout);

       }else if(selectedItems.size()==1)
  {    QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
      elem = currentPath+selected;

      board->setText(elem);
      unique = true;

  }
  move = false;
  //qDebug()<<list.at(0)+"cest ça";


}
void Actions::paste()
{


   /* thread = new CopyThread();
    thread->copyStart();
    thread->run();
   // qDebug()<<liste.size();

   bool success=false;

   //qDebug()<<tabWidget::currentWidget()->currentPath+"cest pla";

   QString tra = board->text();
   QStringList listu = tra.split("\n");
   qDebug()<<listu.size();

   if(listu.size()>1){
  for(int i= 0;i<listu.size();++i)
   {


      QFileInfo infos(listu.at(i));

      QFile srcrPath(currentPath);
       thread->fileCopy(listu.at(i));

      //QFile::copy(listu.a(listu.at(i));

      QFile dst(currentPath+infos.fileName());

        emit pasta(listu.at(i),currentPath+infos.fileName(),false);
      QString defPath = GetNearestExistingAncestorOfPath(listu.at(i));
       thread->setSrcDirPath(defPath);
       thread->setDesDit(i),currentPath+infos.fileName());

       success = true;

   }}
   else if(unique)
   {

       QString linee = board->text();
       QFileInfo infos(linee);
        qDebug()<<linee;
       QFile::copy(linee,currentPath+infos.fileName());
       unique = false;
        emit pasta(linee,currentPath+infos.fileName(),true);
   }
   else
   {}


    if(move && success)
    {
       for(int i= 0;i<listu.size();++i)
        {

            QFile::remove(listu.at(i));
        }
    }
    //list.clear();*/

}
void Actions::rename() const
{

    QString currentName = tabWidget::currentWidget()->currentItemName();
    QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection

     QInputDialog dialog;
      dialog.setWindowTitle("Rename");
       dialog.setLabelText("Enter your new file/folder name:");
       dialog.setTextValue(currentName);
       if (dialog.exec()) {
           QString newName = dialog.textValue();
           if ((newName==currentName)||(QFile(currentPath+newName).exists())) {
               QMessageBox msg;
               msg.setWindowTitle("Error");
               msg.setIcon(QMessageBox::Critical);
               msg.setText("A file or folder already exists with that same name.");
               msg.exec();
           } else {
               QString newPath = currentPath+newName;
               QString oldPath = currentPath+currentName;
               bool ret = QFile(oldPath).rename(newPath);
               if (!ret) {
                   QMessageBox msg;
                   msg.setWindowTitle("Error");
                   msg.setIcon(QMessageBox::Critical);
                   msg.setText("There was an error renaming this file or folder!");
                   msg.setDetailedText("This could mean that the file is read-only, "
                                       "or that you do not have the proper permissions "
                                       "to access it.");
                   msg.exec();
               }
           }
       }
   }
void Actions::properties() const
{

   // QString selectedItems = tabWidget::currentWidget()->view->currentItem()->text();
   // QFileInfo infos(currentPath+selectedItems+'/');

        FolderD D(A);
        D.exec();

}
void Actions::fproperties() const
{
        FileD b(A);
        b.exec();

}
void Actions::mproperties() const
{
    MultiD N(A);
    N.exec();

}

 void Actions::deletef() const
 {      QString currentName = tabWidget::currentWidget()->currentItemName();
        QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection

     QFileInfo infos(currentPath+currentName);
     if(infos.isDir())
     {
         QFile file(currentPath+currentName);
         file.remove();
     }
     else if(infos.isFile())
     {
         QFile file(currentPath+currentName);
         file.remove();

     }

}
void Actions::compress()
{/*
    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();//plusieurs
         QStringList list;
         QString currentName = tabWidget::currentWidget()->currentItemName();
         QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
        QString path = tabWidget::currentWidget()->currentPath;
         foreach(auto elem,selectedItems)
         {
           list <<path+elem;
         }
        if(selectedItems.size()>1)
        {

            QInputDialog dialog;
                dialog.setWindowTitle("Create archive");
                dialog.setLabelText("What do you want to name your archive ?");
                QFileInfo infos(selectedItems.at(0));
                dialog.setTextValue(infos.baseName());
                if(dialog.exec())
                {
                  QString val = dialog.textValue();
                  //do stuff
              //    QuaZip *zip = new QuaZip(currentPath+val+".zip");
                  Archiva::archive(currentPath+val+".zip",list,"bro ça marche ! ");
                  foreach(auto item,list)
                  {
                      QFileInfo infos(item);
                      if(infos.isFile())
                      {
                        if(!JlCompress::compressFile(zip,item,infos.fileName()))
                        {
                             qDebug()<<"could not compress";

                          }
                       else
                             qDebug()<<"compressed successfully";
                      }
                      else
                      {
                          QDir dir(item);
                          JlCompress::compressSubDir(zip,dir.absolutePath(),currentPath,true,QDir::AllEntries);
                      }
                  }
                  zip->close();
                }
                }
               else if(selectedItems.size()==1)
               {
               QInputDialog dialog;
                dialog.setWindowTitle("Create archive");
                dialog.setLabelText("What do you want to name your archive ?");
                QFileInfo fileInfo(currentPath+selected);
                dialog.setTextValue(fileInfo.baseName());
                if(dialog.exec())
               {
                     QString val = dialog.textValue();
                    QFileInfo infos(currentPath+selected);
                    if(infos.isFile())
                    {
                        qDebug()<<"trying";
                      if(!JlCompress::compressFile(currentPath+val+".zip",currentPath+selected))
                       {
                            qDebug()<<"could not compress";
                         }
                      else
                            qDebug()<<"compressed successfully";
                    }
                    else
                    {
                        JlCompress::compressDir(currentPath+val+".zip",currentPath+selected);
                    }
                }

}
      //qDebug()<<currentPath+selectedItems;

      //QFile fo(currentPath);


*/
}
void Actions::uncompress()
{


}
void Actions::newFile()
{
    QInputDialog dialog;
       dialog.setWindowTitle("Create File");
       dialog.setLabelText("What do you want to name your file?");
       dialog.setTextValue("untitled file");
       if (dialog.exec()) {
           QString val = dialog.textValue();
           QString path = tabWidget::currentWidget()->fsCurrentPath();
           path+=val;
           if (QDir(path).exists()) {
               QMessageBox msg;
               msg.setWindowTitle("Error");
               msg.setIcon(QMessageBox::Critical);
               msg.setText("A file or folder with that name already exists.");
               msg.exec();
           } else {
               QFile file(path);
               if (file.open(QFile::WriteOnly)) {
                   file.close();
               }
           }
       }
}
void Actions::newFolder()
{
    QInputDialog dialog;
        dialog.setWindowTitle("Create Folder");
        dialog.setLabelText("What do you want to name your folder?");
        dialog.setTextValue("untitled folder");
        if (dialog.exec()) {
            QString val = dialog.textValue();
            QString path = tabWidget::currentWidget()->fsCurrentPath();
            path+=val;
            if (QDir(path).exists()) {
                QMessageBox msg;
                msg.setWindowTitle("Error");
                msg.setIcon(QMessageBox::Critical);
                msg.setText("A file or folder with that name already exists.");
                msg.exec();
            } else {
                QDir().mkdir(path);
            }
        }
}

void Actions::sort()
{
    SortD fiou;
    fiou.exec();
}

void Actions::_openWith()
{

    QString path = tabWidget::currentWidget()->fsCurrentPath();
      path+=tabWidget::currentWidget()->currentItemName();
     openWith op(path);
     op.exec();

    /* std::string pathu = path.toStdString();//work
    ShellExecuteA(NULL,NULL,"",0,0,SW_NORMAL);//work
    QString ShellCmd = "C:\\Windows\\system32\\shell32.dll,OpenAs_RunDLL \""+path +"\"";
    ShellExecuteA(0,"openas", "C:\\Windows\\system32\\rundll32.exe",ShellCmd.toStdString().c_str(),NULL, SW_NORMAL);*/

}

bool Actions::deleteFile() const
{    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();
     QString currentName = tabWidget::currentWidget()->currentItemName();
     QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
     QString path = tabWidget::currentWidget()->currentPath;

      if(selectedItems.size()>1){

          for(const auto & selectedItem : selectedItems)
          {
              QFileInfo infos(selectedItem);
              if(infos.isFile())
              {
                  if(!QFile::moveToTrash(selectedItem)){return false;}

              }
              else if(infos.isDir())
              {
                if(!QFile::moveToTrash(selectedItem)){return false;}

              }
          }
      }
      else if(QFile(currentPath+selected).exists())
      {
         if(!QFile::moveToTrash(currentPath+selected)){return false;}
      }
   QMessageBox::information(A,"Delete","The files have been moved to trash succcessfully",QMessageBox::Ok);
      return true;
}


