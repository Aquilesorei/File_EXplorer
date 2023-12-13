#include "Dialog.h"
#include "CentralWidget.h"
Dialog::Dialog()
{
    toolBar = new QToolBar;
    layout = new QVBoxLayout;
    p = new FenPrincipale;
    //toolBar = p->addToolBar("Fichiers");
    toolBar->setBaseSize(QSize(30,10));
    toolBar->addAction(p->ActionCut);
    toolBar->addAction(p->ActionCopy);
    toolBar->addAction(p->ActionPaste);
    toolBar->addAction(p->ActionRename);
    toolBar->addAction(p->ActionShare);
    toolBar->addAction(p->ActionDelete);
    toolBar->addSeparator();
    layout->addWidget(toolBar);
    open = new QMenu;
    Openwith = new QMenu;
    compress = new QMenu;
    details = new QMenu;
    openAs = new QMenu;
    layout->addWidget(open);
    layout->addWidget(Openwith);
    layout->addWidget(openAs);
    layout->addWidget(compress);
    layout->addWidget(details);
    this->setLayout(layout);
}

/*void enter(const QString &path)
{
    QDesktopServices::openUrl(QUrl(path));
}
*/
