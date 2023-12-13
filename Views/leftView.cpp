
#include "leftView.h"

#include "../components/tabwidget.h"

#include <QAction>
leftView::leftView(QWidget *parent):QWidget(parent)
{


       //When we create a new item, we specify the text for two columns:
       //Column 1 (0) contains the display text
       //Column 2 (1) contains the ID text
       //To avoid confusion, keep the ID text all-lowercase
        QVBoxLayout *layout = new QVBoxLayout;
       home = new QPushButton;
       home->setText("Home");
       home->setFont(QFont("Calibri", 15));
       connect(home,&QPushButton::clicked,this,&leftView::_home);
       layout->addWidget(home);
       home->setIcon(QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/MainStorage.png"));
       Desktop = new QPushButton;
       Desktop->setText("Desktop");
       connect(Desktop,&QPushButton::clicked,this,&leftView::_Desktop);
       Desktop->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/desktop.png"));
       Desktop->setFont(QFont("Calibri", 15));
      layout->addWidget(Desktop);

       docs = new QPushButton;
       docs->setText( "Documents");
       docs->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Documents.png"));
       connect(docs,&QPushButton::clicked,this,&leftView::_docs);
       docs->setFont(QFont("Calibri", 15));
       layout->addWidget(docs);
       pics = new QPushButton;
       pics->setText( "Pictures");
       layout->addWidget(pics);
       connect(pics,&QPushButton::clicked,this,&leftView::_pics);
       pics->setFont(QFont("Calibri", 15));
       pics->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Image.png"));

       downloads = new QPushButton;
       downloads->setText( "Downloads");
       connect(downloads,&QPushButton::clicked,this,&leftView::_downloads);
       layout->addWidget(downloads);
       downloads->setFont(QFont("Calibri", 15));
       downloads->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Download.png"));

       music = new QPushButton;
       music->setText( "Music");
       layout->addWidget(music);
       music->setFont(QFont("Calibri", 15));
       connect(music,&QPushButton::clicked,this,&leftView::_music);
       music->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Audio.png"));

       videos = new QPushButton;
       videos->setText( "Videos");
       layout->addWidget(videos);
       connect(videos,&QPushButton::clicked,this,&leftView::_videos);
       videos->setFont(QFont("Calibri", 15));
       videos->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Videos.png"));


       Apps = new QPushButton;
       Apps->setText( "Softwares");
       Apps->setFont(QFont("Calibri", 15));
       Apps->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Softwares.jpg"));

       NewFile = new QPushButton;
       NewFile->setText( "NewFile");
       NewFile->setFont(QFont("Calibri", 15));
       NewFile->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/recent.svg"));

       Cloud= new QPushButton;
       Cloud->setText( "Cloud");
       Cloud->setFont(QFont("Calibri", 15));
       Cloud->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/recent.svg"));//here

       Acess= new QPushButton;
       Acess->setText( "FTP");
       Acess->setFont(QFont("Calibri", 15));
       Acess->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Access.png"));

       Encrypted = new QPushButton;
       Encrypted->setText( "Encrypted");
       Encrypted->setText("encrypted");
       Encrypted->setFont(QFont("Calibri", 15));
       Encrypted->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Encrypted.png"));

       Favourite= new QPushButton;
       Favourite->setText( "Favourite");
       Favourite->setFont(QFont("Calibri", 15));
       Favourite->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Favourite.png"));

      compressed= new QPushButton;
      compressed->setText( "Compressed");
      compressed->setFont(QFont("Calibri", 15));
      compressed->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Encrypted.png"));

       Recycle= new QPushButton;
       Recycle->setText( "Recycle bin");
       Recycle->setFont(QFont("Calibri", 15));
       Recycle->setIcon( QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/Corbeille.png"));


      /* trash = new QPushButton;
       trash->setText( "Trash");
       trash->setText("trash");
       trash->setIcon( QPixmap(":/icons/user-trash.svg"));*/
       layout->setContentsMargins(0,0,0,0);
        setLayout(layout);

}

leftView::~leftView()
{

}


void leftView::ecrire()
{
    qDebug()<<"received";
}

void *leftView::_home()
{
    tabWidget::currentWidget()->loadDir(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
    return 0;
}

void *leftView::_docs()
{
    tabWidget::currentWidget()->loadDir(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
     return 0;
}

void *leftView::_pics()
{
   tabWidget::currentWidget()->loadDir(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    return 0;
}

void *leftView::_downloads()
{
    tabWidget::currentWidget()->loadDir(QStandardPaths::writableLocation(QStandardPaths::DownloadLocation));
     return 0;
}

void *leftView::_music()
{
    tabWidget::currentWidget()->loadDir(QStandardPaths::writableLocation(QStandardPaths::MusicLocation));
     return 0;
}

void *leftView::_videos()
{
    tabWidget::currentWidget()->loadDir(QStandardPaths::writableLocation(QStandardPaths::MoviesLocation));
     return 0;
}

void *leftView::_Desktop()
{
  tabWidget::currentWidget()->loadDir(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
   return 0;
}
/*void leftView::mousePressEvent(QMouseEvent *event)
{

        if(event->button()==Qt::RightButton)
        {



             if(!indexAt(event->pos()).isValid()){return;}
             else{
             QPushButton *item = this->itemAt(event->pos());
                    QString er = item->text(0);
                    if(item!= nullptr){


                    }

        }
         QTreeWidget::mousePressEvent(event);


        }
}
*/
