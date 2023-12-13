#include "Archiva.h"
#include "qdir.h"
#include "../libs/quazip/JlCompress.h"
Archiva::Archiva(): QWidget()
{


}
/*
 * to emit signal from static member , you can create a fonction that takes the data you want to emit as parmater and then emit signal
 * not that i haven't try it before , but i'm gonna try it later
*/


bool Archiva::archive(const QString & filePath, const QStringList & list, const QString & comment ) {

QuaZip zip(filePath);
zip.setFileNameCodec("IBM866");

if (!zip.open(QuaZip::mdCreate)) {
   // myMessageOutput(true, QtDebugMsg, QString("testCreate(): zip.open(): %1").arg(zip.getZipError()));
    return false;
}

char c;
foreach(auto item,list)
{

    //put file in the zip
    QFileInfo infos(item);
    if(infos.isFile())
    {
        QuaZipFile outFile(&zip);
        QFile inFile(item);
         QString fileNameWithRelativePath = infos.filePath().remove(0, infos.absolutePath().length() + 1);
        if (!inFile.open(QIODevice::ReadOnly)) {
            qDebug()<<"cannot open source file";
            //myMessageOutput(true, QtDebugMsg, QString("testCreate(): inFile.open(): %1").arg(inFile.errorString().toLocal8Bit().constData()));
            return false;
        }

        if (!outFile.open(QIODevice::WriteOnly, QuaZipNewInfo(fileNameWithRelativePath, infos.filePath()))) {
           // myMessageOutput(true, QtDebugMsg, QString("testCreate(): outFile.open(): %1").arg(outFile.getZipError()));
             qDebug()<<"cannot open dest file";
            return false;
        }

        while (inFile.getChar(&c) && outFile.putChar(c));

        if (outFile.getZipError() != UNZ_OK) {
             qDebug()<<"unable to write to zip file";
           // myMessageOutput(true, QtDebugMsg, QString("testCreate(): outFile.putChar(): %1").arg(outFile.getZipError()));
            return false;
        }

        outFile.close();

        inFile.close();

    }
    else if(infos.isDir())
    {

        //recursivey add to zip
        QDir dir(item);
        if (!dir.exists()) {
           // myMessageOutput(true, QtDebugMsg, QString("dir.exists(%1)=FALSE").arg(dir.absolutePath()));
            return false;
        }
        QuaZipFile outFile(&zip);
        // Если файл в поддиректории, то добавляем имя этой поддиректории к именам файлов
        // например: fileInfo.filePath() = "D:\Work\Sources\SAGO\svn\sago\Release\tmp_DOCSWIN\Folder\123.opn"
        // тогда после удаления части строки fileNameWithSubFolders будет равен "Folder\123.opn" и т.д.
        QString fileNameWithRelativePath = infos.filePath().remove(0, dir.absolutePath().length() + 1);
        QFile inFile;
        inFile.setFileName(infos.filePath());

        if (!inFile.open(QIODevice::ReadOnly)) {
            //myMessageOutput(true, QtDebugMsg, QString("testCreate(): inFile.open(): %1").arg(inFile.errorString().toLocal8Bit().constData()));
            return false;
        }

        if (!outFile.open(QIODevice::WriteOnly, QuaZipNewInfo(fileNameWithRelativePath, infos.filePath()))) {
           // myMessageOutput(true, QtDebugMsg, QString("testCreate(): outFile.open(): %1").arg(outFile.getZipError()));
            return false;
        }

        while (inFile.getChar(&c) && outFile.putChar(c));

        if (outFile.getZipError() != UNZ_OK) {
           // myMessageOutput(true, QtDebugMsg, QString("testCreate(): outFile.putChar(): %1").arg(outFile.getZipError()));
            return false;
        }

        outFile.close();

        if (outFile.getZipError() != UNZ_OK) {
           //// myMessageOutput(true, QtDebugMsg, QString("testCreate(): outFile.close(): %1").arg(outFile.getZipError()));
            return false;
        }

        inFile.close();

    }

}

// Создаем массив состоящий из QFileInfo объектов

// + комментарий
if (!comment.isEmpty())
    zip.setComment(comment);

zip.close();

if (zip.getZipError() != 0) {
   // myMessageOutput(true, QtDebugMsg, QString("testCreate(): zip.close(): %1").arg(zip.getZipError()));
    return false;
}

return true;
}


void Archiva::recurseAddDir(const QDir& d, QStringList & list){

   QStringList qsl = d.entryList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

   foreach (QString file, qsl) {

       QFileInfo finfo(QString("%1/%2").arg(d.path(),file));

       if (finfo.isSymLink())
           return;

       if (finfo.isDir()) {

         //  QString dirname = finfo.fileName();
           QDir sd(finfo.filePath());

           recurseAddDir(sd, list);

       } else
           list << QDir::toNativeSeparators(finfo.filePath());
   }
}
