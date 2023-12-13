#ifndef ACTIONS_H
#define ACTIONS_H
#include <QWidget>
#include <QAction>
#include <QDialog>
#include <QThread>
#include <string>
#include "Achille.h"
#include <QStringList>
#include <QClipboard>
#include "tabwidget.h"
#include <QProgressDialog>
#include <QtConcurrent>
#include <QFuture>
class Actions  : public QObject
{
   Q_OBJECT
    //friend class CopyThread;
public :
    explicit Actions();
    /**hide*/
    static void openCurrentFile();


    /*static void trash();
    static void restore();

    static void openTerminal();

    void properties();


    static void Share();
    static void AddBookmark();*/
    void paste();// à voir
    void copy();
    void rename() const;
    void Cut();
    void properties() const;
    void fproperties() const;
    void mproperties() const;
     void deletef() const;
    void compress();
    void uncompress();
    static void newFolder();
    static void newFile();
    static void sort();
    static void _openWith();
    bool deleteFile() const;

    // openAs();
    QClipboard *board;
     bool move{};
     QStringList list;
     QStringList liste;
     Achille *A;
     QString elem;
     QProgressDialog *progress{};
     bool unique= false;
     QString currentPath = tabWidget::currentWidget()->fsCurrentPath();




    //void progressa(QString label,int min,int max,int value);

signals:
       void pasta(QString src,QString dest,bool unique);
      //void setValue(int index);
     // void setMaximum(int max);



private:



    //static QString handleDuplicate(QString newAddr, int index);
   // static bool copyDirectory(QString oldPath, QString newPath);
};
#endif // ACTIONS_H
