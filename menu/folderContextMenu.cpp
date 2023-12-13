#include <QPixmap>
#include "../Actions.h"
#include "folderContextMenu.h"
#include "../tabwidget.h"
#include <QProcess>


FolderContextMenu::FolderContextMenu(Achille *parent) {

    bWidget = parent;
    Act = new Actions;
    properties = new QAction(QPixmap(":/icons/tab-new.svg"), "Properties", this);
    paste = new QAction(QPixmap(":/icons/tab-new.svg"), "paste", this);
    open = new QAction(QPixmap(":/icons/tab-new.svg"), "Open in the current Tab", this);
    openTerminal = new QAction(QPixmap(":/icons/tab-new.svg"), "Open in Cmd", this);
    openTab = new QAction(QPixmap(":/icons/tab-new.svg"), "Open in New Tab", this);
    cut = new QAction(QPixmap(":/icons/edit-cut.svg"), "Cut", this);
    copy = new QAction(QPixmap(":/icons/edit-copy.svg"), "Copy", this);
    rename = new QAction(QPixmap(":/icons/edit-rename.svg"), "Rename", this);
    trash = new QAction(QPixmap(":/icons/user-trash.svg"), "Move to Trash", this);
    restore = new QAction(QPixmap(":/icons/view-refresh.svg"), "Restore", this);
    deleteFolder = new QAction(QPixmap(":/icons/edit-delete.svg"), "Delete", this);
    compress = new QAction(QPixmap(":/icons/edit-delete.svg"), "Compress", this);


    connect(openTab, &QAction::triggered, this, &FolderContextMenu::_openTab);
    connect(open, &QAction::triggered, this, &FolderContextMenu::_open);
    connect(paste, &QAction::triggered, this, &FolderContextMenu::_paste);
    connect(copy, &QAction::triggered, this, &FolderContextMenu::_copy);
    connect(cut, &QAction::triggered, this, &FolderContextMenu::_cut);
    connect(rename, &QAction::triggered, this, &FolderContextMenu::_rename);
    connect(properties, &QAction::triggered, this, &FolderContextMenu::_properties);
    connect(compress, &QAction::triggered, this, &FolderContextMenu::_compress);
    connect(openTerminal, &QAction::triggered, this, &FolderContextMenu::_openT);
    this->addAction(open);
    this->addAction(openTab);
    this->addAction(openTerminal);
    this->addSeparator();
    this->addAction(cut);
    this->addAction(copy);
    this->addAction(paste);
    this->addSeparator();
    this->addAction(rename);
    this->addAction(properties);
    this->addAction(compress);
    this->addSeparator();

    //if (TabWidget::currentWidget()->fsCurrentPath()==Trash::folderPath) {
    //    this->addAction(restore);
    //} else {
     //   this->addAction(trash);
   // }

    this->addAction(deleteFolder);
}

void FolderContextMenu::_open()
{
    QString addr =tabWidget::currentWidget()->fsCurrentPath();
       if (!addr.endsWith("/")) {
           addr+="/";
       }
       addr+=tabWidget::currentWidget()->currentItemName();
       tabWidget::currentWidget()->loadDir(addr);

}
void FolderContextMenu::_openTab()
{
    QString addr = tabWidget::currentWidget()->fsCurrentPath();
       if (!addr.endsWith("/")) {
           addr+="/";
       }
       addr+=tabWidget::currentWidget()->currentItemName();
       tabWidget::addNewTab(addr);
}
void FolderContextMenu::_paste()
{
   Act->paste();
}
void FolderContextMenu::_cut()
{
    Act->Cut();
}
void FolderContextMenu::_copy()
{
    Act->copy();

}
void FolderContextMenu::_rename()
{
    Act->rename();
}

void FolderContextMenu::_properties()
{
    Act->properties();
}
void FolderContextMenu::_delete()
{
    Act->deletef();
}
void FolderContextMenu::_compress()
{
    Act->compress();
}
void FolderContextMenu::_openT()
{
    QString path = tabWidget::currentWidget()->fsCurrentPath();
    QString selectedItems = tabWidget::currentWidget()->view->currentItem()->text();

        QProcess proc;
        proc.setWorkingDirectory(path+selectedItems);
        proc.setProgram("cmd");
        proc.startDetached();

}
