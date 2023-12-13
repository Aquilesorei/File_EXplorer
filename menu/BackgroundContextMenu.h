#ifndef BACKGROUNDCONTEXTMENU_H
#define BACKGROUNDCONTEXTMENU_H
#include <QMenu>
#include <QAction>
#include "../components/Actions.h"

#include <QClipboard>
#include "Dialogs/Progressa.h"
#include "../components/CentralWidget.h"
#include <QProgressDialog>
#include <QByteArray>
#include <QDataStream>
#include <QTimer>
class BackgroundContextMenu : public QMenu {
    Q_OBJECT

public:
    explicit BackgroundContextMenu(CentralWidget *b= nullptr);
    ~BackgroundContextMenu();
    bool copia(QString src,QString dest);
    QClipboard *board =QApplication::clipboard();
    QString texte = board->text();
    CentralWidget A;
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
    Progressa *progress;
    bool continuer;

    QProgressDialog *pro;





private:
    CentralWidget *bWidget;
    Actions *Act;
    QAction *paste, *openTerminal;
    QAction *Iconview,*Listview,*sort,*newfile,*newfolder,*properties;
     bool first;
     QTimer timer;

private slots:

    void oniview();
    void onlview();
    void onsort();
    void _newFolder();
    void _newfile();
    void proper();
    void openT();
public slots :
      void onpaste();
     void  handleProgress();
     void updateProgress();

signals:
     void Value(int value);
     int Total(int tot);
      void started();
     void fdone();
    // int setMaximum(int max);
};



#endif // BACKGROUNDCONTEXTMENU_H
