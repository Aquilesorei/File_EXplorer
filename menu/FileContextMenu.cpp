#include <QPixmap>
#include "../Actions.h"
#include "FileContextMenu.h"
#include "../tabwidget.h"


FileContextMenu::FileContextMenu(Achille *parent) {

    bWidget = parent;
    Act = new Actions;
    openWith = new QAction(QPixmap(":/icons/tab-new.svg"), "Open with", this);
    properties = new QAction(QPixmap(":/icons/tab-new.svg"), "Properties", this);
    paste = new QAction(QPixmap(":/icons/tab-new.svg"), "paste", this);
    open = new QAction(QPixmap(":/icons/tab-new.svg"), "Open", this);
    uncompress = new QAction(QPixmap(":/icons/edit-delete.svg"), "Unompress", this);
    cut = new QAction(QPixmap(":/icons/edit-cut.svg"), "Cut", this);
    copy = new QAction(QPixmap(":/icons/edit-copy.svg"), "Copy", this);
    rename = new QAction(QPixmap(":/icons/edit-rename.svg"), "Rename", this);
    trash = new QAction(QPixmap(":/icons/user-trash.svg"), "Move to Trash", this);
    restore = new QAction(QPixmap(":/icons/view-refresh.svg"), "Restore", this);
    deleteFile = new QAction(QPixmap(":/icons/edit-delete.svg"), "Delete", this);
    compress = new QAction(QPixmap(":/icons/edit-delete.svg"), "Compress", this);


     connect(deleteFile, &QAction::triggered, this, &FileContextMenu::_deleteFile);
    connect(open, &QAction::triggered, this, &FileContextMenu::_open);
    connect(openWith, &QAction::triggered, this, &FileContextMenu::_openWith);
    connect(paste, &QAction::triggered, this, &FileContextMenu::_paste);
    connect(copy, &QAction::triggered, this, &FileContextMenu::_copy);
    connect(cut, &QAction::triggered, this, &FileContextMenu::_cut);
    connect(rename, &QAction::triggered, this, &FileContextMenu::_rename);
    connect(properties, &QAction::triggered, this, &FileContextMenu::_properties);
    connect(compress, &QAction::triggered, this, &FileContextMenu::_compress);
    connect(uncompress, &QAction::triggered, this, &FileContextMenu::_uncompress);

    this->addAction(open);
    this->addSeparator();
    this->addAction(cut);
    this->addAction(copy);
    this->addAction(paste);
   // this->addAction(open);
    this->addAction(openWith);
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

    this->addAction(deleteFile);
}

void FileContextMenu::_open()
{
    Act->openCurrentFile();

}
void FileContextMenu::_paste()
{
   Act->paste();
}
void FileContextMenu::_cut()
{
    Act->Cut();
}
void FileContextMenu::_copy()
{
    Act->copy();

}
void FileContextMenu::_rename()
{
    Act->rename();
}

void FileContextMenu::_properties()
{
    Act->fproperties();
}
void FileContextMenu::_delete()
{
    Act->deletef();
}
void FileContextMenu::_compress()
{
    Act->compress();
}
void FileContextMenu::_uncompress()
{
    Act->uncompress();
}
void FileContextMenu::_openWith()
{
    Act->_openWith();
}

void FileContextMenu::_deleteFile()
{
    /*QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    QString currentName = tabWidget::currentWidget()->currentItemName();
    QString selected = tabWidget::currentWidget()->view->currentItem()->text(); //l'unique selection
    qDebug()<<currentPath+selected+" de la part de tonton delete";
    QFile::remove(currentPath+selected);*/
    Act->deleteFile();
}
