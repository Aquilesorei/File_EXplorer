#include <QFutureWatcher>
#include <QPixmap>
#include <QFile>
#include "BackgroundContextMenu.h"
#include <QtConcurrent>
#include <QFuture>
#include <QMetaObject>
#include "Dialogs/backD.h"
#include "../components/tabwidget.h"
#include  <QMessageBox>
BackgroundContextMenu::BackgroundContextMenu(CentralWidget *b) {
    bWidget = b;
    //l'erreur vient de Actions il y a une erreur de segmentation
    //essai d'implementer les methodes directement ici et verifie si aucune d'elle ne necessite
    //current index or current itemnames
    //Act = new Actions;
    newfile = new QAction(QPixmap(":/icons/edit-cut.svg"), "New File", this);
    newfolder = new QAction(QPixmap(":/icons/edit-cut.svg"), "New Folder", this);
    Iconview = new QAction(QPixmap(":/icons/edit-cut.svg"), "Icon view", this);
    Listview = new QAction(QPixmap(":/icons/edit-cut.svg"), "List view", this);
    //sort = new QAction(QPixmap(":/icons/edit-cut.svg"), "Sort", this);
    openTerminal = new QAction(QPixmap(":/icons/tab-new.svg"), "Open in windows Terminal", this);

    properties = new QAction(QPixmap(":/icons/tab-new.svg"), "Properties", this);
    paste = new QAction(QPixmap(":/icons/tab-new.svg"), "Paste", this);



    connect(newfile, &QAction::triggered, this, &BackgroundContextMenu::_newfile);
    connect(newfolder, &QAction::triggered, this, &BackgroundContextMenu::_newFolder);
    connect(paste, &QAction::triggered, this, &BackgroundContextMenu::onpaste);
    connect(openTerminal, &QAction::triggered, this, &BackgroundContextMenu::openT);
   connect(properties, &QAction::triggered, this, &BackgroundContextMenu::proper);
    connect(Iconview, &QAction::triggered, this, &BackgroundContextMenu::oniview);
    connect(Listview, &QAction::triggered, this, &BackgroundContextMenu::onlview);




   this->addAction(newfolder);
   this->addAction(newfile);

    this->addAction(paste);
    this->addAction(properties);
    this->addAction(openTerminal);
    this->addSeparator();
    QMenu *viea = this->addMenu("View");
    viea->addAction(Iconview);
    viea->addAction(Listview);
   // this->addAction(sort);




  /*  if (tabWidget::currentWidget()->fsCurrentPath()==Trash::folderPath) {
        this->add//Action(restore);
    } else {
        this->add//Action(trash);
    }*/

    //this->add//Action(deleteAll);
    //making all things ready for copy progress
     pro=new QProgressDialog(this);
     //progress = new Progressa(this);
      /*QObject::connect(this,&BackgroundContextMenu::Value, progress->CurrentFileProgress,&QProgressBar::setValue);
      QObject::connect(this,&BackgroundContextMenu::fdone, progress->CurrentFileProgress,&QProgressBar::reset);*/



      QObject::connect(this,&BackgroundContextMenu::started, this,&BackgroundContextMenu::handleProgress);


      pro->setRange(0,101);
      pro->setGeometry(10, 60, 150, 20);
      first =true;


}

BackgroundContextMenu::~BackgroundContextMenu() {

}
void BackgroundContextMenu::openT()
{
    QString path = tabWidget::currentWidget()->fsCurrentPath();       
        QProcess proc;
        proc.setWorkingDirectory(path);
        proc.setProgram("odyt");
        proc.startDetached();
}
void BackgroundContextMenu::proper()
{
    backD D;
    D.exec();
}
void BackgroundContextMenu::onpaste()
{




   // void copia(QString src,QString dest);
    bool move = false;
      //  QFuture<qlonglong> future = QtConcurrent::run(this,&backD::analysa);
    QStringList listu = texte.split("\n");
    if(listu.endsWith("move"))
    {
       move = true;
       listu.pop_back();
    }
     bool success=false;

    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();



    if(listu.size()>1){

   for(int i= 0;i<listu.size();++i)
    {


       QFileInfo infos(listu.at(i));
       QString filename = infos.fileName();

       QFile srcrPath(currentPath);
     QString desPath= currentPath+filename;

     if(infos.isFile()){


        /* QFutureWatcher<void> futureWatcher;
         //QObject::connect(&futureWatcher, SIGNAL(progressRangeChanged(int,int)), &progressDialog, SLOT(setRange(int,int)));
        // QObject::connect(&futureWatcher, SIGNAL(Value(int value)), &progressDialog, SLOT(setValue(int)));
         QObject::connect(&futureWatcher,&QFutureWatcher<void>::finished,&futureWatcher,&QFutureWatcher<void>::deleteLater);
         QFuture<void> future =QtConcurrent::run([&, this, listu]()-> void{ copia(listu.at(i),desPath); });

         futureWatcher.setFuture(future);
//          progressDialog.exec();
        // futureWatcher.setFuture(QtConcurrent::run([&, this, listu] () -> int { copia(listu.at(i),desPath); return 0;}));
       // QFuture<void> future = QtConcurrent::run(&BackgroundContextMenu::copia,listu.at(i),desPath);
       futureWatcher.waitForFinished();*/

         copia(listu.at(i),desPath);
         if(first)
         {
             pro->exec();
             first= false;
         }



        // if(continuer)
          //+   continue;



     }
     else
     {
         copyDirectoryFiles(listu.at(i),desPath,true);

      }
        success = true;

    }}
    else if(listu.size()==1)
    {


        QString linee = listu.at(0);

        QFileInfo infos(linee);
         //qDebug()<<linee;

        if(infos.isFile())
            copia(linee,currentPath+infos.fileName());
        else if(infos.isDir())
            copyDirectoryFiles(linee,currentPath+infos.fileName(),true);
        success = true;

    }
    else
    {}


     if(move && success)
     {
        foreach(auto item,listu)
         {
             QFile::remove(item);
         }
     }
     //list.clear();*/

}

