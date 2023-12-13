#ifndef DIRVIEW_H
#define DIRVIEW_H
#include <QtWidgets>
#include <QListView>
#include <QUrl>
#include <QDir>
#include <QDebug>
#include<QApplication>
#include <QStyleOptionViewItem>
#include "../Achille.h"
#include <QDesktopServices>
#include <QItemSelectionModel>
class FenPrincipale;
class Achille;
class DirView : public QListWidget
{
Q_OBJECT
public :
    explicit DirView(QWidget *parent= 0);
    ~DirView();
    QItemSelectionModel *selection;

    void mousePressEvent(QMouseEvent *event);
    Achille *bWidget;
    void keyPressEvent(QKeyEvent *event);

signals:
//    void search(const QString& str);
    void on_folder_clicked();
protected:


};


#endif // DIRVIEW_H