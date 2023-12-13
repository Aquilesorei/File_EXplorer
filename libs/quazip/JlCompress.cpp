/*
Copyright (C) 2010 Roberto Pompermaier
Copyright (C) 2005-2014 Sergey A. Tachenov

This file is part of QuaZip.

QuaZip is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.

QuaZip is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with QuaZip.  If not, see <http://www.gnu.org/licenses/>.

See COPYING file for the full LGPL text.

Original ZIP package is copyrighted by Gilles Vollant and contributors,
see quazip/(un)zip.h files for details. Basically it's the zlib license.
*/

#include "JlCompress.h"

#include <utility>

bool JlCompress::copyData(QIODevice &inFile, QIODevice &outFile)
{
    while (!inFile.atEnd()) {
        char buf[4096];
        qint64 readLen = inFile.read(buf, 4096);
        if (readLen <= 0)
            return false;
        if (outFile.write(buf, readLen) != readLen)
            return false;
    }
    return true;
}

bool JlCompress::compressFile(QuaZip* zip, const QString& fileName, const QString& fileDest) {
    // zip: oggetto dove aggiungere il file
    // fileName: nome del file reale
    // fileDest: nome del file all'interno del file compresso

    // Controllo l'apertura dello zip
    if (!zip) return false;
    if (zip->getMode()!=QuaZip::mdCreate &&
        zip->getMode()!=QuaZip::mdAppend &&
        zip->getMode()!=QuaZip::mdAdd) return false;

    // Apro il file risulato
    QuaZipFile outFile(zip);
    if(!outFile.open(QIODevice::WriteOnly, QuaZipNewInfo(fileDest, fileName))) return false;

    QFileInfo input(fileName);
    if (quazip_is_symlink(input)) {
        // Not sure if we should use any specialized codecs here.
        // After all, a symlink IS just a byte array. And
        // this is mostly for Linux, where UTF-8 is ubiquitous these days.
        QString path = quazip_symlink_target(input);
        QString relativePath = input.dir().relativeFilePath(path);
        outFile.write(QFile::encodeName(relativePath));
    } else {
        QFile inFile;
        inFile.setFileName(fileName);
        if (!inFile.open(QIODevice::ReadOnly))
            return false;
        if (!copyData(inFile, outFile) || outFile.getZipError()!=UNZ_OK)
            return false;
        inFile.close();
    }

    // Chiudo i file
    outFile.close();
    if (outFile.getZipError()!=UNZ_OK) return false;

    return true;
}

bool JlCompress::compressSubDir(QuaZip* zip, const QString& dir, const QString& origDir, bool recursive, QDir::Filters filters) {
    // zip: oggetto dove aggiungere il file
    // dir: cartella reale corrente
    // origDir: cartella reale originale
    // (path(dir)-path(origDir)) = path interno all'oggetto zip

    // Controllo l'apertura dello zip
    if (!zip) return false;
    if (zip->getMode()!=QuaZip::mdCreate &&
        zip->getMode()!=QuaZip::mdAppend &&
        zip->getMode()!=QuaZip::mdAdd) return false;

    // Controllo la cartella
    QDir directory(dir);
    if (!directory.exists()) return false;

    QDir origDirectory(origDir);
	if (dir != origDir) {
		QuaZipFile dirZipFile(zip);
		if (!dirZipFile.open(QIODevice::WriteOnly,
            QuaZipNewInfo(origDirectory.relativeFilePath(dir) + QLatin1String("/"), dir), nullptr, 0, 0)) {
				return false;
		}
		dirZipFile.close();
	}


    // Se comprimo anche le sotto cartelle
    if (recursive) {
        // Per ogni sotto cartella
        QFileInfoList files = directory.entryInfoList(QDir::AllDirs|QDir::NoDotAndDotDot|filters);
        for (const auto & file : files) {
            if (!file.isDir()) // needed for Qt < 4.7 because it doesn't understand AllDirs
                continue;
            // Comprimo la sotto cartella
            if(!compressSubDir(zip,file.absoluteFilePath(),origDir,recursive,filters)) return false;
        }
    }

    // Per ogni file nella cartella
    QFileInfoList files = directory.entryInfoList(QDir::Files|filters);
    for (const auto & file : files) {
        // Se non e un file o e il file compresso che sto creando
        if(!file.isFile()||file.absoluteFilePath()==zip->getZipName()) continue;

        // Creo il nome relativo da usare all'interno del file compresso
        QString filename = origDirectory.relativeFilePath(file.absoluteFilePath());

        // Comprimo il file
        if (!compressFile(zip,file.absoluteFilePath(),filename)) return false;
    }

    return true;
}

