#ifndef DIALOG_H
#define DIALOG_H
 #include <QDir>
#include <QDialog>
#include<QMovie>
#include<QVBoxLayout>
#include<QMenu>
#include<QToolBar>
#include<QMenuBar>
#include<QMainWindow>
#include<QDesktopServices>
#include "CentralWidget.h"
#include "../FenPrincipale.h"
#include "tabwidget.h"
class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog();
    FenPrincipale *p;
public slots:
     //void on_treeView_clicked(const QModelIndex &index);
    //void enter(const QString &path);
    //void item_right_clicked();

private:

    QVBoxLayout *layout;
    QToolBar *toolBar;
    QMenu *open;
    QMenu *Openwith;
    QMenu *compress;
    QMenu *details;
    QMenu *openAs;
    QMainWindow *m;


};




#endif // DIALOG_H
