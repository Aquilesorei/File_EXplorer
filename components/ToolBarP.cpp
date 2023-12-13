#include "ToolBarP.h"
#include "Actions.h"
#include "tabwidget.h"
ToolBarP::ToolBarP()
{
    Act = new Actions;
    New = new QToolButton;

    New->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/New.svg"));
    New->setToolTip("New");
    sort= new QToolButton;
    view= new QToolButton;

    ActionCopy =new QAction();
    ActionCut= new QAction();
    ActionPaste= new QAction();
    ActionRename= new QAction();
    ActionDelete= new QAction();
    ActionShare= new QAction();
    SelectA = new QAction;
    ActionFind = new QAction();
    ActionCompress = new QAction();



    //les
    SelectA->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/select-all.png"));
     SelectA->setToolTip("Select All");
    New->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/New.svg"));
    ActionCopy->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Copy.svg"));
    ActionCopy->setToolTip("Copy");
    ActionCut->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Cut.svg"));
    ActionCut->setToolTip("Cut");
    ActionPaste->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Paste.svg"));
    ActionPaste->setToolTip("Paste");
    ActionRename->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Rename.png"));
    ActionRename->setToolTip("Rename");
    ActionDelete->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/delete.png"));
    ActionDelete->setToolTip("Delete");
    ActionShare->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Share.png"));
    ActionShare->setToolTip("Share");
    sort->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/sort.svg"));
    sort->setToolTip("Sort");
    view->setIcon(QPixmap("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/View.svg"));
    view->setToolTip("View");
    ActionFind->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Find.svg"));
    ActionFind->setToolTip("Find");

    ActionCompress->setIcon(QIcon("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/Compress.png"));

    ActionCompress->setToolTip("Compress files in to ZIP file");

    this->addAction(ActionCopy);
    this->addAction(ActionCut);
    this->addAction(ActionPaste);
    this->addAction(ActionRename);
    this->addAction(ActionShare);
    this->addAction(ActionDelete);
    this->addWidget(sort);
    this->addWidget(view);
    this->addAction(ActionCompress);
    this->setFloatable(false);
    this->setMovable(false);
    connect(ActionCopy, &QAction::triggered, this, &ToolBarP::_copy);
    connect(ActionCut, &QAction::triggered, this, &ToolBarP::_cut);
    connect(ActionPaste, &QAction::triggered, this, &ToolBarP::_paste);
    connect(ActionRename, &QAction::triggered, this, &ToolBarP::_rename);
    connect(ActionDelete, &QAction::triggered, this, &ToolBarP::_delete);
    connect(SelectA, &QAction::triggered, this, &ToolBarP::SelectAll);

}
ToolBarP::~ToolBarP()
{
    delete Act;
   delete New ;
   delete sort;
   delete view;
   delete ActionCopy ;
   delete ActionCut;
   delete ActionPaste;
   delete ActionRename;
   delete ActionDelete;
   delete ActionShare;
   delete ActionCompress;
   delete view;
   delete New;
   delete sort;
   delete ActionFind;


}
void ToolBarP::_copy()
{
    Act->copy();
}
void ToolBarP::_cut()
{
    Act->Cut();
}
void ToolBarP::_paste()
{
    Act->paste();
}
void ToolBarP::_rename()
{
    Act->rename();
}
void ToolBarP::_delete()
{
    Act->deletef();
}
void ToolBarP::SelectAll()
{
   tabWidget::currentWidget()->selectAll();

}
