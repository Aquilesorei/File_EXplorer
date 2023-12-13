#include "toolbarfichiers.h"
toolbarfichier::toolbarfichier()
{
    board = QApplication::clipboard();
    tab= new tabWidget;

    this->setOrientation(Qt::Horizontal);
    ActionAll = new QAction;
    ActionNouveau = new QAction();
    ActionNouveau->setShortcuts(QKeySequence::New);
    ActionNouveau->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/New.svg"));
    ActionNouveau->setToolTip("New");
    this->addAction(ActionNouveau);
    ActionCopy =new QAction();
    ActionCut= new QAction();
    ActionPaste= new QAction();
    ActionRename= new QAction();
    ActionDelete= new QAction();
    ActionShare= new QAction();
    ActionSort= new QAction();
    Actionview= new QAction();
    ActionFind = new QAction();
    ActionCompress = new QAction();

    //setting icons and tooltips

    ActionAll->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/select-all.png"));
    ActionNouveau->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/New.svg"));
    ActionCopy->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Copy.svg"));
    ActionCopy->setToolTip("Copy");
    ActionCut->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Cut.svg"));
    ActionCut->setToolTip("Cut");
    ActionPaste->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Paste.svg"));
    ActionPaste->setToolTip("Paste");
    ActionRename->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Rename.png"));
    ActionRename->setToolTip("Rename");
    ActionDelete->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/delete.png"));
    ActionDelete->setToolTip("Delete");
    ActionShare->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Share.png"));
    ActionShare->setToolTip("Share");
    ActionSort->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Sort.svg"));
    ActionSort->setToolTip("Sort");
    Actionview->setIcon(QPixmap("/home/aquiles/Desktop/project/File_EXplorer/Icons/View.svg"));
    Actionview->setToolTip("View");
    ActionFind->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Find.svg"));
    ActionFind->setToolTip("Find");

    ActionCompress->setIcon(QIcon("/home/aquiles/Desktop/project/File_EXplorer/Icons/Compress.png"));
     ActionCompress->setToolTip("Compress files in to ZIP file");


     this->addAction(ActionCopy);
     this->addAction(ActionCut);
     this->addAction(ActionPaste);
     this->addAction(ActionRename);
     this->addAction(ActionShare);
     this->addAction(ActionDelete);
     this->addAction(ActionSort);
     this->addAction(Actionview);
     this->addAction(ActionCompress);
     this->addAction(ActionAll);
     //this->addAction(ActionFind);
     this->setFloatable(false);
     this->setMovable(false);

     //establishing connections !
     QObject::connect(ActionNouveau,&QAction::triggered,this,&toolbarfichier::addNew);
     QObject::connect(ActionCopy,&QAction::triggered,this,&toolbarfichier::_copy);
     QObject::connect(ActionCut,&QAction::triggered,this,&toolbarfichier::_cut);
     QObject::connect(ActionPaste,&QAction::triggered,this,&toolbarfichier::_paste);
     QObject::connect(ActionRename,&QAction::triggered,this,&toolbarfichier::_rename);
     QObject::connect(ActionDelete,&QAction::triggered,this,&toolbarfichier::_delete);
     QObject::connect(ActionSort,&QAction::triggered,this,&toolbarfichier::_sort);
}

void toolbarfichier::addNew()
{
    tab->addNewTab();
}

void toolbarfichier::configActions()
{

}

void toolbarfichier::_copy()
{
  // Act->copy();
   FileContextMenu me;
   me._copy();
}

void toolbarfichier::_cut()
{
   //Act->Cut();
    FileContextMenu me;
    me._cut();
}

void toolbarfichier::_paste()
{
    BackgroundContextMenu ba;
    ba.onpaste();

}

void toolbarfichier::_rename()
{
  FileContextMenu me;
  me._rename();
}

void toolbarfichier::_delete()
{
    FileContextMenu me;
    me._deleteFile();
}

void toolbarfichier::_sort()
{
    SortD d;;
    d.exec();
}
