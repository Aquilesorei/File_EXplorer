#include "MainWindow.h"
#include<QApplication>
#include <string>
#include <QDir>
#include <QIcon>
#include <QPixmap>

MainWindow::MainWindow(): window(new QMainWindow)
{

   index = 0;
    this->setWindowTitle("Myriad File Explorer");
    this->setWindowIcon(QIcon(QDir::currentPath() +"/Icons/Myriad.png"));
    this->setIconSize(QSize(50,50));
    this->setBaseSize(QSize(100,100));
    this->setAnimated(true);
    A = new CentralWidget;
    w = new Welcome;
    tab = new tabWidget;

    //board = QApplication::clipboard();

    navig = new QToolBar;
    navig->setMovable(false);
    navig->setContextMenuPolicy(Qt::PreventContextMenu);
    navig = addToolBar("Navigate");
    navig->setOrientation(Qt::Horizontal);
    if(A->selected)
    {
         QVariant T(A->nbSelectedFiles);
         QString u = T.toString();
        //int a = A->nbSelectedFiles;
       // QString b = a.str();
        statusBar()->showMessage(u+" Files selected, Total ");// à revoir
}
    //setting up... making all ready ...

    setAcceptDrops(true);
   danse = new QMenuBar(this);
    /*label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("File Explorer");
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);*/
    Menu = new  QMenu;
    Menu = danse->addMenu("&Menu");
  //  Menu->setIcon(QIcon("/home/aquiles/Desktop/project/Projects/QtCreator/File_EXplorer/Icons/Menu.png"));
    Menu->setTitle("Menu");


    Menu->setToolTip("Open application menu");
    Menu->setCursor(Qt::PointingHandCursor);
    //Menu->


    //onglets =new QTabWidget;

    //MenuOption; {"id = df";};
    //danse->setStyleSheet(" Spacing :500" );


    this->setMenuBar(danse);
    //ba = new Dialog;
   // ba->p = this;


   // setCentralWidget(window);
    /*Banane = new QToolBar;
    QLabel *Titre = new QLabel;
    Titre->setText("Myriad File Explorer");
    Titre->setFont(QFont("Calibri", 20));
    Banane->addWidget(Titre);
    Banane = addToolBar("Titre");*/
    /*view = new QToolButton;
    New = new QToolButton;
    sort = new QToolButton;*/

    toolbarFichiers = new toolbarfichier;
    this->addToolBar(toolbarFichiers);
  //  toolbarFichiers = addToolBar("files");
    //toolbarFichiers->setFixedSize(QSize(1000,50));

    ActionAnalyse = new QAction("Analyse",this);
    ActionAnalyse->setFont(QFont("Calibri", 20));
    ActionAnalyse->setToolTip("Analyse");
    ActionRefresh = new QAction("Refresh",this);
    ActionRefresh->setFont(QFont("Calibri", 20));
    ActionRefresh->setToolTip("Refresh");
    ActionSetting = new QAction("Settings",this);
    ActionSetting->setFont(QFont("Calibri", 20));
    ActionSetting->setToolTip("Settings");
    MenuOption = new QMenu(this);
    MenuOption = danse->addMenu("&Options");
    //danse->setCornerWidget(MenuOption,Qt::TopRightCorner);
  //  MenuOption->setIcon(QIcon(QDir::currentPath() +"/Icons/Options.jpg"));
    MenuOption->setToolTip("Options");
    MenuOption->addAction(ActionSetting);
    MenuOption->addAction(ActionAnalyse);
    MenuOption->addAction(ActionRefresh);
    //layout et bouttons

    home = new QPushButton("Home");
    home->setToolTip("Move to the home directoy");
    home->setFont(QFont("Calibri", 20));
    home->setIcon(QIcon(QDir::currentPath() +"/Icons/home.png"));





    //les icones

    ActionAnalyse->setIcon(QIcon(QDir::currentPath() +"/Icons/Analyse.png"));
    ActionAnalyse->setToolTip("Analyse and help you to delte useless files");
    ActionRefresh->setIcon(QIcon(QDir::currentPath() +"/Icons/Refresh.png"));
    ActionRefresh->setToolTip("Refresh");
    ActionSetting->setIcon(QIcon(QDir::currentPath() +"/Icons/setting.png"));

    //connect(ActionCopy, &QAction::triggered, this, &MainWindow::FindReplace);
    //buton = new QToolButton;
    //buton->setIcon(QIcon(":/Icons/Find.svg"));
   /* toolbarFichiers->addWidget(MenuNew);
    toolbarFichiers->addWidget(MenuView);
    toolbarFichiers->addWidget(MenuSort);*/



  /* toolbarFichiers->setIconSize(QSize(20,20));
   navig->setIconSize(QSize(20,20));*/
   /* connect(ActionCopy, &QAction::triggered, this,&MainWindow::_copy);
    connect(ActionCut, &QAction::triggered, this,&MainWindow::_cut);
   connect(ActionPaste, &QAction::triggered, this,&MainWindow::_paste);*/



    ///toolbarFichiers->setIconSize(QSize(50,50));
   // menuBar()->setFixedSize(50,50);
  //  MenuSort->addAction(ActionSort);
   // MenuView->addAction(Actionview);
   // MenuSort->addAction(ActionNouveau);


    label = new QLabel;
    page1= new QWidget;
    page2= new QWidget;
    page3= new QWidget;
    Tab = new  QTabWidget(this);
    bayout = new QVBoxLayout;
    bayout1 = new QVBoxLayout;
    bayout2 = new QVBoxLayout;
    Bar =new QProgressBar;
    Bar->reset();
    auto *label1 = new QLabel;

    Storage = QStorageInfo::root();
    QString texte =Storage.name()+"\n"+Storage.device();
    QString text1 = "<Strong>Occupied Space :</Strong>";
    label1->setText(text1);
    label->setText(texte);
    label1->setFont(QFont("Calibri", 20));
    auto Total = Storage.bytesTotal()/1000000;
    auto libre = Storage.bytesAvailable()/1000000;
    occupe = Total-libre;
    Frac = occupe*100/Total;
    Bar->setValue(Frac);

    bayout=new QVBoxLayout;
    bayout1=new QVBoxLayout;
    bayout2=new QVBoxLayout;
    bayout->addWidget(home);
    bayout->addWidget(label1);
    bayout->addWidget(label);
    bayout->addWidget(Bar);
    bayout->addWidget(w->Recycles);
    bayout->addWidget(w->Download);
    bayout->addWidget(w->Secret);
    bayout2->addWidget(w->NewFile);
    page1->setLayout(bayout);
    page2->setLayout(bayout1);
    page3->setLayout(bayout2);
    Tab->addTab(page1,QIcon(QDir::currentPath() +"/Icons/Storages.png"),"Storages");
    Tab->addTab(page2,QIcon(QDir::currentPath() +"/Icons/etoile.png"),"Favourites");
    Tab->addTab(page3,QIcon(QDir::currentPath() +"/Icons/recent.svg"),"New Files");
    Tab->setUsesScrollButtons(true);
    auto mani =new QVBoxLayout;
    mani->addWidget(Tab);
    Menu->setLayout(mani);
    Menu->setFixedSize(QSize(300,400));

    /*splitter = new QSplitter;
    vue = new QListView(splitter);
    filemodel= new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot |QDir::Files);
    filemodel->setRootPath(QDir::currentPath());
    filemodel->setReadOnly(false);

    vue->setModel(filemodel);
    vue->setRootIndex(filemodel->index(QDir::currentPath()));
    Tree = new QTreeView(splitter);
    modele = new QFileSystemModel(this);
    modele->setFilter(QDir::NoDotAndDotDot |QDir::AllDirs);
    modele->setRootPath(QDir::currentPath());
    modele->setReadOnly(false);

    Tree->setModel(modele);
    Tree->setRootIndex(modele->index(QDir::currentPath()));
    tayout = new QVBoxLayout;
    tayout->addWidget(Tree);
    tayout->addWidget(vue);
    tayout->addWidget(splitter);
    widi->setLayout(tayout);*/


     this->setCentralWidget(w);

    avancer =new QToolButton;
     reculer=new QToolButton;
    refresh=new QToolButton;
    Home=new QToolButton;
    avancer->setIcon(QPixmap(QDir::currentPath() +"/Icons/next.png"));
    reculer->setIcon(QPixmap(QDir::currentPath() +"/Icons/previous.png"));
    refresh->setIcon(QPixmap(QDir::currentPath() +"/Icons/refresh.png"));
    home->setIcon(QPixmap(QDir::currentPath() +"/Icons/home.png"));

    avancer->setEnabled(false);
    reculer->setEnabled(false);

    connect(reculer,&QToolButton::clicked,this,&MainWindow::_reculer);
    connect(avancer,&QToolButton::clicked,this,&MainWindow::_avancer);
    connect(refresh,&QToolButton::clicked,this,&MainWindow::onRefreshClicked);
    connect(home,&QToolButton::clicked,this,&MainWindow::onHomeClicked);


    navig->addWidget(reculer);
    navig->addWidget(avancer);
    navig->addWidget(refresh);
    navig->addWidget(home);
    setNavBar();


  left = new leftWidget;
   connecto();
    //QObject::connect(vue,SIGNAL(clicked()),this,SLOT(on_listView_clicked()));

      connect(toolbarFichiers->ActionAll, &QAction::triggered, this,&MainWindow::selecta);
      connect(A, &CentralWidget::selectAllstatus, this, &MainWindow::handleSelect);
      connect(this, &MainWindow::centralChanged, this, &MainWindow::setDock);
      connect(this, &MainWindow::centralChanged, this, &MainWindow::configToolbar);
      configToolbar(central::welcome);
}
void MainWindow::onListViewClicked()

