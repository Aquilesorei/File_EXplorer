#include <QIcon>
#include <QDir>

#include "NavBar.h"

NavBar::NavBar()
    : goBack(new QToolButton),
      goUp(new QToolButton),
      refresh(new QToolButton),
      home(new QToolButton)
{
    this->setMovable(false);
    this->setContextMenuPolicy(Qt::PreventContextMenu);

    goBack->setIcon(QPixmap("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/go-previous.svg"));
    goUp->setIcon(QPixmap("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/go-up.svg"));
    refresh->setIcon(QPixmap("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/view-refresh.svg"));
    home->setIcon(QPixmap("C:/Users/ZONGO Achille/Documents/QtCreator/File_EXplorer/Icons/user-home.svg"));

    goBack->setEnabled(false);
    goUp->setEnabled(false);

    connect(goBack,&QToolButton::clicked,this,&NavBar::onGoBackClicked);
    connect(goUp,&QToolButton::clicked,this,&NavBar::onGoUpClicked);
    connect(refresh,&QToolButton::clicked,this,&NavBar::onRefreshClicked);
    connect(home,&QToolButton::clicked,this,&NavBar::onHomeClicked);

    this->addWidget(goBack);
    this->addWidget(goUp);
    this->addWidget(refresh);
    this->addWidget(home);
}

NavBar::~NavBar() {
    delete goBack;
    delete goUp;
    delete refresh;
    delete home;
}

void NavBar::setBrowserWidget(Achille *b) {
    bWidget = b;
    if (bWidget->fsCurrentPath()=="/") {
        goUp->setEnabled(false);
    } else {
        goUp->setEnabled(true);
    }
    if (b->history().isEmpty()) {
        goBack->setEnabled(false);
    } else {
        goBack->setEnabled(true);
    }
    connect(bWidget,SIGNAL(dirChanged(QString)),this,SLOT(onDirChanged(QString)));
    connect(bWidget,&Achille::historyChanged,this,&NavBar::onHistoryChanged);
}

void NavBar::onGoUpClicked() {
    if (bWidget==nullptr) {
        return;
    }
    QString currentPath = bWidget->fsCurrentPath();
    QDir dir(currentPath);
    dir.cdUp();
    QString newPath = dir.path();
    bWidget->loadDir(newPath);
}

void NavBar::onGoBackClicked() {
    QString path = bWidget->history().first();
    bWidget->loadDir(path);
}

void NavBar::onRefreshClicked() {
    bWidget->reload();
}

void NavBar::onHomeClicked() {
    bWidget->loadDir();
}

void NavBar::onDirChanged(QString path) {
    if (path=="/") {
        goUp->setEnabled(false);
    } else {
        goUp->setEnabled(true);
    }
}

void NavBar::onHistoryChanged() {
    if (bWidget->history().isEmpty()) {
        goBack->setEnabled(false);
    } else {
        goBack->setEnabled(true);
    }
}
