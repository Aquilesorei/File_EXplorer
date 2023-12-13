#include "DirView.h"
#include "../components/CentralWidget.h"
#include "../menu/folderContextMenu.h"
#include "../menu/FileContextMenu.h"
#include "../menu/BackgroundContextMenu.h"
#include "../menu/MultiContextMenu.h"
DirView::DirView(QWidget *parent):QListWidget(parent)
{
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setDragEnabled(true);
    this->viewport()->setAcceptDrops(true);
    this->setDropIndicatorShown(true);
    this->setDragDropMode(QAbstractItemView::DragDrop);
    this->setSortingEnabled(true);
    this->setWordWrap(true);
    this->setUniformItemSizes(true);
    this->setFlow(QListView::LeftToRight);
    this->setFocusPolicy(Qt::NoFocus);
    this->setContextMenuPolicy(Qt::CustomContextMenu);

    // bWidget = new CentralWidget;

}
DirView::~DirView()
{

}
void DirView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton)
    {
        QString currentPath = tabWidget::currentWidget()->fsCurrentPath();


        if(!indexAt(event->pos()).isValid())
        {
            BackgroundContextMenu menu(bWidget);
            menu.exec(QCursor::pos());


        }
        else{
            QListWidgetItem *item = this->itemAt(event->pos());
            QString er = item->text();
            if(item!= nullptr){
                if (this->selectedItems().size()>1) {
                    MultiContextMenu menu(bWidget);
                    menu.exec(QCursor::pos());
                }
                else{
                    QString complete = currentPath+er;
                    if (QFileInfo(complete).isDir())
                    {
                        FolderContextMenu menu(bWidget);
                        menu.exec(QCursor::pos());
                    }
                    else if(QFileInfo(complete).isFile())
                    {
                        FileContextMenu mengu(bWidget);
                        mengu.exec(QCursor::pos());

                    }}


            }
        }

    }
    else{
        QListWidgetItem *item = this->itemAt(event->pos());

    }
    QListWidget::mousePressEvent(event);


}
//else if (event->button()==Qt::LeftButton) {}
/*info = mo->fileInfo(this->currentIndex());
if(info.isFile()){
QString path = mo->filePath(this->currentIndex());
QDesktopServices::openUrl(QUrl::fromLocalFile(path));*/


// QListView::mousePressEvent(event);
//qDebug()<<path;
//  }
// else
// {
/*QString pathg = mo->filePath(this->currentIndex())+"/";
CentralWidget *A= new CentralWidget;
A->model->setRootPath(pathg);
A->view->setRootIndex(A->model->index(pathg));
//A->model->ref
//QDir::setCurrent(pathg);
// qDebug()<<pathg;
emit on_folder_clicked();
QListView::mousePressEvent(event);


}


}





void DirView::mousePressEvent(QMouseEvent *event) {
if (event->button()==Qt::LeftButton) {
QListWidgetItem *item = this->itemAt(event->pos());
if (item==nullptr) {
QList<QListWidgetItem *> selectedItems = this->selectedItems();
for (int i = 0; i<selectedItems.size(); i++) {
    selectedItems.at(i)->setSelected(false);
}
emit bWidget->selectionState(false);
}
} else if (event->button()==Qt::RightButton) {
QListWidgetItem *item = this->itemAt(event->x(),event->y());
if (item!=nullptr) {
qDebug()<<"ok";

   // bWidget->currentItemTxt = item->text();
    QString er = item->text();
    QString complete = bWidget->fsCurrentPath()+er;
    if (QFileInfo(complete).isDir()) {
        FolderContextMenu menu(bWidget);
        menu.exec(QCursor::pos());

}
}
QListWidget::mousePressEvent(event);
}*/

void DirView::keyPressEvent(QKeyEvent *event) {
    if (event->modifiers()==Qt::ControlModifier) {
        if (event->key()==Qt::Key_S) {
            if (tabWidget::currentWidget()->searcha->isVisible()) {
                tabWidget::currentWidget()->searcha->hide();
            } else {
                tabWidget::currentWidget()->searcha->show();
            }
        }
        else if(event->key()==Qt::Key_Delete)
        {
            Actions *act = new Actions;
            act->deleteFile();
        }
    }
    QListWidget::keyPressEvent(event);
}


