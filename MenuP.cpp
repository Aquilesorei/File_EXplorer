#include "MenuP.h"
#include "Actions.h"
MenuP::MenuP()
{
    //W = new Welcome;
    Menu = new  QMenu;
    Menu = this->addMenu("&Menu");
    Menu->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Menu.png"));
    Menu->setTitle("Menu");
    Menu->setToolTip("Open application menu");
    Menu->setCursor(Qt::PointingHandCursor);

    ActionAnalyse = new QAction("Analyse",this);
    ActionAnalyse->setFont(QFont("Calibri", 20));
    ActionAnalyse->setToolTip("Analyse");
    ActionRefresh = new QAction("Refresh",this);
    ActionRefresh->setFont(QFont("Calibri", 20));
    ActionRefresh->setToolTip("Refresh");
    ActionSetting = new QAction("Settings",this);
    ActionSetting->setFont(QFont("Calibri", 20));
    ActionSetting->setToolTip("Settings");

    //layout et bouttons

    home = new QPushButton("Home");
    home->setToolTip("Move to the home directoy");
    home->setFont(QFont("Calibri", 20));
    home->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/home.png"));

    MenuOption = new QMenu;
    MenuOption = this->addMenu("&Options");
    ActionAnalyse->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Analyse.png"));
    ActionAnalyse->setToolTip("Analyse and help you to delte useless files");
    ActionRefresh->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Refresh.png"));
    ActionRefresh->setToolTip("Refresh");
    ActionSetting->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/setting.png"));
    //danse->setCornerWidget(MenuOption,Qt::TopRightCorner);
    MenuOption->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Options.jpg"));
    MenuOption->setToolTip("Options");
    MenuOption->addAction(ActionSetting);
    MenuOption->addAction(ActionAnalyse);
    MenuOption->addAction(ActionRefresh);


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
    QLabel *label1 = new QLabel;

    Storage = QStorageInfo::root();
    QString texte =Storage.name()+"\n"+Storage.device();
    QString text1 = "<Strong>Occupied Space :</Strong>";
    label1->setText(text1);
    label->setText(texte);
    label1->setFont(QFont("Calibri", 20));
    float Total = Storage.bytesTotal()/1000000;
    float libre = Storage.bytesAvailable()/1000000;
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
    bayout->addWidget(Recycles);
    bayout->addWidget(Download);
    bayout->addWidget(Secret);
    bayout2->addWidget(NewFile);
    page1->setLayout(bayout);
    page2->setLayout(bayout1);
    page3->setLayout(bayout2);
    Tab->addTab(page1,QIcon("/Icons/Storages.png"),"Storages");
    Tab->addTab(page2,QIcon("/Icons/etoile.png"),"Favourites");
    Tab->addTab(page3,QIcon("/Icons/recent.svg"),"New Files");
    Tab->setUsesScrollButtons(true);
    QVBoxLayout *mani =new QVBoxLayout;
    mani->addWidget(Tab);
    Menu->setLayout(mani);
    mani->deleteLater();
    Act = new Actions;
    //connect(home,SIGNAL(clicked()),this,SLOT(home_buuton_pressed()));
    connect(ActionRefresh, &QAction::triggered, this, &MenuP::refresh);
}
MenuP::~MenuP()
{


    delete Menu;
    delete ActionAnalyse;
    delete ActionRefresh;
    delete ActionSetting;
    delete home;
    delete MenuOption;
    delete label;
    delete page1;
    delete page2;
    delete page3;
    delete Tab;
    delete bayout;
    delete bayout1;
    delete bayout2;
    delete Bar;
}
void MenuP::refresh()
{
    Act->refresh();
}