void BackgroundContextMenu::handleProgress()//will be
{
    connect(&timer,&QTimer::timeout,this,&BackgroundContextMenu::updateProgress);
    timer.start(100);
}

void BackgroundContextMenu::updateProgress()
{
    QObject::connect(this,&BackgroundContextMenu::Value, pro,&QProgressDialog::setValue);
    QObject::connect(this,&BackgroundContextMenu::fdone, pro,&QProgressDialog::reset);

}
void BackgroundContextMenu::_newfile()
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
void BackgroundContextMenu::_newFolder()
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
        } // i like that

}
void BackgroundContextMenu::oniview()
{
    tabWidget::currentWidget()->setIconView();

}
void BackgroundContextMenu::onlview()
{
    tabWidget::currentWidget()->setListView();
}
void BackgroundContextMenu::onsort()
{
   //Act->sort();

}

bool BackgroundContextMenu::copia(QString src,QString dest)
{
    // took from QFile::copy in Qt 5.0.2 method and modified to fulfill my needs
       emit started();
        QFile f(src);
        if (src.isEmpty()) {
            qWarning("QFile::copy: Empty or null file name");
            return false;
        }
        if (QFile(dest).exists()) {
            // ### Race condition. If a file is moved in after this, it /will/ be
            // overwritten. On Unix, the proper solution is to use hardlinks:
            // return ::link(old, new) && ::remove(old); See also rename().
            qWarning("Destination file exists");
            return false;
        }

        bool error = false;
        if(!f.open(QFile::ReadOnly)) {
            error = true;
            qWarning("Cannot open %s for input", qPrintable(src));
        } else {
            QString fileTemplate = QLatin1String("%1/qt_temp.XXXXXX");
    #ifdef QT_NO_TEMPORARYFILE
            QFile out(fileTemplate.arg(QFileInfo(dest).path()));
            if (!out.open(QIODevice::ReadWrite))
                error = true;
    #else
            QTemporaryFile out(fileTemplate.arg(QFileInfo(dest).path()));
            if (!out.open()) {
                out.setFileTemplate(fileTemplate.arg(QDir::tempPath()));
                if (!out.open())
                    error = true;
            }
    #endif
            if (error) {
                out.close();
                f.close();
                qWarning("Cannot open for output");
            } else {
                char block[4096];
                qint64 totalRead = 0;
                for (int i = 1; !f.atEnd(); i++) {
                    qint64 in = f.read(block, sizeof(block));
                    if (in <= 0)
                        break;
                    totalRead += in;
                    //data->bytes_so_far += in;
                    if (i % 5 == 0 && totalRead != f.size()) {
                        emit Value(totalRead*100/f.size());
                    }
                    if(in != out.write(block, in)) {
                        f.close();
                        qWarning("Failure to write block");
                        error = true;
                        break;
                    }
                }

                if (totalRead != f.size()) {
                    // Unable to read from the source. The error string is
                    // already set from read().
                    error = true;
                }
                if (!error && !out.rename(dest)) {
                    error = true;
                    f.close();
                    qWarning("Cannot create %s for output", qPrintable(dest));
                }
    #ifdef QT_NO_TEMPORARYFILE
                if (error)
                    out.remove();
    #else
                if (!error)
                    out.setAutoRemove(false);
    #endif
            }
        }
        if(!error) {
            QFile::setPermissions(dest, f.permissions());
            f.close();

          // emit Value(totalRead*100/f.size());
            return true;
        }
        emit fdone();
        return false;



}
bool BackgroundContextMenu::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{

    QDir sourceDir(fromDir);
        QDir targetDir(toDir);
        if(!targetDir.exists()){    /* if directory don't exists, build it */
            if(!targetDir.mkdir(targetDir.absolutePath()))
                return false;
        }

        QFileInfoList fileInfoList = sourceDir.entryInfoList();
        foreach(QFileInfo fileInfo, fileInfoList){
            if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
                continue;

            if(fileInfo.isDir()){    /* if it is directory, copy recursively*/
                if(!copyDirectoryFiles(fileInfo.filePath(),
                    targetDir.filePath(fileInfo.fileName()),
                    coverFileIfExist))
                    return false;
            }
            else{
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Question);
                msgBox.setText("The file(s) already exits !");
                msgBox.setInformativeText("Some files you are trying to copy already exists Do you want to replace them ?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);

                /* if coverFileIfExist == true, remove old file first */
                if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                    switch (msgBox.exec()) {
                                    case (QMessageBox::No):
                                        break;
                                    case (QMessageBox::Yes):
                                        targetDir.remove(fileInfo.fileName());
                                        break;

                                }
                }

                // files copy
                   //extern void copia(QString src,QString dest);

                  // QFuture<void> future = QtConcurrent::run(copia,fileInfo.filePath(),targetDir.filePath(fileInfo.fileName()));
                //    future.waitForFinished();
                 // QProgressDialog dialog;
                   //dialog.setLabelText(QString(" cCopied %1 files(s) of %2").arg(QThread::idealThreadCount()));

                copia(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName()));
            }

        }
        return true;

}