{
    if(centralWidget()== w){
    connect(home,SIGNAL(clicked()),this,SLOT(onHomeClicked()));
     delete(w);
    // A = new CentralWidget;
     tab = new tabWidget;
    // A->loadDir();

     this->setCentralWidget(tab);
     emit centralChanged(central::tab);
    }

}

void MainWindow::onDownloadsClicked()
{ if(centralWidget()== w)
 {
         connect(home,SIGNAL(clicked()),this,SLOT(onHomeClicked()));
         connect(w->BoutonMAinStorage,SIGNAL(clicked()),this,SLOT(onListViewClicked()));
         connect(w->Downloads,SIGNAL(clicked()),this,SLOT(onDownloadsClicked()));
         connect(w->images, SIGNAL(clicked()), this,SLOT(onImageClicked()));
         connect(w->Audio, SIGNAL(clicked()), this,SLOT(onMusicClicked()));
         connect(w->Desktop, SIGNAL(clicked()), this,SLOT(onDesktopClicked()));
         connect(w->Videos, SIGNAL(clicked()), this,SLOT(onVideosClicked()));
         connect(w->Documents, SIGNAL(clicked()), this,SLOT(onDocumentClicked()));

         delete(w);
        // A = new CentralWidget;
         tab = new tabWidget;
        // A->loadDir();

         this->setCentralWidget(tab);
        tabWidget::addNewTab("/home/aquiles/Downloads/");
         emit centralChanged(central::tab);

}
}
void MainWindow::onImageClicked()
{
      tab = new tabWidget;

      tabWidget::addNewTab("/home/aquiles/Pictures/");
      this->setCentralWidget(tab);
      emit centralChanged(central::tab);

}
void MainWindow::onMusicClicked()
{
    tab = new tabWidget;

    tabWidget::addNewTab("/home/aquiles/Music/");
    this->setCentralWidget(tab);
    emit centralChanged(central::tab);

}
void MainWindow::onVideosClicked()
{
    tab = new tabWidget;

    tabWidget::addNewTab("/home/aquiles/Videos/");
    this->setCentralWidget(tab);
    emit centralChanged(central::tab);

}
void MainWindow::onDocumentClicked()
{
    tab = new tabWidget;

    tabWidget::addNewTab("/home/aquiles/Documents/");
    this->setCentralWidget(tab);
    emit centralChanged(central::tab);
}
void MainWindow::onDesktopClicked()
{
    tab = new tabWidget;

    tabWidget::addNewTab("/home/aquiles/Desktop/");
    this->setCentralWidget(tab);
    emit centralChanged(central::tab);
}