bool JlCompress::extractFile(QuaZip* zip, const QString& fileName, const QString& fileDest) {
    // zip: oggetto dove aggiungere il file
    // filename: nome del file reale
    // fileincompress: nome del file all'interno del file compresso

    // Controllo l'apertura dello zip
    if (!zip) return false;
    if (zip->getMode()!=QuaZip::mdUnzip) return false;

    // Apro il file compresso
    if (!fileName.isEmpty())
        zip->setCurrentFile(fileName);
    QuaZipFile inFile(zip);
    if(!inFile.open(QIODevice::ReadOnly) || inFile.getZipError()!=UNZ_OK) return false;

    // Controllo esistenza cartella file risultato
    QDir curDir;
    if (fileDest.endsWith(QLatin1String("/"))) {
        if (!curDir.mkpath(fileDest)) {
            return false;
        }
    } else {
        if (!curDir.mkpath(QFileInfo(fileDest).absolutePath())) {
            return false;
        }
    }

    QuaZipFileInfo64 info;
    if (!zip->getCurrentFileInfo(&info))
        return false;

    QFile::Permissions srcPerm = info.getPermissions();
    if (fileDest.endsWith(QLatin1String("/")) && QFileInfo(fileDest).isDir()) {
        if (srcPerm != 0) {
            QFile(fileDest).setPermissions(srcPerm);
        }
        return true;
    }

    if (info.isSymbolicLink()) {
        QString target = QFile::decodeName(inFile.readAll());
        if (!QFile::link(target, fileDest))
            return false;
        return true;
    }

    // Apro il file risultato
    QFile outFile;
    outFile.setFileName(fileDest);
    if(!outFile.open(QIODevice::WriteOnly)) return false;

    // Copio i dati
    if (!copyData(inFile, outFile) || inFile.getZipError()!=UNZ_OK) {
        outFile.close();
        removeFile(QStringList(fileDest));
        return false;
    }
    outFile.close();

    // Chiudo i file
    inFile.close();
    if (inFile.getZipError()!=UNZ_OK) {
        removeFile(QStringList(fileDest));
        return false;
    }

    if (srcPerm != 0) {
        outFile.setPermissions(srcPerm);
    }
    return true;
}

bool JlCompress::removeFile(const QStringList& listFile) {
    bool ret = true;
    // Per ogni file
    for (int i=0; i<listFile.count(); i++) {
        // Lo elimino
        ret = ret && QFile::remove(listFile.at(i));
    }
    return ret;
}

bool JlCompress::compressFile(const QString& fileCompressed, const QString& file) {
    // Creo lo zip
    QuaZip zip(fileCompressed);
    QDir().mkpath(QFileInfo(fileCompressed).absolutePath());
    if(!zip.open(QuaZip::mdCreate)) {
        QFile::remove(fileCompressed);
        return false;
    }

    // Aggiungo il file
    if (!compressFile(&zip,file,QFileInfo(file).fileName())) {
        QFile::remove(fileCompressed);
        return false;
    }

    // Chiudo il file zip
    zip.close();
    if(zip.getZipError()!=0) {
        QFile::remove(fileCompressed);
        return false;
    }

    return true;
}

bool JlCompress::compressFiles(const QString& fileCompressed, const QStringList& files) {
    // Creo lo zip
    QuaZip zip(fileCompressed);
    QDir().mkpath(QFileInfo(fileCompressed).absolutePath());
    if(!zip.open(QuaZip::mdCreate)) {
        QFile::remove(fileCompressed);
        return false;
    }

    // Comprimo i file
    QFileInfo info;
    for (const auto & file : files) {
        info.setFile(file);
        if (!info.exists() || !compressFile(&zip,file,info.fileName())) {
            QFile::remove(fileCompressed);
            return false;
        }
    }

    // Chiudo il file zip
    zip.close();
    if(zip.getZipError()!=0) {
        QFile::remove(fileCompressed);
        return false;
    }

    return true;
}

bool JlCompress::compressDir(const QString& fileCompressed, const QString& dir, bool recursive) {
    return compressDir(fileCompressed, dir, recursive, QDir::Filters());
}

bool JlCompress::compressDir(const QString& fileCompressed, const QString& dir,
                             bool recursive, QDir::Filters filters)
{
    // Creo lo zip
    QuaZip zip(fileCompressed);
    QDir().mkpath(QFileInfo(fileCompressed).absolutePath());
    if(!zip.open(QuaZip::mdCreate)) {
        QFile::remove(fileCompressed);
        return false;
    }

    // Aggiungo i file e le sotto cartelle
    if (!compressSubDir(&zip,dir,dir,recursive, filters)) {
        QFile::remove(fileCompressed);
        return false;
    }

    // Chiudo il file zip
    zip.close();
    if(zip.getZipError()!=0) {
        QFile::remove(fileCompressed);
        return false;
    }

    return true;
}

QString JlCompress::extractFile(const QString& fileCompressed, const QString& fileName, QString fileDest) {
    // Apro lo zip
    QuaZip zip(fileCompressed);
    return extractFile(zip, fileName, std::move(fileDest));
}

