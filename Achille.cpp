#include "Achille.h"
#include <QDir>
#include <QVector>
#include <QIcon>
#include <QDesktopServices>
#include <QImageReader>
#include <QPixmapCache>
#include <QPixmap>
#include <QMimeDatabase>
#include <iostream>
#include <QPicture>

#include "tabwidget.h"

Achille::Achille()
{
          setMouseTracking(true);
    searcha = new SearchBar(this);
    searcha->hide();
    connect(searcha->entry,&QLineEdit::returnPressed,this,&Achille::onEnterPressed);
    connect(searcha->close,&QPushButton::clicked,this,&Achille::onCloseClicked);
    view = new DirView(this);
    view->setIconSize(QSize(64,64));
    view->setSortingEnabled(true);


    layout = new QVBoxLayout(this);



   // view->setModel(model);
    view->setViewMode(QListView::IconMode);
     view->setWordWrap(true);
   // view->setRootIndex(model->index(QDir::currentPath()));
     //view->setRootIndex(model->index("C:/"));
     view->setSelectionMode(QAbstractItemView::ExtendedSelection);
     /*selectionmodel = new QItemSelectionModel;
     selectionmodel = view->selectionModel();
     indexElementSelectionne = selectionmodel->currentIndex();
     QModelIndexList lis = selectionmodel->selectedIndexes();
     nbSelectedFiles = lis.size();
     if(indexElementSelectionne.isValid())
     {
         selected = true;
     }*/

       //QVariant elementSelectionne = model->data(indexElementSelectionne,Qt::DisplayRole);
       //QMessageBox::information(this, "Elément sélectionné",filename);

    //layout->addWidget(view);
     layout->addWidget(searcha,0,Qt::AlignTop);
    layout->addWidget(view);

       defaultGridSize = view->gridSize();
       setIconView();
       connect(view,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(onItemDoubleClicked(QListWidgetItem*)));
       connect(view,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onItemClicked(QListWidgetItem*)));
    setLayout(layout);
    //connect(view,SIGNAL(on_folder_clicked()),this,SLOT(folder_double_clicked()));
    //connect(model,&DirView::layoutChanged)
    //iconpro= new QFileIconProvider;

   // AllPictures = picture();

    list_video = {"mp4","avi","3gp","webm","3g2","mpg","flv","mkv","ogg"};
    list_Android_executable = {"apk"};
    list_archive ={"zip","rar","7z","tar","gz","iso","s7z","tar.gz","tgz"};
    list_audio = {"mp3","bpm","amr","pcm","aac","opus"};
    list_document = {"txt","epub","doc","docx"};
    list_word = {"doc","docx"};
    list_exel = {"xls","xlsx","csv"};
    list_powerpoint= {"pptx"};
    list_image = {"jpg","jpeg","png","svg","ico"};



}


Achille::~Achille()
{
    delete view;

    delete layout;

}
void Achille::onEnterPressed() {
    qDebug()<<"ok";
    this->reload();
    this->searchPatterns.clear();
    this->searchPatterns.append(searcha->entry->text());
    this->reload();
/*
    if(!AllItems.isEmpty())//check if AllItems is not empty
    {
        //create a containers for all item in directory and subdirecttories and themselves
        QVector<QListWidgetItem *> items ;

        foreach(auto item,AllItems)
        {
            QFileInfo infos(fsCurrentPath()+item->text());
            if(infos.isFile()){items.push_back(item);}
            else if(infos.isDir()) {
                items.push_back(item);
                QDirIterator it(fsCurrentPath(),QDir::AllEntries,QDirIterator::Subdirectories);
                while(it.hasNext())
                {

                   QListWidgetItem *itema = new QListWidgetItem(it.next());
                   items.push_back(itema);
                }

            }
        }//finish iterrating over
        view->clear();
        if(!items.isEmpty())
        {
        foreach(auto thing,items)
        {
            //search guy !
            if(thing->text().contains(searcha->entry->text(),Qt::CaseSensitive))
            {
                    //add items to view
                  view->addItem(thing->text());
            }
        }
        }
    }*/

}

void Achille::onCloseClicked() {
    this->searchPatterns.clear();
    this->reload();
    searcha->hide();
}

