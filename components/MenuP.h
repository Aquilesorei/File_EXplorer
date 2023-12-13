#ifndef MENUP_H
#define MENUP_H
#include <QMenuBar>
#include <QMenu>
#include<QLabel>
#include<QVBoxLayout>
#include<QProgressBar>
#include<QtWidgets>
#include<QStorageInfo>
#include<QMenuBar>
#include<QTabWidget>


class Actions;
class MenuP : public QMenuBar
{
    Q_OBJECT

public :
    explicit MenuP();
    ~MenuP();
    QPushButton *home;

    QPushButton *Download;

    QPushButton *NewFile;

    QPushButton *Recycles;
        QPushButton *Secret;
private:
    QMenu *Menu,*MenuOption;
    QAction *ActionAnalyse;
    QAction *ActionRefresh;
    QAction *ActionSetting;
    QTabWidget *onglets;
    QWidget *widi;
    Actions *Act;
    QLabel *label;
    QWidget *page1;
    QWidget *page2;
    QWidget *page3;
    QTabWidget *Tab;
    QProgressBar *Bar;
    QVBoxLayout *bayout;
    QVBoxLayout *bayout1;
     QVBoxLayout *bayout2;
     QStorageInfo Storage;
     float occupe;
     float Frac;
     void refresh();



};
#endif // MENUP_H
