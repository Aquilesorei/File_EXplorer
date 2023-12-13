#ifndef FOLDERCONTEXTMENU_H
#define FOLDERCONTEXTMENU_H
#include <QMenu>


#include "../Achille.h"
#include "../Actions.h"

class FolderContextMenu : public QMenu {
    Q_OBJECT
public:
    explicit FolderContextMenu(Achille *parent);


private:
    Achille *bWidget;
    QAction *openTab, *cut, *copy,*rename, *trash, *restore, *deleteFolder,*open,*paste,*properties;
    QAction *compress,*openTerminal;
    static void _open();
    void _openTab();
    void _paste();
    void _cut();
    void _copy();
    void _rename();
    void _properties();
    void _delete();
    void _compress();
    static void _openT();
    Actions *Act;


};
#endif // FOLDERCONTEXTMENU_H
