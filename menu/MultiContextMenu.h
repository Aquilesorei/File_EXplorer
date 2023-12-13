#ifndef MULTICONTEXTMENU_H
#define MULTICONTEXTMENU_H
#include <QMenu>
#include <QAction>
#include "../Achille.h"
#include "../tabwidget.h"
#include "../Actions.h"

class MultiContextMenu: public QMenu {
    Q_OBJECT
public:
    explicit MultiContextMenu(Achille *b);
    ~MultiContextMenu();
    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();
private:
    Achille *bWidget;
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