void MainWindow::setDock(Centrals flags)
{

   if(flags==0x0000)
   {

       this->addDockWidget(Qt::LeftDockWidgetArea,left);
       left->show();
   }
   else
   {
     left->hide();
     this->removeDockWidget(left);

   }
}

void MainWindow::status(int nb)
{



    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    QString currentName = tabWidget::currentWidget()->currentItemName();
    QString selected = tabWidget::currentWidget()->view->currentItem()->text();//l'unique selection
    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();//plusieurs
    QStringList list,folders,files;
    int nbFiles =0;
    QString path = tabWidget::currentWidget()->currentPath;
    if(selectedItems.size()>1)
    {
        for(const auto & selectedItem : selectedItems)
        {
           list.push_back(path+selectedItem);
        }
        for(const auto & i : list)
        {
         QFileInfo infos(i);
         if(infos.isFile())
             nbFiles++;
         else{

        QString path = i;

        QDir dir(path);



    #ifdef _WIN32
        //Windows: use the registry
        bool hidden = false;
    #else
        bool hidden = false;
        //bool hidden = QVariant(Settings::getSetting("view/hidden","false")).toBool();
    #endif
        if (hidden) {
            folders += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
            files += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
        } else {
            folders += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
            files += dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
        }

}
        }
        QVariant Y(folders.size());
        QVariant Z(files.size());
        QVariant fich(Z.toInt()+nbFiles);
        QVariant T(nb);

        switch(Y.toInt())
        {
        case 0:
             statusBar()->showMessage(T.toString()+" Files selected");
             break;

         default:
             statusBar()->showMessage("Folder : "+Y.toString()+" Files : "+fich.toString());
             break;

        }
}
    else
    {
        QFileInfo infos(currentPath+selected);
        if(infos.isFile()){
            QVariant one(1);
            statusBar()->showMessage(one.toString()+" File selected");
        }
        else if(infos.isDir()){
            QString path = currentPath+selected;

            QDir dir(path);


        #ifdef _WIN32
            //Windows: use the registry
            bool hidden = false;
        #else
            bool hidden = false;
            //bool hidden = QVariant(Settings::getSetting("view/hidden","false")).toBool();
        #endif
            if (hidden) {
                folders = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
                files = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::IgnoreCase);
            } else {
                folders = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
                files = dir.entryList(tabWidget::currentWidget()->searchPatterns,QDir::Files | QDir::NoDotAndDotDot, QDir::Name | QDir::IgnoreCase);
            }
            QVariant Y(folders.size());
            QVariant Z(files.size());
             QVariant fich(Z.toInt()+nbFiles);
             statusBar()->showMessage("Folders : "+Y.toString()+" Files : "+fich.toString());


        }


    }
}

