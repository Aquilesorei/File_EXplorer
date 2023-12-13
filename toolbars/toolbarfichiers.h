#ifndef TOOLBARFICHIERS_H
#define TOOLBARFICHIERS_H
#include <QToolBar>
#include <QWidget>
#include <QAction>
#include <QImage>
#include <QClipboard>
#include "../components/tabwidget.h"
#include "../components/Actions.h"
#include "../menu/BackgroundContextMenu.h"
#include "../menu/FileContextMenu.h"
#include "../menu/Dialogs/SortD.h"
class BackgroundContextMenu;
class FileContextMenu;
class toolbarfichier :public QToolBar
{
    Q_OBJECT
  public :
    explicit toolbarfichier();
    QAction *ActionAll;
private:
    QAction *ActionNouveau;
    QAction *ActionOuvrir;
    QAction *Actionview;
    QAction *ActionSort;
    QAction *ActionShare;
    QAction *ActionDelete;
    QAction *ActionFermer;
    QAction *ActionRename;
    QAction *ActionCopy;
    QAction *ActionPaste;
    QAction *ActionCut;
    QAction *ActionFind;

    //les sous menu du menu window
    QAction *ActionClose;
    QAction *ActionCompress;
    tabWidget *tab;

    QAction *ActionSecret;
    QClipboard *board;
     bool move;

     QString elem;
     bool unique= false;
     Actions *Act;
     QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
     //QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
     /* selected est la cause de l'erreur de segmentation du au fait que  rien n'est selectionné quand le compilateura appel selected
      * assure toi qu'en element est selectionné avant de demander un un selected je sais pas moi , un signal n'est t-il pas emmit lors d'une  selection ?
      * */
private slots:
    void addNew();
    void configActions();
    void _copy();
    void _cut();
    void _paste();
    void _rename();
    void _delete();
    void _sort();


};
#endif // TOOLBARFICHIERS_H
