#include "Welcome.h"
Welcome::Welcome(QWidget *parent):QWidget(parent)
{

    layout = new QGridLayout(this);
    BoutonMAinStorage = new QPushButton("Local Disk");

    BoutonMAinStorage->setFont(QFont("Calibri", 15));

    //this->setMaximumSize();
    Desktop = new QPushButton("Desktop");
    Desktop->setFont(QFont("Calibri", 15));
    Downloads = new QPushButton("Downloads");
    Downloads->setFont(QFont("Calibri", 15));
    Download=new QPushButton("Downloads");
    Download->setFont(QFont("Calibri", 20));
    images = new QPushButton("Pictures");
    images->setFont(QFont("Calibri", 15));
    Audio = new QPushButton("Music");
    Audio->setFont(QFont("Calibri", 15));
    Videos = new QPushButton("Videos");
    Videos->setFont(QFont("Calibri", 15));
    Documents  = new QPushButton("Documents");
    Documents->setFont(QFont("Calibri", 15));
    Apps  = new QPushButton("Softwares");
    Apps->setFont(QFont("Calibri", 15));
    NewFile=new QPushButton;

    NewFiles  = new QPushButton("New Files");
    NewFiles->setFont(QFont("Calibri", 15));
    Cloud  = new QPushButton;
    Access  = new QPushButton("FTP");
    Access->setFont(QFont("Calibri", 15));
    Compressed = new QPushButton("Compressed");
    Compressed->setFont(QFont("Calibri", 15));
    Encrypted  = new QPushButton("Encrypted");
    Encrypted->setFont(QFont("Calibri", 15));
    Recycle  = new QPushButton("Recycle Bin");
    Recycle->setFont(QFont("Calibri", 15));
    Secret =new QPushButton("Hidden Cabinet");
    Secret->setFont(QFont("Calibri", 20));
    Favourite  = new QPushButton("Favourites");
    Favourite->setFont(QFont("Calibri", 15));

    Recycles = new QPushButton("Trash");
    home = new QPushButton("Home");
    home->setToolTip("Move to the home directoy");
    home->setFont(QFont("Calibri", 20));
    Recycles->setFont(QFont("Calibri", 20));
    Recycles->setIcon(QIcon(QDir::currentPath() +"/Icons/recycles.png"));
    BoutonMAinStorage->setIconSize(QSize(125,75));
    Secret->setIcon(QIcon(QDir::currentPath() +"/Icons/Secure.png"));
    Secret->setIconSize(QSize(22,22));
    BoutonMAinStorage->setIcon(QIcon(QDir::currentPath() +"/Icons/MainStorage.png"));
    BoutonMAinStorage->setIconSize(QSize(250,100));
    Downloads->setIcon(QIcon(QDir::currentPath() +"/Icons/Download.png"));
    Downloads->setIconSize(QSize(250,100));
    Download->setIcon(QIcon(QDir::currentPath() +"/Icons/Download.png"));
    images->setIcon(QIcon(QDir::currentPath() +"/Icons/Image.png"));
    images->setIconSize(QSize(250,100));
    Audio->setIcon(QIcon(QDir::currentPath() +"/Icons/Audio.png"));
    Audio->setIconSize(QSize(250,100));
    Videos->setIcon(QIcon(QDir::currentPath() +"/Icons/Videos.png"));
    Videos->setIconSize(QSize(250,100));
    Documents->setIcon(QIcon(QDir::currentPath() +"/Icons/Documents.png"));
    Documents->setIconSize(QSize(250,100));
    Apps->setIcon(QIcon(QDir::currentPath() +"/Icons/Softwares.jpg"));
    Apps->setIconSize(QSize(250,100));
    NewFiles->setIcon(QIcon(QDir::currentPath() +"/Icons/recent.svg"));
    NewFiles->setIconSize(QSize(250,100));
    NewFile->setIcon(QIcon(QDir::currentPath() +"/Icons/recent.svg"));
    Access->setIcon(QIcon(QDir::currentPath() +"/Icons/Access.png"));
    Access->setIconSize(QSize(250,100));
    Compressed->setIcon(QIcon(QDir::currentPath() +"/Icons/Compressed.png"));
    Compressed->setIconSize(QSize(250,100));
    Encrypted->setIcon(QIcon(QDir::currentPath() +"/Icons/Encrypted.png"));
    Encrypted->setIconSize(QSize(250,100));
    Recycle->setIcon(QIcon(QDir::currentPath() +"/Icons/Corbeille.png"));//l'icone change souvent
    Recycle->setIconSize(QSize(250,100));
    Favourite->setIcon(QIcon(QDir::currentPath() +"/Icons/Favourite.png"));
    Favourite->setIconSize(QSize(250,100));
    Desktop->setIcon(QIcon(QDir::currentPath() +"/Icons/desktop.png"));
    Desktop->setIconSize(QSize(250,100));

    //centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
   // window->setContentsMargins(0,0,0,0);
    layout->addWidget(BoutonMAinStorage, 0, 0);
    layout->addWidget(Downloads, 0, 1);
    layout->addWidget(Desktop, 0, 2);
    layout->addWidget(images, 0, 3);
    layout->addWidget(Audio, 0, 4);
    layout->addWidget(Videos, 1, 0);
    layout->addWidget(Documents, 1, 1);
    layout->addWidget(Apps, 1, 2);
    layout->addWidget(NewFiles, 1, 3);
    layout->addWidget(Access, 1, 4);
    layout->addWidget(Compressed, 2, 0);
    layout->addWidget(Encrypted, 2, 1);
    layout->addWidget(Recycle, 2, 2);
    layout->addWidget(Favourite, 2, 3);

    setLayout(layout);
    this->setAutoFillBackground(true);

}

