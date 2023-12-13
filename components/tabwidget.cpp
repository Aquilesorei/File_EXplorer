 #include <QDir>
 #include <QSplitter>
#include "tabwidget.h"
#include <QHBoxLayout>
//#include "NavLayout.h"
#include <QListWidgetItem>


QTabWidget *tabWidget::tabs;
//NavBar *TabWidget::navigationBar;

tabWidget::tabWidget(QWidget *parent):QWidget(parent)
    ,layout(new QVBoxLayout)
{
    //navigationBar = navbar;

    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    tabs = new QTabWidget;
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
    tabs->setTabBarAutoHide(true);
    layout->addWidget(tabs);

    connect(tabs,&QTabWidget::currentChanged,this,&tabWidget::onTabsChanged);
    connect(tabs,SIGNAL(tabCloseRequested(int)),this,SLOT(onTabClosed(int)));

    // libdisks
/*#ifndef NO_UDISKS
    disks = new Disks(this);
    connect(disks, SIGNAL(updatedDevices()), this, SLOT(populateMedia()));
    connect(disks, SIGNAL(mountpointChanged(QString,QString)), this, SLOT(handleMediaMountpointChanged(QString,QString)));
    connect(disks, SIGNAL(foundNewDevice(QString)), this, SLOT(handleMediaAdded(QString)));
    connect(disks, SIGNAL(removedDevice(QString)), this, SLOT(handleMediaRemoved(QString)));
    connect(disks, SIGNAL(mediaChanged(QString,bool)), this, SLOT(handleMediaChanged(QString,bool)));
    connect(disks, SIGNAL(deviceErrorMessage(QString,QString)), this, SLOT(handleMediaError(QString,QString)));
#endif*/

    addNewTab();
}

tabWidget::~tabWidget() {
    delete tabs;
    delete layout;
}

void tabWidget::addNewTab(const QString& path) {
    int count = tabs->count();

    auto *b = new CentralWidget;

    b->loadDir(path,true,true);
    QString name = b->currentDirName();

    if (name=="") {
        name+="/";
    }
    tabs->addTab(b,name);
    tabs->setCurrentIndex(count);
    b->startRefresh();
    //navigationBar->setBrowserWidget(b);
}

void tabWidget::addNewTab() {
    addNewTab(QDir::homePath());
}

 void tabWidget::closeCurrentTab() {
    int index = tabs->currentIndex();
    if (tabs->count()==1) {
        addNewTab();
    }
    auto *b = dynamic_cast<CentralWidget *>(tabs->widget(index));
    b->stopRefresh();
    delete b;
}

CentralWidget *tabWidget::currentWidget() {
    auto *w = dynamic_cast<CentralWidget *>(tabs->currentWidget());
    return w;
}

void tabWidget::updateTabName() {
    CentralWidget *w = currentWidget();
    tabs->setTabText(tabs->currentIndex(),w->currentDirName());
}

QVector<CentralWidget *> tabWidget::allWidgets() {
    QVector<CentralWidget *> widgets;
    for (int i = 0; i<tabs->count(); i++) {
        auto current = dynamic_cast<CentralWidget *>(tabs->widget(i));
        widgets.push_back(current);
    }
    return widgets;
}

void tabWidget::onTabsChanged() {
    //navigationBar->setBrowserWidget(currentWidget());
   // MainWindow::addrTxt->setBrowserWidget(currentWidget());
    //MainWindow::addrButtons->setBrowserWidget(currentWidget());
}

void tabWidget::onTabClosed(int index) {
    auto b = dynamic_cast<CentralWidget *>(tabs->widget(index));
    b->stopRefresh();
    delete b;
}


/* @brief media support
*/
/*#ifndef NO_UDISKS
void tabWidget::populateMedia()
{
   QMapIterator<QString, Device*> device(disks->devices);
   while (device.hasNext()) {
       device.next();
       if (mediaBookmarkExists(device.value()->path)>-1) { continue; }
       if ((device.value()->isOptical && !device.value()->hasMedia)
#ifndef __FreeBSD__
               || (!device.value()->isOptical && !device.value()->isRemovable)
#endif
               || (!device.value()->isOptical && !device.value()->hasPartition)) { continue; }
       modelBookmarks->addBookmark(QString("%1 (%2)").arg(device.value()->name).arg(device.value()->dev),
                                   device.value()->mountpoint,
                                   "",
                                   device.value()->isOptical?"drive-optical":"drive-removable-media",
                                   device.value()->path,
                                   true,
                                   false);
   }
}

void tabWidget::handleMediaMountpointChanged(QString path, QString mountpoint)
{
   Q_UNUSED(mountpoint)
   if (path.isEmpty()) { return; }
   for (int i = 0; i < modelBookmarks->rowCount(); i++) {
       if (modelBookmarks->item(i)->data(MEDIA_MODEL).toBool() && modelBookmarks->item(i)->data(MEDIA_PATH).toString() == path) {
           modelBookmarks->item(i)->setData(disks->devices[path]->mountpoint, BOOKMARK_PATH);
       }
   }
}

int tabWidget::mediaBookmarkExists(QString path)
{
   if (path.isEmpty()) { return -1; }
   for (int i = 0; i < modelBookmarks->rowCount(); ++i) {
       if (modelBookmarks->item(i)->data(MEDIA_MODEL).toBool()
               && modelBookmarks->item(i)->data(MEDIA_PATH).toString() == path) { return i; }
   }
   return -1;
}

void tabWidget::handleMediaAdded(QString path)
{
   Q_UNUSED(path)
   populateMedia();
}

void tabWidget::handleMediaRemoved(QString path)
{
   int bookmark = mediaBookmarkExists(path);
   if (bookmark>-1) { modelBookmarks->removeRow(bookmark); }
}

void tabWidget::handleMediaChanged(QString path, bool present)
{
   //qDebug() << "changed" << path << present;
   if (path.isEmpty()) { return; }
   if (disks->devices[path]->isOptical && !present && mediaBookmarkExists(path)>-1) {
       handleMediaRemoved(path);
   } else if (disks->devices[path]->isOptical && present && mediaBookmarkExists(path)==-1) {
       handleMediaAdded(path);
   }
}

void tabWidget::handleMediaUnmount()
{
   //qDebug() << "handle media unmount";
   QStandardItem *item = modelBookmarks->itemFromIndex(bookmarksList->currentIndex());
   if (item == Q_NULLPTR) { return; }
   QString path = item->data(MEDIA_PATH).toString();
   if (path.isEmpty()) { return; }
   disks->devices[path]->unmount();
}

void tabWidget::handleMediaEject()
{
   //qDebug() << "handle media eject";
   QStandardItem *item = modelBookmarks->itemFromIndex(bookmarksList->currentIndex());
   if (item == Q_NULLPTR) { return; }
   QString path = item->data(MEDIA_PATH).toString();
   if (path.isEmpty()) { return; }
   disks->devices[path]->eject();
}

void tabWidget::handleMediaError(QString path, QString error)
{
   QMessageBox::warning(this, path, error);
}
#endif*/