QString JlCompress::extractFile(QuaZip &zip, const QString& fileName, QString fileDest)
{
    if(!zip.open(QuaZip::mdUnzip)) {
        return {};
    }

    // Estraggo il file
    if (fileDest.isEmpty())
        fileDest = fileName;
    if (!extractFile(&zip,fileName,fileDest)) {
        return {};
    }

    // Chiudo il file zip
    zip.close();
    if(zip.getZipError()!=0) {
        removeFile(QStringList(fileDest));
        return {};
    }
    return QFileInfo(fileDest).absoluteFilePath();
}

QStringList JlCompress::extractFiles(const QString& fileCompressed, const QStringList& files, const QString& dir) {
    // Creo lo zip
    QuaZip zip(fileCompressed);
    return extractFiles(zip, files, dir);
}

QStringList JlCompress::extractFiles(QuaZip &zip, const QStringList &files, const QString &dir)
{
    if(!zip.open(QuaZip::mdUnzip)) {
        return {};
    }

    // Estraggo i file
    QStringList extracted;
    for (int i=0; i<files.count(); i++) {
        QString absPath = QDir(dir).absoluteFilePath(files.at(i));
        if (!extractFile(&zip, files.at(i), absPath)) {
            removeFile(extracted);
            return {};
        }
        extracted.append(absPath);
    }

    // Chiudo il file zip
    zip.close();
    if(zip.getZipError()!=0) {
        removeFile(extracted);
        return {};
    }

    return extracted;
}

QStringList JlCompress::extractDir(const QString& fileCompressed, QTextCodec* fileNameCodec, const QString& dir) {
    // Apro lo zip
    QuaZip zip(fileCompressed);
    if (fileNameCodec)
        zip.setFileNameCodec(fileNameCodec);
    return extractDir(zip, dir);
}

QStringList JlCompress::extractDir(const QString& fileCompressed, const QString& dir) {
    return extractDir(fileCompressed, nullptr, dir);
}

QStringList JlCompress::extractDir(QuaZip &zip, const QString &dir)
{
    if(!zip.open(QuaZip::mdUnzip)) {
        return {};
    }
    QString cleanDir = QDir::cleanPath(dir);
    QDir directory(cleanDir);
    QString absCleanDir = directory.absolutePath();
    if (!absCleanDir.endsWith('/')) // It only ends with / if it's the FS root.
        absCleanDir += '/';
    QStringList extracted;
    if (!zip.goToFirstFile()) {
        return {};
    }
    do {
        QString name = zip.getCurrentFileName();
        QString absFilePath = directory.absoluteFilePath(name);
        QString absCleanPath = QDir::cleanPath(absFilePath);
        if (!absCleanPath.startsWith(absCleanDir))
            continue;
        if (!extractFile(&zip, QLatin1String(""), absFilePath)) {
            removeFile(extracted);
            return {};
        }
        extracted.append(absFilePath);
    } while (zip.goToNextFile());

    // Chiudo il file zip
    zip.close();
    if(zip.getZipError()!=0) {
        removeFile(extracted);
        return {};
    }

    return extracted;
}

QStringList JlCompress::getFileList(const QString& fileCompressed) {
    // Apro lo zip
    auto* zip = new QuaZip(QFileInfo(fileCompressed).absoluteFilePath());
    return getFileList(zip);
}

QStringList JlCompress::getFileList(QuaZip *zip)
{
    if(!zip->open(QuaZip::mdUnzip)) {
        delete zip;
        return {};
    }

    // Estraggo i nomi dei file
    QStringList lst;
    QuaZipFileInfo64 info;
    for(bool more=zip->goToFirstFile(); more; more=zip->goToNextFile()) {
      if(!zip->getCurrentFileInfo(&info)) {
          delete zip;
          return {};
      }
      lst << info.name;
      //info.name.toLocal8Bit().constData()
    }

    // Chiudo il file zip
    zip->close();
    if(zip->getZipError()!=0) {
        delete zip;
        return {};
    }
    delete zip;
    return lst;
}

QStringList JlCompress::extractDir(QIODevice* ioDevice, QTextCodec* fileNameCodec, const QString& dir)
{
    QuaZip zip(ioDevice);
    if (fileNameCodec)
        zip.setFileNameCodec(fileNameCodec);
    return extractDir(zip, dir);
}

QStringList JlCompress::extractDir(QIODevice *ioDevice, const QString& dir)
{
    return extractDir(ioDevice, nullptr, dir);
}

QStringList JlCompress::getFileList(QIODevice *ioDevice)
{
    auto zip = new QuaZip(ioDevice);
    return getFileList(zip);
}


QString JlCompress::extractFile(QIODevice *ioDevice, const QString& fileName, QString fileDest)
{
    QuaZip zip(ioDevice);
    return extractFile(zip, fileName, std::move(fileDest));
}

QStringList JlCompress::extractFiles(QIODevice *ioDevice, const QStringList& files, const QString& dir)
{
    QuaZip zip(ioDevice);
    return extractFiles(zip, files, dir);
}

bool JlCompress::compressMulti(const QString &zipFile, const QStringList& items,const QString &dir ,bool recursive ) {
    // first copy all files in temporary folder

    // the compress the folder and move it to th current wworking directory

    //finally remove folder
    return {};

}
