#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H
#include<QtWidgets>
#include <QMainWindow>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QContextMenuEvent>
#include <QToolBar>
#include <QToolButton>
#include<QMainWindow>
#include<QFileSystemModel>
#include<QStorageInfo>
#include<QMenuBar>
#include<QToolButton>
#include <QTreeView>
#include<QToolBar>
#include<QPushButton>
#include<QGridLayout>
#include<QTabWidget>
#include <QSplitter>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QProgressBar>
#include<QList>
#include<QListView>
#include<QTableView>
#include <QFlags>
#include <QVariant>
#include <QMenuBar>
#include <QPropertyAnimation>
#include "components/leftWidget.h"
#include "components/CentralWidget.h"
#include "components/Welcome.h"
#include "components/tabwidget.h"
#include "toolbars/toolbarfichiers.h"
class QMainWindow;

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;


class CentralWidget;
class Welcome;
class tabWidget;
class leftWidget;
enum class central{tab,welcome};
Q_DECLARE_FLAGS(Centrals,central);
Q_DECLARE_OPERATORS_FOR_FLAGS(Centrals);
class toolbarfichier;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

   Q_OBJECT

public:
    MainWindow();

    CentralWidget *A;
    Welcome *w;

    //menuoption
    QAction *ActionAnalyse;
    QAction *ActionRefresh;
    QAction *ActionSetting;
    /*QClipboard *board;
    QString elem;
    bool unique= false;
    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    QString currentName = tabWidget::currentWidget()->currentItemName();
    QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection*/


public slots:
  // void on_picture_clicked();
   void onListViewClicked();

   void onDownloadsClicked();
   void onImageClicked();
   void onMusicClicked();
   void onVideosClicked();
   void onDocumentClicked();
   void onDesktopClicked();

private slots :
   void setDock(Centrals flags);
   void  _reculer();
   void _avancer();
   void onRefreshClicked();
   void onHomeClicked();
   void onDirChanged(const QString& path);
   void onHistoryChanged();
   void selecta();
   void handleSelect();
   void status(int nb);
   void configToolbar(Centrals flags);
  // void _cut();
  // void _paste();
  // void _copy();

signals :
   void centralChanged(Centrals flags);


protected :

  QMainWindow *window;
    void setNavBar();

    QMenu *Menu;
    QMenu *MenuOption;
    QMenu *MenuView;
    QMenu *MenuNew;
    QMenu *MenuSort;
    QTreeView *Tree;
    toolbarfichier *toolbarFichiers;
    QToolBar *Banane;
   QToolButton *buton;
    QGridLayout *layout;
    QTabWidget *onglets;
    QWidget *widi;

    QLabel *label;
    QWidget *page1;
    QWidget *page2;
    QWidget *page3;
    QTabWidget *Tab;
    QProgressBar *Bar;
    tabWidget *tab;
    QVBoxLayout *bayout;
    QVBoxLayout *bayout1;
     QVBoxLayout *bayout2;
     QStorageInfo Storage;
     float occupe,  Frac;
      int index ;
     //Dialog *ba;

    //les boutons
     QToolBar *navig;

    QPushButton *home;

    // leurs sous menus de menuFichier

    QMenuBar *danse;
   // QToolButton *view,*New,*sort;
    QToolButton *avancer, *reculer, *refresh, *Home;
    void connecto();
    leftWidget *left;
};


#endif // FENPRINCIPALE_H
