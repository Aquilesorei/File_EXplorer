#ifndef ANALYSA_H
#define ANALYSA_H
#include <QThread>

class Analysa : public QObject
{
    Q_OBJECT
public :
    explicit Analysa();
    void config();
    void config2();
    bool files();
    static void hek();
   // static int progressnb;
signals:
    void progress(int progress);

 private :
     const QString workingDirectoryPath="/home/aquiles/workingDirectory/";
     QStringList list_Apps = {"sh","run","deb"};
     QStringList list_Archive = {"zip","7z","tar.gz"};
     QStringList all = list_Apps+list_Archive;
     QStringList folders,folderApps,folderComp;
     bool containsApps(const QString& folderPath);

     bool containsComp(const QString& folderPath);
     static bool veriff(const QList<QString>& liste, const QString& item) ;
};
#endif // ANALYSA_H