void MainWindow::configToolbar(Centrals flags)
{
    if(flags==0x0001)
    {
       toolbarFichiers->hide();
       navig->hide();
    }
    else
    {
        toolbarFichiers->show();
        navig->show();
    }
}


/*NavBar::~NavBar() {
    delete goBack;
    delete goUp;
    delete refresh;
    delete home;
}*/

void MainWindow::setNavBar() {

    if (tabWidget::currentWidget()->fsCurrentPath()=="/") {
        reculer->setEnabled(false);
    } else {
        reculer->setEnabled(true);
    }
    if (tabWidget::currentWidget()->history().isEmpty()) {
        avancer->setEnabled(false);
    } else {
        avancer->setEnabled(true);
    }
    connect(A, &CentralWidget::dirChanged, this, &MainWindow::onDirChanged);
    connect(A, &CentralWidget::historyChanged, this, &MainWindow::onHistoryChanged);
}

void MainWindow::connecto()
{
    connect(home,SIGNAL(clicked()),this,SLOT(onHomeClicked()));
    connect(w->BoutonMAinStorage,SIGNAL(clicked()),this,SLOT(onListViewClicked()));
    connect(w->Downloads,SIGNAL(clicked()),this,SLOT(onDownloadsClicked()));
    connect(w->images, SIGNAL(clicked()), this,SLOT(onImageClicked()));
    connect(w->Audio, SIGNAL(clicked()), this,SLOT(onMusicClicked()));
    connect(w->Desktop, SIGNAL(clicked()), this,SLOT(onDesktopClicked()));
    connect(w->Videos, SIGNAL(clicked()), this,SLOT(onVideosClicked()));
    connect(w->Documents, SIGNAL(clicked()), this,SLOT(onDocumentClicked()));

}

