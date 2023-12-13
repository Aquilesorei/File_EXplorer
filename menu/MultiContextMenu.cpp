#include <QPixmap>

#include "MultiContextMenu.h"

#include "../components/Actions.h"

#include "../components/tabwidget.h"

MultiContextMenu::MultiContextMenu(CentralWidget *b) {
    bWidget = b;

    Act = new Actions;
    compress = new QAction(QPixmap(":/icons/edit-cut.svg"), "Compress", this);
    cut = new QAction(QPixmap(":/icons/edit-cut.svg"), "Cut", this);
    copy = new QAction(QPixmap(":/icons/edit-copy.svg"), "Copy", this);
    trash = new QAction(QPixmap(":/icons/user-trash.svg"), "Move to Trash", this);
    restore = new QAction(QPixmap(":/icons/view-refresh.svg"), "Restore", this);
    deleteAll = new QAction(QPixmap(":/icons/edit-delete.svg"), "Delete", this);
    openTerminal = new QAction(QPixmap(":/icons/tab-new.svg"), "Open in windows Terminal", this);

    properties = new QAction(QPixmap(":/icons/tab-new.svg"), "Properties", this);




     connect(compress, &QAction::triggered, this, &MultiContextMenu::_compress);
    connect(cut, &QAction::triggered, this, &MultiContextMenu::onCutClicked);
    connect(copy, &QAction::triggered, this, &MultiContextMenu::onCopyClicked);
    connect(deleteAll, &QAction::triggered, this, &MultiContextMenu::onDeleteAllClicked);
    connect(openTerminal, &QAction::triggered, this, &MultiContextMenu::onDeleteAllClicked);
    connect(properties, &QAction::triggered, this, &MultiContextMenu::proper);






    this->addAction(cut);
    this->addAction(copy);
    this->addAction(compress);
    this->addAction(properties);
    this->addAction(openTerminal);
    this->addSeparator();





  /*  if (tabWidget::currentWidget()->fsCurrentPath()==Trash::folderPath) {
        this->addAction(restore);
    } else {
        this->addAction(trash);
    }*/

    this->addAction(deleteAll);
}

MultiContextMenu::~MultiContextMenu() {
    delete cut;
    delete copy;
    delete trash;
    delete restore;
    delete deleteAll;
}

void MultiContextMenu::onCutClicked() {
    Act->Cut();

}

void MultiContextMenu::onCopyClicked() {
    Act->copy();

}



void MultiContextMenu::onDeleteAllClicked() {
    Act->deleteFile();

}
void MultiContextMenu::openT()
{
    QString path = tabWidget::currentWidget()->fsCurrentPath();
    QString selectedItems = tabWidget::currentWidget()->view->currentItem()->text();

        QProcess proc;
        proc.setWorkingDirectory(path+selectedItems);
        proc.setProgram("cmd");
        proc.startDetached();

}
void MultiContextMenu::proper()
{
    Act->mproperties();

}

void MultiContextMenu::_compress()
{
   Act->compress();
}