void Achille::setIconView() const {
    view->setViewMode(QListWidget::IconMode);
    view->setFlow(QListWidget::LeftToRight);
    view->setWrapping(true);
    view->setMovement(QListWidget::Snap);
    view->setResizeMode(QListWidget::Adjust);
    view->setGridSize(QSize(80,80));
    view->setWordWrap(true);
}

void Achille::setListView() {
    view->setViewMode(QListView::ListMode);
    view->setFlow(QListWidget::TopToBottom);
    view->setWrapping(true);
    view->setMovement(QListWidget::Snap);
    view->setResizeMode(QListWidget::Adjust);
    view->setGridSize(defaultGridSize);
    view->setWordWrap(true);
}

void Achille::loadDir(const QString& path, bool recordHistory, bool firstLoad) {
    //recordHistory = true;//modiff
    if (recordHistory) {
        //emit dirChanged(path);
        if (!currentPath.isEmpty()) {
            historyList.push_front(currentPath);
            emit historyChanged();
           //  qDebug()<<historyList.at(0);
        }
        emit dirChanged(path);
        // qDebug()<<path;
    }
    currentPath = path;
    view->clear();
    QDir dir(path);

    QStringList folders, files;
   // if (veriff())

#ifdef _WIN32
    //Windows: use the registry
    bool hidden = false;
#else
    bool hidden = false;
    //bool hidden = QVariant(Settings::getSetting("view/hidden","false")).toBool();
#endif
    if (hidden) {
        folders = dir.entryList(searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
        files = dir.entryList(searchPatterns,QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
    } else {
        folders = dir.entryList(searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
        files = dir.entryList(searchPatterns,QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
    }

    QVector<QListWidgetItem *> folderItems, fileItems;

    for (const auto & folder : folders) {
        auto item = new QListWidgetItem(folder);

        item->setData(1,folder);
        item->setWhatsThis(item->text());
        item->setSizeHint(QSize(100,100));
        //item->setIcon(QIcon::fromTheme("folder",QPixmap(":/icons/folder.svg")));
        item->setIcon(QPixmap(QDir::currentPath() +"/Icons/folder.svg"));
        folderItems.push_back(item);
    }



    for (const auto & file : files) {
        auto item = new QListWidgetItem(file);

        item->setWhatsThis(item->text());
        item->setSizeHint(QSize(100,100));
        QString patha = iPath+item->text();
        QFileInfo infos(patha);

        item->setIcon(QPixmap(QDir::currentPath() +"/Icons/file.svg"));
        QString ext = infos.suffix();
        if(veriff(list_image,ext))
        {
               item->setIcon(QPixmap(patha));

            //item->setIcon(QPixmap("QDir::currentPath() +"/Icons/image_file.png"));
        }
#ifdef _WIN32

        if(ext=="pdf")
        {
           item->setIcon(QPixmap(QDir::currentPath() +"/Icons/pdf.png"));
        }
        else if(veriff(list_video,ext))
        {

            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/video.png"));
        }
        else if(veriff(list_audio,ext))
        {
            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/music.png"));
        }
        else if(veriff(list_archive,ext))
        {
           item->setIcon(QPixmap(QDir::currentPath() +"/Icons/zip.png"));
        }
        else if(veriff(list_word,ext))
        {
           item->setIcon(QPixmap(QDir::currentPath() +"/Icons/microsoft_word.png"));
        }
        else if(veriff(list_powerpoint,ext))
        {
            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/micosoft_powerpoint.png"));
        }
        else if(veriff(list_exel,ext))
        {
            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/microsoft_excel.png"));
        }
        else if (ext== "txt")
        {
            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/txt.png"));
        }
        else if(veriff(list_image,ext))
        {
               item->setIcon(QPixmap(patha));

            //item->setIcon(QPixmap(QDir::currentPath() +"/Icons/image_file.png"));
        }
        else if(ext == "apk")
        {
            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/android.png"));
        }
        else if(ext== "gif")
        {
            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/gif.png"));
        }
        else
        {
            item->setIcon(QPixmap(QDir::currentPath() +"/Icons/file.svg"));
        }


#else
        //QIcon defaultIcon = QIcon::fromTheme("text-plain");
        QIcon defaultIcon = QPixmap(":/icons/file.svg");
        QMimeDatabase db;
        if (!QImageReader(fsCurrentPath()+file).format().isEmpty()) {
            QString key = fsCurrentPath()+file;
            QPixmap pm;
            if (!QPixmapCache::find(key,&pm)) {
                pm.load(key);
                QPixmapCache::insert(key,pm);
            }
            if (pm.isNull()) {
                item->setIcon(defaultIcon);
            } else {
                item->setIcon(pm);
            }
        } else {
            QIcon icon = QIcon::fromTheme(db.mimeTypeForFile(fsCurrentPath()+file).iconName(),defaultIcon);
            item->setIcon(icon);
        }
#endif
        fileItems.push_back(item);
    }


    for (auto folderItem : folderItems) {
        auto *label = new QLabel("my label");
        view->setItemWidget(folderItem,label);
        folderItem->setSizeHint(label->sizeHint());
        view->addItem(folderItem);
       // AllItems.push_back(folderItems.at(i));
}

    for (auto fileItem : fileItems) {
        view->addItem(fileItem);
        //AllItems.push_back(fileItems.at(i));
    }

    if (!firstLoad) {
        tabWidget::updateTabName();
    }

   // if (fsCurrentPath()==Trash::folderPath) {
       // trashbar->show();
   // } else {
        //trashbar->hide();
    //}

}

void Achille::loadDir(const QString& path, bool recordHistory) {
    loadDir(path,recordHistory,false);
}

void Achille::loadDir(const QString& path) {
    loadDir(path,true);
}

void Achille::loadDir() {
    loadDir(QDir::homePath());
}

QStringList Achille::history() {
    return historyList;
}

void Achille::reload() {
    //Get all currently selected items so we can re-select them
    QList<QListWidgetItem *> items = view->selectedItems();
    QStringList oldNames;
    for (auto item : items) {
        oldNames.push_back(item->text());
    }

    //Get all items currently in the view
    QStringList currentItems;
    for (int i = 0; i<view->count(); i++) {
        QListWidgetItem *item = view->item(i);
        currentItems.push_back(item->text());
    }

    //Load items in the current directory
    bool hidden = false;
#ifdef _WIN32
    //TODO: Use the registry
#else
    //hidden = QVariant(Settings::getSetting("view/hidden","false")).toBool();
#endif
    QStringList dirItems;
    QDir dir(fsCurrentPath());
    if (hidden) {
        dirItems = dir.entryList(QDir::AllEntries | QDir::NoDotAndDotDot);
    } else {
        dirItems = dir.entryList(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    }

    //Check to see if there are any items in the directory stringlist that are not
    //in the current view list
    bool found = false;
    for (const auto & dirItem : dirItems) {
        if (!currentItems.contains(dirItem)) {
            found = true;
            break;
        }
    }
    if (!found) {
        for (const auto & currentItem : currentItems) {
            if (!dirItems.contains(currentItem)) {
                found = true;
                break;
            }
        }
    }

    //If found, reload
    if (found) {
        loadDir(currentPath,false);

        for (int i = 0; i<view->count(); i++) {
            QListWidgetItem *item = view->item(i);
            for (const auto & oldName : oldNames) {
                if (item->text()==oldName) {
                    item->setSelected(true);
                }
            }
        }
    }
}

QString Achille::fsCurrentPath() const {
    QString path = currentPath;
    if (!path.endsWith("/")) {
        path+="/";
    }
    return path;
}

QString Achille::currentDirName() const {
    QDir dir(currentPath);
    QString name = dir.dirName();
    if (name=="") {
        name = "/";
    }
    return name;
}

void Achille::startRefresh() {
    thread = new FileSystemWatcher(this);
    thread->start(1000);
}

void Achille::stopRefresh() {
    thread->stop();
}

QString Achille::currentItemName() {
    return currentItemTxt;
}

QStringList Achille::currentItemNames() {
    QStringList list;
    auto selectedItems =view->selectedItems();
    for (int i = 0; i < selectedItems.size(); i++) {
        list.push_back(selectedItems.at(i)->text());
         emit SelectChange(i);
    }
    return list;
}

void Achille::selectAll() {
    view->selectAll();
    AllSelected = true;
    emit selectAllstatus(AllSelected);
}

void Achille::onItemDoubleClicked(QListWidgetItem *item) {
    //tabWidget *tb = new tabWidget;
    //int blo = tb->tabs->currentIndex();

    QString path = currentPath;
    if (!path.endsWith("/")) {
        path+="/";
    }
    path+=item->text();
    QFileInfo file(path);
    if(file.isDir())
        path+='/';
    iPath = path;
   // qDebug()<<path;
    if (file.isDir()) {
        //view->clear();
        loadDir(path);

        //startRefresh();
        //tabWidget *tb = new tabWidget;
        //static QString pathf = currentPath;
       // tb->addNewTab(currentPath);
        emit selectionState(false);
    } else {
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    }
}

void Achille::onItemClicked(QListWidgetItem *item) {
    currentItemTxt = item->text();
    emit selectionState(true);
}
/*bool Achille::eventFilter(QObject *obj,QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress)
    {

    }
}
*/
//ListWidget clss
//We had to create separate list widget so we could inherit the mouse press event


/*void ListWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button()==Qt::LeftButton) {
        QListWidgetItem *item = this->itemAt(event->x(),event->y());
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
            if (this->selectedItems().size()>1) {
                MultiContextMenu menu(bWidget);
                menu.exec(QCursor::pos());
            } else {
                bWidget->currentItemTxt = item->text();
                QString complete = bWidget->fsCurrentPath()+bWidget->currentItemTxt;
                if (QFileInfo(complete).isDir()) {
                    FolderContextMenu menu(bWidget);
                    menu.exec(QCursor::pos());
                } else {
                    FileContextMenu menu(bWidget);
                    menu.exec(QCursor::pos());
                }
            }
        } else {
            BackgroundContextMenu menu(bWidget);
            menu.exec(QCursor::pos());
        }
    }
    QListWidget::mousePressEvent(event);
}*/

/*void ListWidget::keyPressEvent(QKeyEvent *event) {
    if (event->modifiers()==Qt::ControlModifier) {
        if (event->key()==Qt::Key_S) {
            if (bWidget->searchbar->isVisible()) {
                bWidget->searchbar->hide();
            } else {
                bWidget->searchbar->show();
            }
        }
    }
    QListWidget::keyPressEvent(event);
}*/

//FileSystemWatcher class
//This is class is an extended QTimer.
//Its purpose is to refresh the Achille every second so that files/folders created outside
//the program are included in our view.
FileSystemWatcher::FileSystemWatcher(Achille *widget) {
    bWidget = widget;
    connect(this,&QTimer::timeout,this,&FileSystemWatcher::onRefresh);
}

void FileSystemWatcher::onRefresh() {
    bWidget->reload();
}


bool Achille::veriff(const QList<QString>& liste,const QString& item)
{
    bool  success {false};
    for(auto & i : liste)
   {
     if(item==i)
     {
       success = true;
     }

   }
    return  success;

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
            Achille *A= new Achille;
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




/*QStringList picture()
{
   // QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
     QStringList folders,folderPic;
      //  QDir dir(QDir::homePath());

        QDirIterator it(QDir::homePath(),list_image,QDir::AllDirs,QDirIterator::Subdirectories);
        while(it.hasNext())
        {
             folders<<it.next();

        }
  //  folders = dir.entryList(searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
    for(int i=0;i<folders.size();++i)
    {
        if(containsPict(folders.at(i)))
        {
            folderPic<<folders.at(i);
        }
    }
     qDebug()<<folders.size();
    return folderPic;
}

bool containsPict(QString folderPath)
{



    QDirIterator it(folderPath,list_image,QDir::Files);
    while(it.hasNext())
    {
         QFileInfo infos(it.next());
         QString ext =infos.suffix();
         if(veriff(list_image,ext))
             return true;


    }

    return 0;
}
void DisplayPict()
{
    QVector<QListWidgetItem *> folderItems;
      loadOnlyPictures = true;
     QStringList  picturd = picture();

    for (int i = 0; i<picturd.size(); i++) {
        QListWidgetItem *item = new QListWidgetItem(picturd.at(i));
        //item->setIcon(QIcon::fromTheme("folder",QPixmap(":/icons/folder.svg")));
        item->setIcon(QPixmap("c/Icons/folder.svg"));
        folderItems.push_back(item);
    }
    for (int i = 0; i<folderItems.size(); i++) {
        view->addItem(folderItems.at(i));
    }

}*/
//creating a struct  to detectv usb masse storage