void MainWindow::_reculer() {
    if (tabWidget::currentWidget()==nullptr) {
        return;
    }
    QString currentPath = tabWidget::currentWidget()->fsCurrentPath();
    QDir dir(currentPath);
    dir.cdUp();
    QString newPath = dir.path();
    tabWidget::currentWidget()->loadDir(newPath);
}

void MainWindow:: _avancer(){

    QString path = tabWidget::currentWidget()->history().at(index);
    tabWidget::currentWidget()->loadDir(path);
    ++index;
}

void MainWindow::onRefreshClicked() {
    tabWidget::currentWidget()->reload();
}

void MainWindow::onHomeClicked() {

    if(centralWidget() == tab)
        {
         if(tabWidget::allWidgets().size()>1)
        {
             foreach(auto widis,tabWidget::allWidgets())
             {
                 widis->stopRefresh();
             }

         }

         else{tabWidget::currentWidget()->stopRefresh();}
           tab->deleteLater();
            w = new Welcome;
            w->showMaximized();
            this->setCentralWidget(w);
            emit centralChanged(central::welcome);
            //connect(w->BoutonMAinStorage,SIGNAL(clicked()),this,SLOT(onListViewClicked()));
            connecto();

}
}
void MainWindow::onDirChanged(const QString& path) {
       qDebug()<<"Directory changed";
    if (path=="/") {
        reculer->setEnabled(false);
    } else {
        reculer->setEnabled(true);
    }
}

void MainWindow::onHistoryChanged() {
     qDebug()<<"history changed";
    if (tabWidget::currentWidget()->history().isEmpty()) {
        avancer->setEnabled(false);
    } else {
        avancer->setEnabled(true);
    }
}

void MainWindow::selecta()
{

  if(tabWidget::currentWidget()->AllSelected)
  {
      tabWidget::currentWidget()->view->clearSelection();
      tabWidget::currentWidget()->AllSelected = false;
  }
  else
  {
       tabWidget::currentWidget()->selectAll();
      // toolbarFichiers->ActionAll->setStatusTip("All items selected");
  }
}
void MainWindow::handleSelect()
{

    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();//plusieurs
   if(selectedItems.length()>=1)
       toolbarFichiers->ActionAll->setEnabled(true);
   else
      toolbarFichiers->ActionAll->setEnabled(false);
}

/*void MainWindow::_cut()
{
    board->clear();


 // QList<QListWidgetItem *> selectedItems = tabWidget::currentWidget()->currentItemNames();//la liste est vide
   QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();

  const QString path = tabWidget::currentWidget()->currentPath;


  if(selectedItems.size()>1){
      QString ajout;
      for(int i= 0;i<selectedItems.size();++i)
      {
        // list.push_back(path+selectedItems.at(i));
          ajout += path+selectedItems.at(i)+"\n";



      }
      ajout += "move";
     board->setText(ajout);
  }
  else if(selectedItems.size()==1)
  {
      elem = currentPath+selected;
      board->setText(elem);
      unique = true;

  }
  //move = true;
}

void MainWindow::_paste()
{
   //BackgroundContextMenu *ba = new BackgroundContextMenu(A);
  // ba->onpaste();
}

void MainWindow::_copy()
{
    QStringList selectedItems = tabWidget::currentWidget()->currentItemNames();

    QString path = tabWidget::currentWidget()->currentPath;



  if(selectedItems.size()>1){
      QString ajout;
      for(int i= 0;i<selectedItems.size();++i)
      {
        // list.push_back(path+selectedItems.at(i));
          ajout += path+selectedItems.at(i)+"\n";

         //board->setText(list.at(i));

      }

      board->setText(ajout);

       }else if(selectedItems.size()==1)
  {
      elem = currentPath+selected;

      board->setText(elem);
      unique = true;

  }
 // move = false;
}
*/
