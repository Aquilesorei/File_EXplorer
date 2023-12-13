#ifndef TOOLBARP_H
#define TOOLBARP_H
#include <QToolBar>
#include <QToolButton>
#include "Actions.h"
#include "CentralWidget.h"
class Achille;
class Actions;
class ToolBarP : public QToolBar {
    Q_OBJECT
public:
    ToolBarP();
    ~ToolBarP();
    void setBrowserWidget(Achille *b);
private:
    Achille *bWidget;
    QToolButton *view, *New, *sort;
    QAction *ActionOuvrir;
    QAction *ActionShare;
    QAction *ActionDelete;
    QAction *ActionRename;
    QAction *ActionCopy;
    QAction *ActionPaste;
    QAction *ActionCut;
    QAction *ActionFind;
    Actions *Act;
    QAction *SelectA;
    void SelectAll();
    //les sous menu du menu window
    QAction *ActionClose;
    QAction *ActionCompress;
    void _paste();
    void _cut();
    void _copy();
    void _rename();
    void _delete();
    //void _compress();
    //void _uncompress();

private slots:

};
#endif // TOOLBARP_H
