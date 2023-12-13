#ifndef MULTICONTEXTMENU_H
#define MULTICONTEXTMENU_H
#include <QMenu>
#include <QAction>
#include "../components/CentralWidget.h"
#include "../components/tabwidget.h"
#include "../components/Actions.h"

class MultiContextMenu: public QMenu {
    Q_OBJECT
public:
    explicit MultiContextMenu(CentralWidget *b);
    ~MultiContextMenu();
    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();
private:
    CentralWidget *bWidget;
    Actions *Act;
    QAction *cut, *copy, *trash, *restore, *deleteAll,*openTerminal,*properties,*compress;

private slots:
    void onCutClicked();
    void onCopyClicked();
    //void onTrashClicked();
    //void onRestoreClicked();
    void onDeleteAllClicked();
    void openT();
    void proper();
    void _compress();


};
#endif // MULTICONTEXTMENU_H
