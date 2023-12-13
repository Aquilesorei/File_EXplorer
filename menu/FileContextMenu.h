#ifndef FILECONTEXTMENU_H
#define FILECONTEXTMENU_H
#include <QMenu>
#include "../components/CentralWidget.h"
#include "../components/Actions.h"

class FileContextMenu : public QMenu {
    Q_OBJECT
public:
    explicit FileContextMenu(CentralWidget *parent=nullptr);
    void _cut();
    void _copy();
    void _deleteFile();
    void _rename();
    void _compress();
    void _uncompress();


private:
    CentralWidget *bWidget;
    QAction *cut, *copy,*rename, *trash, *restore, *deleteFile,*open,*paste,*properties;
    QAction *compress,*uncompress,*openWith;
    void _open();
    void _paste();   
    void _properties();
    void _delete();
    void _openWith();   
    Actions *Act;


};
#endif // FILECONTEXTMENU_H
